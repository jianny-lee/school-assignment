package team2;

import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * class that insert some data of request for administrator
 * 
 * @author HyoJin Lee, NaGyeong Yeo
 *
 */
public class insert {
   static String tableName = null;
   static String name = null, menu = null, calories = null, category = null, ingredients = null;
   static int price = 0;

   /**
    * constructor to insert category
    * 
    * @param category
    * @param ingredients
    */
   public insert(String category, String ingredients) {
      tableName = "DBCOURSE_FoodCategory";
      this.category = category;
      this.ingredients = ingredients;
   }

   /**
    * constructor to insert menu
    * 
    * @param tableName
    * @param name
    * @param menu
    * @param price
    * @param calories
    * @param category
    */
   public insert(String tableName, String name, String menu, int price, String calories, String category) {
      this.tableName = tableName;
      this.name = name;
      this.menu = menu;
      this.price = price;
      this.calories = calories;
      this.category = category;
   }

   /**
    * insert new category(+ingredients) into FoodCategory table
    * 
    * @param category
    * @param ingredients
    */
   public void CategoryInsert() {
      PreparedStatement pstmt = null;
      try {
         String sql = "insert into " + tableName + " values (?,?)"; // make query
         // create a object of prepareStatement that have '?' which can
         // be changed with each input of user
         pstmt = Open.myConn.prepareStatement(sql); 
         /* input data into parameters */
         pstmt.setString(1, category);
         pstmt.setString(2, ingredients);
         pstmt.executeUpdate(); // execute query
         System.out.println(tableName + " 테이블에 새로운 레코드를 추가했습니다.");
      } catch (SQLException e) {
         e.printStackTrace();
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
   }

   /**
    * insert new menu(+price, etc) into specific Restaurant table
    * 
    * @param tableName
    * @param name
    * @param menu
    * @param price
    * @param calories
    * @param category
    */
   public void RestaurantInsert() {
      PreparedStatement pstmt = null;
      try {
         String sql = "insert into " + tableName + " values (?,?,?,?,?)"; // make query
         // create a object of prepareStatement that have '?' which can be changed with
         // each input of user
         pstmt = Open.myConn.prepareStatement(sql);
         /* input data into parameters */
         pstmt.setString(1, name);
         pstmt.setString(2, menu);
         pstmt.setInt(3, price);
         pstmt.setString(4, calories);
         pstmt.setString(5, category);
         pstmt.executeUpdate(); // execute query
         System.out.println(tableName + " 테이블에 새로운 레코드를 추가했습니다.");

      } catch (Exception e) {
         e.printStackTrace();
         System.out.println(e.getMessage());
         System.out.println("레코드 추가 실패");
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
   }

}
