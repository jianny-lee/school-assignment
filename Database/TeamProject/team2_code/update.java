package team2;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 * class that update some data for request of administrator
 * @author HyoJin Lee
 *
 */
public class update {
   static String name = null, menu = null, city = null, attraction = null, colNames[] = null;;
   static int price = 0;
   static String grades_new = null, grades_pre = null;
   static String tableName = null;

   /**
    * constructor
    * @param city
    * @param attraction
    */
   public update(String city, String attraction) {
      tableName = "DBCOURSE_Attraction";
      this.city = city;
      this.attraction = attraction;
   }

   /**
    * constructor
    * @param name
    * @param colNames
    * @param grades
    */
   public update(String name, String[] colNames, String grades) {
      this.name = name;
      this.colNames = colNames;
      this.grades_new = grades;
      tableName = "DBCOURSE_Grades";
   }

   /**
    * constructor
    * @param tableName
    * @param menu
    * @param price
    */
   public update(String tableName, String menu, int price) {
      this.tableName = tableName;
      this.menu = menu;
      this.price = price;
   }

   /**
    * update the price of menu
    */
   public void RestaurantUpdate() {
      PreparedStatement pstmt=null;
      try {
         String sql = "update " + tableName + " set price=? where menu=?";
         pstmt = Open.myConn.prepareStatement(sql);// create a object of prepareStatement that have '?' which can
                                                         // be changed with each input of user
         pstmt.setInt(1, price); //put the 'price' to first question mark
         pstmt.setString(2, menu); //put the 'menu' to second question mark
         pstmt.executeUpdate(); //plug in above parameters and execute update
      } catch (Exception e) {
         e.printStackTrace();
         System.out.println(e.getMessage());
      }finally {
         if (pstmt != null) {
            try {
               pstmt.close();
            } catch (SQLException e) {
               // TODO Auto-generated catch block
               e.printStackTrace();
               System.out.println(e.getMessage());
            }
         }
         
      }
   }

   /**
    * update the attraction of city
    */
   public void AttractionUpdate() {
      PreparedStatement pstmt=null;
      try {
         String sql = "update " + tableName + " set attraction=? where city=?";
         pstmt = Open.myConn.prepareStatement(sql);// create a object of prepareStatement that have '?' which can
                                                         // be changed with each input of user
         pstmt.setString(1, attraction); //put the 'attraction' to first question mark
         pstmt.setString(2, city); //put the 'city' to second question mark
         pstmt.executeUpdate();//plug in above parameters and execute update
      } catch (SQLException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
         System.out.println(e.getMessage());
      }finally {
         if (pstmt != null) {
            try {
               pstmt.close();
            } catch (SQLException e) {
               // TODO Auto-generated catch block
               e.printStackTrace();
               System.out.println(e.getMessage());
            }
         }
         
      }
   }

   /**
    * update the grades of each restaurant using transaction
    * @return table
    * @throws SQLException
    */
   @SuppressWarnings("finally")
   public JTable GradesUpdate() throws SQLException {
      JTable table = new JTable(); // generate new table object
      DefaultTableModel model = new DefaultTableModel(colNames, 0); //generate new model object
      PreparedStatement pstmt1 = null;
      PreparedStatement pstmt2 = null;
      PreparedStatement pstmt3 = null;
      ResultSet myRs = null;
      Statement st = null;
      String sql1 = "select grades from " + tableName + " where name=?";
      String sql2 = "update " + tableName + " set grades=? where name=?";
      String sql3 = "update " + tableName + " set grades=? where name=?";
      String sql4 = "select * from " + tableName;
      try {
         Open.myConn.setAutoCommit(false); //turn off automatic commit on a connection
         pstmt1 = Open.myConn.prepareStatement(sql1);// create a object of prepareStatement that have '?' which can
                                          // be changed with each input of user
         pstmt2 = Open.myConn.prepareStatement(sql2);// create a object of prepareStatement that have '?' which can
                                          // be changed with each input of user
         pstmt3 = Open.myConn.prepareStatement(sql3);// create a object of prepareStatement that have '?' which can
                                          // be changed with each input of user
         st = Open.myConn.createStatement();// create a object of Statement
         pstmt1.setString(1, name);//put the 'name' to pstmt1's first question mark
         myRs = pstmt1.executeQuery();//plug in above parameters and execute
         while (myRs.next()) { //approach every record in the table
            grades_pre = myRs.getString(colNames[1]); // get the grades value
         }
         float grades = (Float.parseFloat(grades_pre) + Float.parseFloat(grades_new)); //get the sum of previous grades, new grades and save to grades
         pstmt2.setFloat(1, grades);//put the 'grades' to pstmt2's first question mark
         pstmt2.setString(2, name);//put the 'name' to pstmt2's second question mark
         pstmt2.executeUpdate();//plug in above parameters and execute update

         pstmt3.setFloat(1, grades / 2);//put the 'grades/2'(average) to pstmt2's first question mark
         pstmt3.setString(2, name);//put the 'name' to pstmt2's second question mark
         pstmt3.executeUpdate();//plug in above parameters and execute update

         myRs = st.executeQuery(sql4); //execute query and fetch
         while (myRs.next()) { //approach every record in the table
            model.addRow(new Object[] { myRs.getString(colNames[0]), myRs.getString(colNames[1]) }); // get all tuples and save to model
         }
         table = new JTable(model);// table becomes a JTable objects with contents of the model
         Open.myConn.commit(); //transactions committed
      } catch (SQLException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
         System.out.println(e.getMessage());
         if (Open.myConn != null) {
               try {
                   System.err.print("Transaction is being rolled back"); //show the error message that transactions failed
                   Open.myConn.rollback(); //transactions rolled back
               } catch(SQLException ex) {
                  ex.printStackTrace();
                System.out.println(ex.getMessage());
               }
           }

      } finally {
         if (pstmt1 != null) {
            pstmt1.close();
         }
         if (pstmt2 != null) {
            pstmt2.close();
         }
         if (pstmt3 != null) {
            pstmt3.close();
         }
         if (st != null) {
            st.close();
         }
         Open.myConn.setAutoCommit(true);//turn on automatic commit
         return table; //return value is table
      }
   }
}
