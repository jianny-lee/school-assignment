package team2;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

/**
 * class that retrieve the result for request of administrator
 * @author DoKyung Lee
 *
 */
public class retrieve_adm {
   
   static String colNames[] = null;
   static String tableName = null;
   static String index = null;
   DefaultTableModel model = null;

   /**
    * constructor that has String and String array parameters
    * @param tableName
    * @param colNames
    */
   public retrieve_adm(String tableName, String[] colNames) {
      this.tableName = tableName;
      this.colNames = colNames;
   }

   /**
    * constructor that has 2 Strings and String array parameters
    * @param tableName
    * @param index
    * @param colNames
    */
   public retrieve_adm(String tableName, String index, String[] colNames) {
      this.tableName = tableName;
      this.index = index;
      this.colNames = colNames;

   }
   
   /**
    * method for administrator that returns a table that is a result of query 
    * @return
    * @throws SQLException 
    */
   public JTable show() throws SQLException {
      JTable table = new JTable(); // 'table' is a object of JTable 
      model = new DefaultTableModel(colNames, 0); // Constructs a DefaultTableModel with columns that are elements in columnNames and the number of rows is '0'
      Statement st = null;
      
      try {
         int num = 0; // the number of columns that have to be shown 
         st = Open.myConn.createStatement(); //create a object of Statement
         String sql = null;
         ResultSet myRs = null; //create a object of ResultSet
         
         // condition statement about 'tableName' shows the whole table
         if (tableName == "DBCOURSE_Restaurants") {
            num = 4; // the number of columns that have to be shown is 4
            sql = "select * from " + tableName + " use index (i_name)"; // use index in query 
            myRs = st.executeQuery(sql); // execute query that is same as 'sql' and 'myRs' becomes that result
         } else if (tableName == "DBCOURSE_Attraction") { // second option and comments are same with 'if' part
            num = 2;
            sql = "select * from " + tableName + " use index (i_city)";
            myRs = st.executeQuery(sql);
         } else if (tableName == "DBCOURSE_FoodCategory") { // third option and comments are same with 'if' part
            num = 2;
            sql = "select * from " + tableName + " use index (i_category)";
            myRs = st.executeQuery(sql);
         } else if (tableName == "DBCOURSE_Grades") { // fourth option and comments are same with 'if' part
            num = 2;
            sql = "select * from " + tableName;
            myRs = st.executeQuery(sql);
         } else { // fifth option and comments are same with 'if' part
            num = 5;
            sql = "select * from " + tableName + " use index (" + index + ")";
            myRs = st.executeQuery(sql);
         }

         while (myRs.next()) { // read ResultSet 'myRs' line by line
            switch (num) { // 3 cases are divided depending on value of 'num'
            case 4: // first case - the result data of query occupies domain of column in the model
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]), myRs.getString(colNames[3]) }); // domain of 'colNames' becomes 'Object' array and also rows of 'tableName'
               break;
            case 2: // second case
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]) });
               break;
            case 5: // third case
               model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]),
                     myRs.getString(colNames[2]), myRs.getString(colNames[3]), myRs.getString(colNames[4]) });
               break;
            }
         }
         table = new JTable(model); // table becomes a JTable objects with contents of the model

      } catch (SQLException e) {  //catch errors
         e.printStackTrace();
         System.out.println(e.getMessage());
      } finally {
            if (st != null) {
                st.close(); // close the statement
             }
            return table;  //return table of the result 
          }
   }
}
