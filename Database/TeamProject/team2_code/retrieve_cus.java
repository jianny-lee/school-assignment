package team2;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 * class that retrieve the result for request of customer
 * 
 * @author NaGyeong Yeo, Dokyung Lee, HyoJin Lee
 *
 */
public class retrieve_cus {
   static String colNames[] = null;
   static String tableName = null, type = null, name = null;
   static int priceMin, priceMax;

   /**
    * constructor to retrieve data by using type
    * 
    * @param tableName
    * @param type
    * @param colNames
    */
   public retrieve_cus(String tableName, String type, String[] colNames) {
      this.tableName = tableName;
      this.type = type;
      this.colNames = colNames;
   }

   /**
    * constructor that has String, String array, and integer parameters
    * 
    * @param name
    * @param colNames
    * @param a
    */
   public retrieve_cus(String name, String[] colNames, int a) {
      this.name = name;
      this.colNames = colNames;
   }

   /**
    * constructor to retrieve data by using price range
    * 
    * @param tableName
    * @param priceMin
    * @param priceMax
    * @param colNames
    */
   public retrieve_cus(String tableName, int priceMin, int priceMax, String[] colNames) {
      this.tableName = tableName;
      this.priceMin = priceMin;
      this.priceMax = priceMax;
      this.colNames = colNames;
   }

   /**
    * retrieve restaurant and menu information by using type / retrieve restaurant
    * and menu information by using price range
    * 
    * @return
    */
   public JTable show() {
      JTable table = new JTable();
      DefaultTableModel model = new DefaultTableModel(colNames, 0);
      PreparedStatement pstmt = null;
      try {
         int num = 0;
         String sql;
         if (tableName == "DBCOURSE_type") { // retrieve restaurant and menu information by using type
            num = 3; // the number of columns is 3
            sql = "select name, menu, price from " + tableName + " where type=?"; // make query
            // create a object of prepareStatement that have '?'
            // which can be changed with each input of user
            pstmt = Open.myConn.prepareStatement(sql);
            /* input data into parameter */
            pstmt.setString(1, type);
         } else if (tableName == "DBCOURSE_menu, DBCOURSE_foodCategory") { // retrieve restaurant and menu
            // information by using price range
            num = 6; // the number of columns is 6
            // make query
            sql = "select name, menu, price, calories, DBCOURSE_menu.category, ingredients from " + tableName
                  + " where DBCOURSE_menu.category=DBCOURSE_foodCategory.category and price >= ? and price <=?"; 
            pstmt = Open.myConn.prepareStatement(sql); // create a object of prepareStatement that have '?'
            // which can be changed with each input of user
            /* input data into parameters */
            pstmt.setInt(1, priceMin);
            pstmt.setInt(2, priceMax);
         }

         ResultSet myRs = pstmt.executeQuery(); // execute query

         /* make table according to the number of columns */
         while (myRs.next()) {
            switch (num) {
            case 2:
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]) });
               break;
            case 3:
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]) });
               break;
            case 4:
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]), myRs.getString(colNames[3]) });
               break;
            case 5:
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]), myRs.getString(colNames[3]), myRs.getString(colNames[4]) });
               break;
            case 6:
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]), myRs.getString(colNames[3]), myRs.getString(colNames[4]),
                     myRs.getString(colNames[5]) });
               break;
            }
         }
         table = new JTable(model); // table becomes a JTable objects with contents of the model

      } catch (SQLException e) { // catch errors
         e.printStackTrace();
         System.out.println(e.getMessage());
      } finally {
         if (pstmt != null) {
            try {
               pstmt.close();
            } catch (SQLException e) {
               e.printStackTrace();
               System.out.println(e.getMessage());
            }
         }
      }

      return table; // return table of the result
   }

   /**
    * method for customer that returns a table that is a result of query
    * 
    * @return JTable = output of the query
    */
   public JTable show4() {

      JTable table = new JTable(); // 'table' is a object of JTable
      DefaultTableModel model = new DefaultTableModel(colNames, 0); // Constructs a DefaultTableModel with columns
      // that are elements in columnNames and the
      // number of rows is '0'
      PreparedStatement pstmt1 = null;

      try {
         // nested query is used in this query
         String sql1 = "select city, attraction from DBCOURSE_Attraction use index (i_city) where city in (select city from DBCOURSE_Restaurants use index (i_name) where name=?)";

         // create a object of prepareStatement that have '?' which can
         // be changed with each input of user
         pstmt1 = Open.myConn.prepareStatement(sql1); 
         pstmt1.setString(1, name); // first '?' is the same with value of 'name'

         ResultSet myRs = pstmt1.executeQuery(); // execute query in 'pstmt1' and 'myRs' becomes that result

         while (myRs.next()) { // read ResultSet 'myRs' line by line
            // domain of 'colNames' becomes 'Object' array and also rows of 'tableName'
            model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]) });
         }
         table = new JTable(model); // table becomes a JTable objects with contents of the model

      } catch (SQLException e) { // catch errors
         e.printStackTrace();
         System.out.println(e.getMessage());
      } finally {
         if (pstmt1 != null) {
            try {
               pstmt1.close();
            } catch (SQLException e) {
               e.printStackTrace();
               System.out.println(e.getMessage());
            }
         }
      }

      return table; // return table of the result
   }
}
