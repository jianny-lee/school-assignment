package team2;

import java.awt.*;
import java.awt.event.*;
import java.sql.SQLException;
import java.util.InputMismatchException;

import javax.swing.*;

/**
 * 
 * class that is a window for administrator
 * @author YoungEun Lee, DoKyung Lee, HyoJin Lee, NaGyeong Yeo
 *
 */
public class Adm {
   static String tableName, index;
   private JFrame frmAdm;
   private JTextField Insert_Rest_Menu_textField;
   private JTextField Insert_Rest_Price_textField_1;
   private JTextField Insert_Rest_Calo_textField_1;
   private JTextField Insert_Rest_Cate_textField_1;
   private JTextField delete_Menu_text;
   private JTextField delete_PriceRange1_textField_1;
   private JTextField delete_PriceRange2_textField_2;
   private JTextField delete_CaloriesRange1_textField_3;
   private JTextField delete_CaloriesRange2_textField_4;
   private JTextField update_Attraction_textField_15;
   private JTextField update_Rest_Menu_textField_1;
   private JTextField update_Rest_Price_textField_1;
   private JTextField Insert_FoodCate_Cate_textField_1;
   private JTextField Insert_FoodCate_Ingre_textField_1;

   /**
    * open the Adm window.
    */
   public static void AdmScreen() {
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            try {
               Adm window = new Adm();
               window.frmAdm.setVisible(true);
            } catch (Exception e) {
               e.printStackTrace();
            }
         }
      });
   }

   /**
    * initialize the application.
    */
   public Adm() {
      initialize();
   }

   /**
    * Initialize the contents of the frame.
    */
   private void initialize() {
      frmAdm = new JFrame(); // create frame 'frmCus' of new JFrame.
      frmAdm.setTitle("Administrator Service");
      frmAdm.setBounds(0, 0, 1027, 594);
      frmAdm.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      frmAdm.getContentPane().setLayout(null);
      frmAdm.setLocationRelativeTo(null);

      // create TabbedPane 'tabbedPane' of new TabbedPane at gui top.
      JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
      tabbedPane.setBackground(Color.WHITE);
      tabbedPane.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      tabbedPane.setBounds(0, 0, 1005, 542);
      frmAdm.getContentPane().add(tabbedPane);

      // create Panel 'Retrieve_Adm' of new JPanel.
      JPanel Retrieve_Adm = new JPanel();
      Retrieve_Adm.setBackground(Color.WHITE);
      // add tab about Retrieve(Administrator) Administrator mode at 'tabbedPane'.
      tabbedPane.addTab("Retrieve(Administrator)", null, Retrieve_Adm, null);
      Retrieve_Adm.setLayout(null);

      JLabel label_25 = new JLabel("< Restaurants >");
      label_25.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 18));
      label_25.setBounds(30, 13, 157, 21);
      Retrieve_Adm.add(label_25);

      // create the button 'Retrieve_Rest_button' of new JButton.
      JButton Retrieve_Rest_button = new JButton("SHOW");
      // add the action for button 'Retrieve_Rest_button'.
      Retrieve_Rest_button.addActionListener(new ActionListener() {
         // show the restaurants information at Retrieve Panel when Administrator mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName of "DBCOURSE_Restaurants"
            tableName = "DBCOURSE_Restaurants";
            // in this button, columns in colNames should be selected
            String colNames[] = { "name", "city", "address", "type" };
            // create a object of class named 'retrieve_adm'
            retrieve_adm readm = new retrieve_adm(tableName, colNames);
            // execute 'show' method in 'retrieve_adm' and it becomes a value of 'table'
            JTable table;
            try {
               table = readm.show(); // create a scrollpane named 'Ret_rest_result' including data of 'table'
               JScrollPane Ret_rest_result = new JScrollPane(table);
               Ret_rest_result.setBounds(17, 45, 551, 150);
               // panel named 'Retrieve_Adm' contains 'Ret_rest_result'
               Retrieve_Adm.add(Ret_rest_result);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }
         }
      });
      Retrieve_Rest_button.setForeground(SystemColor.textHighlight);
      Retrieve_Rest_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Retrieve_Rest_button.setBounds(467, 9, 101, 29);
      Retrieve_Adm.add(Retrieve_Rest_button);

      JScrollPane scrollPane = new JScrollPane();
      scrollPane.setBounds(16, 45, 552, 150);
      Retrieve_Adm.add(scrollPane);

      JLabel label_26 = new JLabel("< Attraction >");
      label_26.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 18));
      label_26.setBounds(645, 13, 166, 21);
      Retrieve_Adm.add(label_26);

      // create the button 'Retrieve_Attrac_button' of new JButton.
      JButton Retrieve_Attrac_button = new JButton("SHOW");
      // add the action for button 'Retrieve_Attrac_button'.
      Retrieve_Attrac_button.addActionListener(new ActionListener() {
         // show the attraction and city at Retrieve Panel when Administrator mode.
         public void actionPerformed(ActionEvent arg0) {
            // declare the tableName of "DBCOURSE_Attraction"
            tableName = "DBCOURSE_Attraction";
            // set the columns name of food type table.
            String colNames[] = { "city", "attraction" };
            // create the 'readm' of new retrieve_adm class.
            retrieve_adm readm = new retrieve_adm(tableName, colNames);
            JTable table;
            try {
               table = readm.show();
               JScrollPane Ret_attrac_result = new JScrollPane(table);
               Ret_attrac_result.setBounds(645, 45, 306, 150);
               Retrieve_Adm.add(Ret_attrac_result);
            } catch (SQLException e) {
               // TODO Auto-generated catch block
               e.printStackTrace();
            }

         }
      });
      Retrieve_Attrac_button.setForeground(SystemColor.textHighlight);
      Retrieve_Attrac_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Retrieve_Attrac_button.setBounds(850, 9, 101, 29);
      Retrieve_Adm.add(Retrieve_Attrac_button);

      JScrollPane scrollPane1 = new JScrollPane();
         scrollPane1.setBounds(645, 45, 306, 150);
         Retrieve_Adm.add(scrollPane1);
         
      JLabel label_27 = new JLabel("< Food Category >");
      label_27.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 18));
      label_27.setBounds(642, 198, 183, 27);
      Retrieve_Adm.add(label_27);

      // create the combobox 'Retrieve_RestInfo_Combobox' of new JComboBox.
      JComboBox Retrieve_RestInfo_Combobox = new JComboBox();
      Retrieve_RestInfo_Combobox.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Retrieve_RestInfo_Combobox.setBackground(Color.WHITE);
      Retrieve_RestInfo_Combobox.setBounds(27, 234, 545, 30);
      // set the model of 'Retrieve_RestInfo_Combobox' about combobox components.
      Retrieve_RestInfo_Combobox.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'Retrieve_RestInfo_Combobox' at 'Retrieve_Adm'
      Retrieve_Adm.add(Retrieve_RestInfo_Combobox);

      // create the button 'Retrieve_RestInfo_button' of new JButton.
      JButton Retrieve_RestInfo_button = new JButton("SHOW");
      // add the action for button 'Retrieve_RestInfo_button'.
      Retrieve_RestInfo_button.addActionListener(new ActionListener() {
         // show the menu information of restaurants at Retrieve Panel when Administrator
         // mode.
         public void actionPerformed(ActionEvent e) {
            // get 'Retrieve_RestInfo_Combobox' of component in tableName.
            tableName = (String) Retrieve_RestInfo_Combobox.getSelectedItem();
            // call the 'whichTable' method
            whichTable();
            // set the columns name of restaurants table.
            String colNames[] = { "name", "menu", "price", "calories", "category" };
            // create the 'readm' of new retrieve_adm class.
            retrieve_adm readm = new retrieve_adm(tableName, index, colNames);
            JTable table;
            try {
               table = readm.show();
               JScrollPane Ret_info_result = new JScrollPane(table);
               Ret_info_result.setBounds(27, 268, 547, 220);
               Retrieve_Adm.add(Ret_info_result);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }
         }

      });
      // create the button 'Retrieve_FoodCate_button' of new JButton.
      JButton Retrieve_FoodCate_button = new JButton("SHOW");
      // add the action for button 'Retrieve_FoodCate_button'
      Retrieve_FoodCate_button.addActionListener(new ActionListener() {
         // show the food category and using ingredients at Retrieve Panel when
         // Administrator mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName of "DBCOURSE_FoodCategory"
            tableName = "DBCOURSE_FoodCategory";
            // set the columns name of food category table.
            String colNames[] = { "category", "ingredients" };
            // create the 'readm' of new retrieve_adm class.
            retrieve_adm readm = new retrieve_adm(tableName, colNames);
            JTable table;
            try {
               table = readm.show();
               JScrollPane Ret_cate_result = new JScrollPane(table);
               Ret_cate_result.setBounds(642, 237, 306, 251);
               Retrieve_Adm.add(Ret_cate_result);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }
         }
      });
      Retrieve_FoodCate_button.setForeground(SystemColor.textHighlight);
      Retrieve_FoodCate_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Retrieve_FoodCate_button.setBounds(847, 202, 101, 29);
      Retrieve_Adm.add(Retrieve_FoodCate_button);

      JScrollPane scrollPane3 = new JScrollPane();
         scrollPane3.setBounds(27, 268, 547, 220);
         Retrieve_Adm.add(scrollPane3);
         
      
      JLabel label_28 = new JLabel("< Restaurants' Info >");
      label_28.setBackground(new Color(240, 240, 240));
      label_28.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 18));
      label_28.setBounds(27, 198, 211, 21);
      Retrieve_Adm.add(label_28);

      Retrieve_RestInfo_button.setForeground(SystemColor.textHighlight);
      Retrieve_RestInfo_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Retrieve_RestInfo_button.setBounds(471, 198, 101, 29);
      Retrieve_Adm.add(Retrieve_RestInfo_button);

      JScrollPane scrollPane4 = new JScrollPane();
         scrollPane4.setBounds(642, 237, 306, 251);
         Retrieve_Adm.add(scrollPane4);
         
      // create Panel 'delete' of new JPanel.
      JPanel delete = new JPanel();
      delete.setBackground(Color.WHITE);
      // add tab about delete Administrator mode at 'tabbedPane'.
      tabbedPane.addTab("delete", null, delete, null);
      delete.setLayout(null);

      JLabel delete_Rest_label = new JLabel("< Restaurant >");
      delete_Rest_label.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      delete_Rest_label.setBounds(151, 15, 194, 27);
      delete.add(delete_Rest_label);

      // create the combobox 'delete_RestName_comboBox_1' of new JComboBox.
      JComboBox delete_RestName_comboBox_1 = new JComboBox();
      delete_RestName_comboBox_1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_RestName_comboBox_1.setBackground(Color.WHITE);
      delete_RestName_comboBox_1.setBounds(304, 66, 220, 30);
      // set the model of 'delete_RestName_comboBox_1' about combobox components.
      delete_RestName_comboBox_1.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'delete_RestName_comboBox_1' at 'Retrieve_User1'.
      delete.add(delete_RestName_comboBox_1);

      delete_Menu_text = new JTextField();
      delete_Menu_text.setColumns(40);
      delete_Menu_text.setBounds(305, 112, 381, 35);
      delete.add(delete_Menu_text);

      // create the new JTextPane about TextPane 'delete_Result'
      JTextPane delete_Result = new JTextPane();
      delete_Result.setBackground(UIManager.getColor("Button.background"));
      delete_Result.setBounds(161, 448, 656, 40);
      delete.add(delete_Result);

      // create the button 'delete_Rest_button' of new JButton.
      JButton delete_Rest_button = new JButton("ENTER");
      // add the action for button 'delete_Rest_button'.
      delete_Rest_button.addActionListener(new ActionListener() {
         // when user click the button of delete related to restaurant in the 'delete'
         // panel
         public void actionPerformed(ActionEvent e) {
            // save the value of restaurant name
            tableName = (String) delete_RestName_comboBox_1.getSelectedItem();
            String name = tableName;
            // using restaurant name, get the real table name of database
            whichTable();
            // get the menu name to delete
            String menu = (String) delete_Menu_text.getText();
            // when user click the button without any menu name
            if (menu.equals("")) {
               menu = null;
               // show the message to input again
               delete_Result.setText("menu¸¦ ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               return; // quit the method
            }
            // use the delete's constructor
            delete resdelete = new delete(tableName, menu);
            // implement the Restaurantdelete() method in the delete class
            resdelete.Restaurantdelete();
            // complete the request, then set the text on the textfield to vacuum
            delete_Menu_text.setText("");
            // show the success message
            delete_Result.setText(name + "ÀÇ menu »èÁ¦¸¦ ¼º°øÇÏ¿´½À´Ï´Ù.");
         }
      });
      delete_Rest_button.setForeground(SystemColor.textHighlight);
      delete_Rest_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_Rest_button.setBounds(706, 114, 90, 30);
      delete.add(delete_Rest_button);
         
      JLabel delete_Price = new JLabel("< Price >");
      delete_Price.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      delete_Price.setBounds(151, 174, 118, 21);
      delete.add(delete_Price);

      // create the combobox 'delete_Price_Name_comboBox_2' of new JComboBox.
      JComboBox delete_Price_Name_comboBox_2 = new JComboBox();
      delete_Price_Name_comboBox_2.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_Price_Name_comboBox_2.setBackground(Color.WHITE);
      delete_Price_Name_comboBox_2.setBounds(304, 203, 220, 30);
      // set the model of 'delete_Price_Name_comboBox_2' about combobox components.
      delete_Price_Name_comboBox_2.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'delete_Price_Name_comboBox_2' at 'delete'.
      delete.add(delete_Price_Name_comboBox_2);

      // create the new JTextField about Textfield 'delete_PriceRange1_textField_1'
      delete_PriceRange1_textField_1 = new JTextField();
      delete_PriceRange1_textField_1.setColumns(18);
      delete_PriceRange1_textField_1.setBounds(305, 252, 140, 35);
      // add textfield about 'delete_PriceRange1_textField_1' at Retrieve_User2
      delete.add(delete_PriceRange1_textField_1);

      JLabel label_2 = new JLabel("~ ");
      label_2.setBounds(477, 251, 20, 37);
      delete.add(label_2);

      // create the new JTextField about Textfield 'delete_PriceRange2_textField_2'
      delete_PriceRange2_textField_2 = new JTextField();
      delete_PriceRange2_textField_2.setColumns(18);
      delete_PriceRange2_textField_2.setBounds(525, 252, 140, 35);
      delete.add(delete_PriceRange2_textField_2);

      JButton delete_Price_button = new JButton("ENTER");// create the button 'delete_Price_button' of new JButton.
      delete_Price_button.addActionListener(new ActionListener() {// add the action for button 'delete_Price_button'.
         public void actionPerformed(ActionEvent e) {// when user click the button of delete related to price in the
                                          // 'delete' panel
            tableName = (String) delete_Price_Name_comboBox_2.getSelectedItem();// get the restaurant name in the
                                                               // comboBox
            String name = tableName;// save the value of restaurant name
            whichTable();// using restaurant name, get the real table name of database
            String min = (String) delete_PriceRange1_textField_1.getText();// get the min value of price
            String max = (String) delete_PriceRange2_textField_2.getText();// get the max value of price

            if (min.equals("") || max.equals("")) {// when user click the button without price value
               delete_Result.setText("»èÁ¦ÇÒ price ¹üÀ§¸¦ ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä.");// show the message to input again
               // clear the textfield.
               delete_PriceRange1_textField_1.setText("");
               delete_PriceRange2_textField_2.setText("");
               return; // quit the method
            }
            int price_min = Integer.parseInt(delete_PriceRange1_textField_1.getText());// change the type of min
                                                                     // value of price to int
            int price_max = Integer.parseInt(delete_PriceRange2_textField_2.getText());// change the type of max
                                                                     // value of price to int
            delete pricedelete = new delete(tableName, price_min, price_max); // use the delete's constructor
            pricedelete.Pricedelete();// implement the Pricedelete() method in the delete class
            delete_PriceRange1_textField_1.setText("");// complete the request, then set the text on the textfield
                                             // to vacuum
            delete_PriceRange2_textField_2.setText("");// complete the request, then set the text on the textfield
                                             // to vacuum
            delete_Result.setText(name + "ÀÇ ÇØ´ç price ¹üÀ§ ¸Þ´º¸¦ »èÁ¦Çß½À´Ï´Ù.");// show the success message
         }
      });
      delete_Price_button.setForeground(SystemColor.textHighlight);
      delete_Price_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_Price_button.setBounds(706, 254, 90, 30);
      delete.add(delete_Price_button);

      JLabel delete_Calories = new JLabel("< Calories >");
      delete_Calories.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      delete_Calories.setBounds(151, 323, 167, 21);
      delete.add(delete_Calories);

      // create the combobox 'delete_Calories_NamecomboBox_3' of new JComboBox.
      JComboBox delete_Calories_NamecomboBox_3 = new JComboBox();
      delete_Calories_NamecomboBox_3.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_Calories_NamecomboBox_3.setBackground(Color.WHITE);
      delete_Calories_NamecomboBox_3.setBounds(304, 353, 220, 30);
      // set the model of 'delete_Calories_NamecomboBox_3' about combobox components.
      delete_Calories_NamecomboBox_3.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'delete_Calories_NamecomboBox_3' at 'Retrieve_User1'.
      delete.add(delete_Calories_NamecomboBox_3);

      // create the new JTextField about Textfield 'delete_CaloriesRange1_textField_3'
      delete_CaloriesRange1_textField_3 = new JTextField();
      delete_CaloriesRange1_textField_3.setColumns(18);
      delete_CaloriesRange1_textField_3.setBounds(305, 402, 140, 35);
      delete.add(delete_CaloriesRange1_textField_3);

      JLabel label_12 = new JLabel("~ ");
      label_12.setBounds(477, 401, 20, 37);
      delete.add(label_12);

      // create the new JTextField about Textfield 'delete_CaloriesRange2_textField_4'
      delete_CaloriesRange2_textField_4 = new JTextField();
      delete_CaloriesRange2_textField_4.setColumns(18);
      delete_CaloriesRange2_textField_4.setBounds(525, 402, 140, 35);
      delete.add(delete_CaloriesRange2_textField_4);

      // create the button 'delete_Calories_button' of new JButton.
      JButton delete_Calories_button = new JButton("ENTER");
      // add the action for button 'delete_Calories_button'.
      delete_Calories_button.addActionListener(new ActionListener() {
          //delete the restaurant menu in calory range at Delete Panel when Administrator mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName about 'delete_Calories_NamecomboBox_3' into String.
            tableName = (String) delete_Calories_NamecomboBox_3.getSelectedItem();
            String name = tableName;
            // call the 'whichTable' method.
            whichTable();
            // declare the min about 'delete_CaloriesRange1_textField_3' into String.
            String min = (String) delete_CaloriesRange1_textField_3.getText();
            // declare the max about 'delete_CaloriesRange2_textField_4' into String.
            String max = (String) delete_CaloriesRange2_textField_4.getText();
            // if min or max enter the null value
            if (min.equals("") || max.equals("")) {
               delete_Result.setText("»èÁ¦ÇÒ calory ¹üÀ§¸¦ ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               // clear the textfield.
               delete_CaloriesRange1_textField_3.setText("");
               delete_CaloriesRange2_textField_4.setText("");
               return; // try again the enter the value
            }
            // get back the value of 'delete_CaloriesRange1_textField_3' in caloty_min
            int calory_min = Integer.parseInt(delete_CaloriesRange1_textField_3.getText());
            // get back the value of 'delete_CaloriesRange1_textField_4' in caloty_max
            int calory_max = Integer.parseInt(delete_CaloriesRange2_textField_4.getText());
            // create the 'calorydelete' of new delete class
            delete calorydelete = new delete(tableName, calory_min, calory_max);
            // run the 'Calorydelete' method in 'delete' class
            calorydelete.Calorydelete();
            delete_CaloriesRange1_textField_3.setText("");
            delete_CaloriesRange2_textField_4.setText("");
            delete_Result.setText(name + "ÀÇ ÇØ´ç calory ¹üÀ§ ¸Þ´º¸¦ »èÁ¦Çß½À´Ï´Ù.");
         }
      });

      delete_Calories_button.setForeground(SystemColor.textHighlight);
      delete_Calories_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_Calories_button.setBounds(706, 404, 90, 30);
      delete.add(delete_Calories_button);

      JLabel delete_RestName1 = new JLabel("Name");
      delete_RestName1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_RestName1.setBounds(230, 70, 52, 17);
      delete.add(delete_RestName1);

      JLabel delete_RestMenu = new JLabel("Menu");
      delete_RestMenu.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_RestMenu.setBounds(230, 116, 52, 26);
      delete.add(delete_RestMenu);

      JLabel delete_RestName2 = new JLabel("Name");
      delete_RestName2.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_RestName2.setBounds(230, 210, 52, 23);
      delete.add(delete_RestName2);

      JLabel delete_PriceRange = new JLabel("Price Range");
      delete_PriceRange.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_PriceRange.setBounds(189, 251, 101, 34);
      delete.add(delete_PriceRange);

      JLabel delete_RestName3 = new JLabel("Name");
      delete_RestName3.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_RestName3.setBounds(230, 359, 52, 17);
      delete.add(delete_RestName3);

      JLabel delete_CaloriesRange = new JLabel("Calories Range");
      delete_CaloriesRange.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      delete_CaloriesRange.setBounds(161, 404, 129, 29);
      delete.add(delete_CaloriesRange);

      // create Panel 'update' of new JPanel.
      JPanel update = new JPanel();
      update.setBackground(Color.WHITE);
      // add tab about delete Administrator mode at 'tabbedPane'.
      tabbedPane.addTab("update", null, update, null);
      update.setLayout(null);

      JLabel update_label_18 = new JLabel("< Attraction >");
      update_label_18.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      update_label_18.setBounds(159, 245, 200, 21);
      update.add(update_label_18);

      JLabel update_label_19 = new JLabel("Attraction");
      update_label_19.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      update_label_19.setForeground(Color.RED);
      update_label_19.setBounds(226, 330, 200, 35);
      update.add(update_label_19);

      // create the new JTextField about Textfield 'update_Attraction_textField_15'.
      update_Attraction_textField_15 = new JTextField();
      update_Attraction_textField_15.setColumns(18);
      update_Attraction_textField_15.setBounds(351, 330, 220, 30);
      update.add(update_Attraction_textField_15);

      // create the combobox 'update_Attraction_City_comboBox_4' of new JComboBox.
      JComboBox update_Attraction_City_comboBox_4 = new JComboBox();
      update_Attraction_City_comboBox_4.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      update_Attraction_City_comboBox_4.setBackground(Color.WHITE);
      update_Attraction_City_comboBox_4.setBounds(351, 280, 220, 30);
      // set the model of 'update_Attraction_City_comboBox_4' about combobox
      // components.
      update_Attraction_City_comboBox_4
            .setModel(new DefaultComboBoxModel(new String[] { "Seoul", "Busan", "Jeonju", "Gangwon-do", "Jeju" }));
      // add combobox 'update_Attraction_City_comboBox_4' at 'update'.
      update.add(update_Attraction_City_comboBox_4);

      // create the new JTextPane about TextPane 'update_Result'.
      JTextPane update_Result = new JTextPane();
      update_Result.setBackground(UIManager.getColor("Button.background"));
      update_Result.setBounds(159, 399, 656, 40);
      update.add(update_Result);

      // create the button 'delete_Calories_button' of new JButton.
      JButton update_Attraction_button_6 = new JButton("ENTER");
      update_Attraction_button_6.addActionListener(new ActionListener() {

         public void actionPerformed(ActionEvent e) {// when user click the button of delete related to attraction in
                                          // the 'update' panel
            String city = (String) update_Attraction_City_comboBox_4.getSelectedItem();// get the city name in the
                                                                     // comboBox
            String attraction = (String) update_Attraction_textField_15.getText();// get the attraction name to
                                                                  // update

            if (attraction.equals("")) {// when user click the button without any attraction name
               update_Result.setText("updateÇÒ attractionÀ» ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä.");// show the message to input again
               return; // quit the method
            }

            update attractupdate = new update(city, attraction); // use the update's constructor
            attractupdate.AttractionUpdate();// implement the AttractionUpdate() method in the update class
            update_Attraction_textField_15.setText("");// complete the request, then set the text on the textfield
                                             // to vacuum
            update_Result.setText(city + "ÀÇ attraction update¸¦ ¼º°øÇß½À´Ï´Ù."); // show the success message
         }
      });
      update_Attraction_button_6.setForeground(SystemColor.textHighlight);
      update_Attraction_button_6.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      update_Attraction_button_6.setBounds(726, 330, 90, 30);
      update.add(update_Attraction_button_6);

      // create the combobox 'update_Restaurants_City_comboBox_1' of new JComboBox.
      JComboBox update_Restaurants_City_comboBox_1 = new JComboBox();
      update_Restaurants_City_comboBox_1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      update_Restaurants_City_comboBox_1.setBackground(Color.WHITE);
      update_Restaurants_City_comboBox_1.setBounds(351, 91, 220, 30);
      // set the model of 'update_Restaurants_City_comboBox_1' about combobox
      // components.
      update_Restaurants_City_comboBox_1.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'update_Restaurants_City_comboBox_1' at 'update'.
      update.add(update_Restaurants_City_comboBox_1);

      // create the button 'update_Rest_button_6' of new JButton.
      JButton update_Rest_button_6 = new JButton("ENTER");
      // add the action for button 'update_Rest_button_6'.
      update_Rest_button_6.addActionListener(new ActionListener() {
         // update the price of menu of restaurants at Delete Panel when Administrator
         // mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName about 'update_Restaurants_City_comboBox_1' into String.
            tableName = (String) update_Restaurants_City_comboBox_1.getSelectedItem();
            String name = tableName;
            // call the 'whichTable' method
            whichTable();
            // declare the menu about 'update_Rest_Menu_textField_1' into String.
            String menu = (String) update_Rest_Menu_textField_1.getText();
            // declare the val about 'update_Rest_Price_textField_1' into String.
            String val = (String) update_Rest_Price_textField_1.getText();
            // if menu or val enter the null value
            if (menu.equals("") || val.equals("")) {
               update_Result.setText("updateÇÒ menu¿Í price °ªÀ» µÑ ´Ù ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               return; // try again the enter the value
            }

            // get back the value of 'val' in 'price'
            int price = Integer.parseInt(val);
            // create the 'attractupdate' of new update class
            update attractupdate = new update(tableName, menu, price);
            // run the 'RestaurantUpdate' method in 'update' class
            attractupdate.RestaurantUpdate();
            update_Rest_Menu_textField_1.setText("");
            update_Rest_Price_textField_1.setText("");
            update_Result.setText(name + "ÀÇ update¸¦ ¼º°øÇß½À´Ï´Ù.");
         }
      });
      update_Rest_button_6.setForeground(SystemColor.textHighlight);
      update_Rest_button_6.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      update_Rest_button_6.setBounds(726, 184, 90, 30);
      update.add(update_Rest_button_6);

      JLabel label_1 = new JLabel("Price");
      label_1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_1.setForeground(Color.RED);
      label_1.setBounds(225, 184, 50, 35);
      update.add(label_1);

      JLabel label_3 = new JLabel("< Restaurants >");
      label_3.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      label_3.setBounds(159, 45, 170, 21);
      update.add(label_3);

      JLabel label_13 = new JLabel("Menu");
      label_13.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_13.setForeground(Color.RED);
      label_13.setBounds(225, 141, 50, 35);
      update.add(label_13);

      // create the new JTextField about Textfield 'update_Rest_Menu_textField_1'.
      update_Rest_Menu_textField_1 = new JTextField();
      update_Rest_Menu_textField_1.setColumns(18);
      update_Rest_Menu_textField_1.setBounds(351, 141, 200, 35);
      update.add(update_Rest_Menu_textField_1);

      // create the new JTextField about Textfield 'update_Rest_Price_textField_1'.
      update_Rest_Price_textField_1 = new JTextField();
      update_Rest_Price_textField_1.setColumns(18);
      update_Rest_Price_textField_1.setBounds(351, 184, 200, 35);
      update.add(update_Rest_Price_textField_1);

      JLabel label_16 = new JLabel("Name");
      label_16.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_16.setBounds(225, 91, 50, 35);
      update.add(label_16);

      JLabel label_17 = new JLabel("**Red -> REQUIRED FIELD");
      label_17.setForeground(Color.RED);
      label_17.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 15));
      label_17.setBounds(350, 45, 259, 35);
      update.add(label_17);

      JLabel label_18 = new JLabel("ex) Sweet Potato Fries");
      label_18.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      label_18.setBounds(557, 141, 188, 35);
      update.add(label_18);

      JLabel label_19 = new JLabel("ex) 16900");
      label_19.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      label_19.setBounds(557, 184, 188, 35);
      update.add(label_19);

      JLabel lblExNamsanHaeundae = new JLabel("ex) Namsan, Haeundae");
      lblExNamsanHaeundae.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      lblExNamsanHaeundae.setBounds(385, 332, 188, 35);
      update.add(lblExNamsanHaeundae);

      JLabel lblCity = new JLabel("City");
      lblCity.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      lblCity.setForeground(Color.RED);
      lblCity.setBounds(226, 280, 50, 35);
      update.add(lblCity);

      JLabel lblPrice = new JLabel("\u25B6 Update of Price");
      lblPrice.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 18));
      lblPrice.setForeground(new Color(0, 0, 255));
      lblPrice.setBounds(351, 220, 163, 21);
      update.add(lblPrice);

      JLabel lblUpdateOf = new JLabel("\u25B6 Update of Attraction");
      lblUpdateOf.setForeground(Color.BLUE);
      lblUpdateOf.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 18));
      lblUpdateOf.setBounds(351, 363, 200, 21);
      update.add(lblUpdateOf);

      // create the Panel 'Insert' of new JPanel
      JPanel Insert = new JPanel();
      Insert.setBackground(Color.WHITE);
      // add tab about 'Insert' administrator mode at 'tabbedPane'.
      tabbedPane.addTab("Insert", null, Insert, null);
      Insert.setLayout(null);

      // create the combobox 'Insert_Rest_Name_comboBox_1' of new JComboBox.
      JComboBox Insert_Rest_Name_comboBox_1 = new JComboBox();
      Insert_Rest_Name_comboBox_1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Insert_Rest_Name_comboBox_1.setBackground(Color.WHITE);
      Insert_Rest_Name_comboBox_1.setBounds(341, 212, 220, 30);
      // set the model of 'Insert_Rest_Name_comboBox_1' about combobox components.
      Insert_Rest_Name_comboBox_1.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'Insert_Rest_Name_comboBox_1' at 'Insert'.
      Insert.add(Insert_Rest_Name_comboBox_1);

      // create the TextPane 'Insert_Result' of new TextPane.
      JTextPane Insert_Result = new JTextPane();
      Insert_Result.setBackground(UIManager.getColor("Button.background"));
      Insert_Result.setBounds(151, 440, 656, 40);
      Insert.add(Insert_Result);

      // create the button 'Insert_Rest_button_6' of new JButton.
      JButton Insert_Rest_button_6 = new JButton("ENTER");
      // add the action for button 'Insert_Rest_button_6'.
      Insert_Rest_button_6.addActionListener(new ActionListener() {
          //insert the menu, price, calory and category in selected restaurants at Insert
          //Panel when Administrator mode.
          
         public void actionPerformed(ActionEvent e) {
            // declare the tableName about 'Insert_Rest_Name_comboBox_1' into String.
            tableName = (String) Insert_Rest_Name_comboBox_1.getSelectedItem();
            String name = tableName;
            // clarify a table name
            whichTable();

            // declare the menu about 'Insert_Rest_Menu_textField' into String.
            String menu = (String) Insert_Rest_Menu_textField.getText();
            // declare the price_val about 'Insert_Rest_Price_textField_1' into String.
            String price_val = (String) Insert_Rest_Price_textField_1.getText();
            // declare the calories about 'Insert_Rest_Calo_textField_1' into String.
            String calories = (String) Insert_Rest_Calo_textField_1.getText();
            // declare the category about 'Insert_Rest_Cate_textField_1' into String.
            String category = (String) Insert_Rest_Cate_textField_1.getText();

            // if menu or price_val enter the null value
            if (menu.equals("") || price_val.equals("")) {
               Insert_Result.setText("menu, price°ªÀ» µÑ ´Ù ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               return; // try again the enter the value
            }
            if (calories.equals("")) {
               calories = null;
            }
            if (category.equals("")) {
               category = null;
            }
            try {
               // get back the value of 'delete_PriceRange1_textField_1' in price_min.
               int price = Integer.parseInt(price_val);
               // insert using the method RestaurantInsert()
               insert resinsert = new insert(tableName, name, menu, price, calories, category);
               // run the 'RestaurantInsert' method in 'insert' class.
               resinsert.RestaurantInsert();
            } catch (NumberFormatException e1) {
               // if price and calories is not integer
               // print the panel 'Insert_Result'
               Insert_Result.setText("price, calories°ªÀ» Á¤¼ö·Î ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               return; // try again enter the value.
            }
            /* clear textFields */
            Insert_Rest_Menu_textField.setText("");
            Insert_Rest_Price_textField_1.setText("");
            Insert_Rest_Calo_textField_1.setText("");
            Insert_Rest_Cate_textField_1.setText("");
            Insert_Result.setText(name + "ÀÇ menu insert¸¦ ¼º°øÇÏ¿´½À´Ï´Ù.");
         }
      });
      Insert_Rest_button_6.setForeground(SystemColor.textHighlight);
      Insert_Rest_button_6.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Insert_Rest_button_6.setBounds(717, 390, 90, 30);
      Insert.add(Insert_Rest_button_6);

      // create the new JTextField about Textfield 'Insert_Rest_Menu_textField'.
      Insert_Rest_Menu_textField = new JTextField();
      Insert_Rest_Menu_textField.setColumns(18);
      Insert_Rest_Menu_textField.setBounds(342, 262, 200, 35);
      Insert.add(Insert_Rest_Menu_textField);

      // create the new JTextField about Textfield 'Insert_Rest_Price_textField_1'.
      Insert_Rest_Price_textField_1 = new JTextField();
      Insert_Rest_Price_textField_1.setColumns(18);
      Insert_Rest_Price_textField_1.setBounds(342, 305, 200, 35);
      Insert.add(Insert_Rest_Price_textField_1);

      JLabel label_7 = new JLabel("Calories");
      label_7.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_7.setBounds(216, 345, 96, 35);
      Insert.add(label_7);

      // create the new JTextField about Textfield 'Insert_Rest_Calo_textField_1'.
      Insert_Rest_Calo_textField_1 = new JTextField();
      Insert_Rest_Calo_textField_1.setColumns(18);
      Insert_Rest_Calo_textField_1.setBounds(342, 345, 200, 35);
      Insert.add(Insert_Rest_Calo_textField_1);

      JLabel label_8 = new JLabel("Category");
      label_8.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_8.setBounds(216, 390, 90, 35);
      Insert.add(label_8);

      // create the new JTextField about Textfield 'Insert_Rest_Cate_textField_1'.
      Insert_Rest_Cate_textField_1 = new JTextField();
      Insert_Rest_Cate_textField_1.setColumns(18);
      Insert_Rest_Cate_textField_1.setBounds(342, 390, 200, 35);
      Insert.add(Insert_Rest_Cate_textField_1);

      JLabel label_4 = new JLabel("Price");
      label_4.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_4.setForeground(Color.RED);
      label_4.setBounds(216, 305, 50, 35);
      Insert.add(label_4);

      JLabel label_5 = new JLabel("< Restaurants >");
      label_5.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      label_5.setBounds(151, 165, 170, 21);
      Insert.add(label_5);

      JLabel label_6 = new JLabel("Menu");
      label_6.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_6.setForeground(Color.RED);
      label_6.setBounds(216, 262, 50, 35);
      Insert.add(label_6);

      JLabel lblName = new JLabel("Name");
      lblName.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      lblName.setBounds(216, 212, 50, 35);
      Insert.add(lblName);

      JLabel lblExSweetPotato = new JLabel("ex) Sweet Potato Fries");
      lblExSweetPotato.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      lblExSweetPotato.setBounds(548, 262, 188, 35);
      Insert.add(lblExSweetPotato);

      JLabel lblEx = new JLabel("ex) 16900");
      lblEx.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      lblEx.setBounds(548, 305, 188, 35);
      Insert.add(lblEx);

      JLabel lblEx_1 = new JLabel("ex) 710");
      lblEx_1.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      lblEx_1.setBounds(548, 345, 188, 35);
      Insert.add(lblEx_1);

      JLabel lblExNoodle = new JLabel("ex) Noodles");
      lblExNoodle.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      lblExNoodle.setBounds(548, 390, 188, 35);
      Insert.add(lblExNoodle);

      JLabel lblRedRequired = new JLabel("**Red -> REQUIRED FIELD");
      lblRedRequired.setForeground(Color.RED);
      lblRedRequired.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 15));
      lblRedRequired.setBounds(341, 15, 259, 35);
      Insert.add(lblRedRequired);

      JLabel label = new JLabel("< Food Category >");
      label.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      label.setBounds(151, 15, 200, 30);
      Insert.add(label);

      JLabel label_9 = new JLabel("Category");
      label_9.setForeground(Color.RED);
      label_9.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_9.setBounds(209, 60, 113, 35);
      Insert.add(label_9);

      // create the new JTextField about Textfield 'Insert_FoodCate_Cate_textField_1'.
      Insert_FoodCate_Cate_textField_1 = new JTextField();
      Insert_FoodCate_Cate_textField_1.setColumns(18);
      Insert_FoodCate_Cate_textField_1.setBounds(335, 60, 200, 35);
      Insert.add(Insert_FoodCate_Cate_textField_1);

      JLabel label_10 = new JLabel("Ingredients");
      label_10.setForeground(Color.RED);
      label_10.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      label_10.setBounds(209, 108, 113, 35);
      Insert.add(label_10);

      // create the new JTextField about Textfield
      // 'Insert_FoodCate_Ingre_textField_1'.
      Insert_FoodCate_Ingre_textField_1 = new JTextField();
      Insert_FoodCate_Ingre_textField_1.setColumns(18);
      Insert_FoodCate_Ingre_textField_1.setBounds(335, 108, 200, 35);
      Insert.add(Insert_FoodCate_Ingre_textField_1);

      JLabel label_11 = new JLabel("ex) Wheat flour");
      label_11.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      label_11.setBounds(541, 108, 188, 35);
      Insert.add(label_11);

      JLabel label_22 = new JLabel("ex) Noodle");
      label_22.setFont(new Font("¸¼Àº °íµñ", Font.ITALIC, 13));
      label_22.setBounds(541, 60, 188, 35);
      Insert.add(label_22);

      // create the button 'Insert_FoodCate_button_6' of new JButton.
      JButton Insert_FoodCate_button_6 = new JButton("ENTER");
      // add the action for button 'Insert_FoodCate_button_6'.
      Insert_FoodCate_button_6.addActionListener(new ActionListener() {
         // insert the category and ingredients at Insert Panel when Administrator mode.
         public void actionPerformed(ActionEvent e) {
            // declare the category about 'Insert_FoodCate_Cate_textField_1' into String.
            String category = (String) Insert_FoodCate_Cate_textField_1.getText();
            // declare the ingredients about 'Insert_FoodCate_Cate_textField_1' into String.
            String ingredients = (String) Insert_FoodCate_Ingre_textField_1.getText();
            // if category enter the null value
            if (category.equals("") || ingredients.equals("")) {
               Insert_Result.setText("category, ingredients¸¦ ¸ðµÎ ÀÔ·ÂÇØÁÖ¼¼¿ä.");
               return; // try again the enter the value.
            }

            // create the 'resinsert' of new insert class.
            insert resinsert = new insert(category, ingredients);
            // insert using the method CategoryInsert()
            resinsert.CategoryInsert();
            /* clear textFields */
            Insert_FoodCate_Cate_textField_1.setText("");
            Insert_FoodCate_Ingre_textField_1.setText("");
            Insert_Result.setText("category insert¸¦ ¼º°øÇÏ¿´½À´Ï´Ù.");
         }
      });
      Insert_FoodCate_button_6.setForeground(SystemColor.textHighlight);
      Insert_FoodCate_button_6.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Insert_FoodCate_button_6.setBounds(710, 108, 90, 30);
      Insert.add(Insert_FoodCate_button_6);

      // create the Panel 'Grades' of new JPanel
      JPanel Grades = new JPanel();
      Grades.setBackground(Color.WHITE);
      // add tab about Grades Administrator mode at 'tabbedPane'.
      tabbedPane.addTab("Grades", null, Grades, null);
      Grades.setLayout(null);

      // create the button 'btnNewButton' of new JButton.
      JButton btnNewButton = new JButton("SHOW");
      // add the action for button 'btnNewButton'.
      btnNewButton.addActionListener(new ActionListener() {
         // show the grade of restaurants at Grade Panel when Administrator mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName of "DBCOURSE_Grades"
            tableName = "DBCOURSE_Grades";
            // in this button, columns in colNames should be selected
            String colNames[] = { "name", "grades" };
            // create a object of class named 'retrieve_adm'
            retrieve_adm resgrade = new retrieve_adm(tableName, colNames);
            // execute 'show' method in 'retrieve_adm' and it becomes a value of 'table'
            JTable table;
            try {
               table = resgrade.show(); // create a scrollpane named 'grades_scrollPane' including data of 'table'
               JScrollPane scrollPane = new JScrollPane(table);
               scrollPane.setBounds(258, 145, 512, 245);
               // panel named 'Grades' contains 'grades_scrollPane'
               Grades.add(scrollPane);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }

         }
      });
      btnNewButton.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      btnNewButton.setForeground(SystemColor.textHighlight);
      btnNewButton.setBounds(668, 85, 102, 29);
      Grades.add(btnNewButton);

      JLabel label_14 = new JLabel("<Grades>");
      label_14.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 20));
      label_14.setBounds(258, 80, 112, 37);
      Grades.add(label_14);

   }

   /**
    * whichTable is method that is used when we know only restaurant's name, not a
    * table's name restaurant's name is changed into real table's name of database
    */
   public void whichTable() {
      String str = null, idx = null;
      // insert the str and idx when restaurant is selected.
      if (tableName.equals("Chienrong")) {
         str = "DBCOURSE_Rst1";
         idx = "i_price_rst1";
      } else if (tableName.equals("Dintaifung")) {
         str = "DBCOURSE_Rst2";
         idx = "i_price_rst2";
      } else if (tableName.equals("California Pizza Kitchen")) {
         str = "DBCOURSE_Rst3";
         idx = "i_price_rst3";
      } else if (tableName.equals("Haeundae Smokehouse")) {
         str = "DBCOURSE_Rst4";
         idx = "i_price_rst4";
      } else if (tableName.equals("JamaeGuksu")) {
         str = "DBCOURSE_Rst5";
         idx = "i_price_rst5";
      } else if (tableName.equals("HanKookJib")) {
         str = "DBCOURSE_Rst6";
         idx = "i_price_rst6";
      } else if (tableName.equals("ChungWoo")) {
         str = "DBCOURSE_Rst7";
         idx = "i_price_rst7";
      }
      tableName = str; // insert the str in tableName
      index = idx; // insert the idx in index
   }
}
