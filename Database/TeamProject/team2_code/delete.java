package team2;

import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * class that delete some data for request of administrator
 * @author HyoJin Lee
 *
 */
public class delete {
   
   static String menu = null;
   static int price_min = 0, price_max = 0, calory_min = 0, calory_max = 0;
   static String tableName = null;

   /**
    * constructor
    * @param tableName
    * @param menu
    */
   public delete(String tableName, String menu) {
      this.tableName = tableName;
      this.menu = menu;
   }

   /**
    * constructor
    * @param tableName
    * @param min
    * @param max
    */
   public delete(String tableName, int min, int max) {
      this.tableName = tableName;

      this.price_min = min;
      this.price_max = max;

      this.calory_min = min;
      this.calory_max = max;
   }

   /**
    * delete the menu
    */
   public void Restaurantdelete() {
      PreparedStatement pstmt=null;
      try {
         String sql = "delete from " + tableName + " where menu=?";
         //create a object of prepareStatement that have '?' which can
         // be changed with each input of user
         pstmt = Open.myConn.prepareStatement(sql);
         pstmt.setString(1, menu);//put the 'menu' to first question mark
         pstmt.executeUpdate();//plug in above parameters and execute update
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
    *  delete tuples in the restaurant table that included in the price range
    */
   public void Pricedelete() {
      PreparedStatement pstmt=null;
      try {
         String sql = "delete from " + tableName + " where price>=? and price<=?";
         //create a object of prepareStatement that have '?' which can
         // be changed with each input of user
         pstmt = Open.myConn.prepareStatement(sql);
         pstmt.setInt(1, price_min); //put the 'price_min' to first question mark
         pstmt.setInt(2, price_max);//put the 'price_max' to second question mark
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
    * delete tuples in the restaurant table that included in the calories range
    */
   public void Calorydelete() {
      PreparedStatement pstmt=null;
      try {
         String sql = "delete from " + tableName + " where calories>? and calories<?";
         //create a object of prepareStatement that have '?' which can
         // be changed with each input of user
         pstmt = Open.myConn.prepareStatement(sql);
         pstmt.setInt(1, calory_min); //put the 'calory_min' to first question mark
         pstmt.setInt(2, calory_max);//put the 'calory_max' to second question mark
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
}
