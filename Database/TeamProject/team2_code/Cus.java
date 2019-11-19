package team2;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

import javax.swing.*;
/**
 * class that is a window for customer
 * @author YoungEun Lee, DoKyung Lee, HyoJin Lee, NaGyeong Yeo
 *
 */
public class Cus {
   static String index = null;
   private JFrame frmCus;
   private String tableName;
   private JTextField textField;
   private JTextField textField_1;
   private JTextField grades_textField_2;

   /**
    * open the Cus window
    */
   public static void CusScreen() {
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            try {
               Cus window = new Cus();
               window.frmCus.setVisible(true);
            } catch (Exception e) {
               e.printStackTrace();
            }
         }
      });
   }

   /**
    * initialize the application.
    */
   public Cus() {
      initialize();
   }

   /**
    * Initialize the contents of the frame.
    */
   private void initialize() {
      frmCus = new JFrame(); // create frame 'frmCus' of new JFrame.
      frmCus.setTitle("Customer Service");
      frmCus.setBounds(0, 0, 1025, 594);
      frmCus.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      frmCus.getContentPane().setLayout(null);
      frmCus.setLocationRelativeTo(null);

      // create TabbedPane 'tabbedPane' of new TabbedPane at gui top.
      JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
      tabbedPane.setBackground(Color.WHITE);
      tabbedPane.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      tabbedPane.setBounds(0, 0, 1005, 542);
      frmCus.getContentPane().add(tabbedPane);

      // create Panel 'Retrieve_User1' of new JPanel.
      JPanel Retrieve_User1 = new JPanel();
      Retrieve_User1.setBackground(Color.WHITE);
      // add tab about retrieve(User) customer mode at 'tabbedPane'.
      tabbedPane.addTab("Retrieve(User)", null, Retrieve_User1, null);
      Retrieve_User1.setLayout(null);

      JLabel label = new JLabel("< Type >");
      label.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 19));
      label.setBounds(13, 256, 89, 29);
      Retrieve_User1.add(label);

      // create the combobox 'Ret_Cus_type_combobox' of new JComboBox.
      JComboBox Ret_Cus_type_combobox = new JComboBox();
      Ret_Cus_type_combobox.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_type_combobox.setBackground(Color.WHITE);
      Ret_Cus_type_combobox.setBounds(13, 287, 460, 30);
      // set the model of 'Ret_Cus_type_combobox' about combobox components.
      Ret_Cus_type_combobox
            .setModel(new DefaultComboBoxModel(new String[] { "Korean", "Western", "Chinese", "Japanese" }));
      // add combobox 'Ret_Cus_type_combobox' at 'Retrieve_User1'.
      Retrieve_User1.add(Ret_Cus_type_combobox);

      // create the button 'Ret_Cus_type_button' of new JButton.
      JButton Ret_Cus_type_button = new JButton("SHOW");
      // add the action for button 'Ret_Cus_type_button'.
      Ret_Cus_type_button.addActionListener(new ActionListener() {
          //show the food type at Retrieve Panel when Customer mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName of "DBCOURSE_type"
            tableName = "DBCOURSE_type";
            // get 'Ret_Cus_type_combobox' of component in String 'type'
            String type = (String) Ret_Cus_type_combobox.getSelectedItem();
            // set the columns name of food type table.
            String colNames[] = { "name", "menu", "price" };
            // create the 'restype' of new retrieve_cus class.
            retrieve_cus restype = new retrieve_cus(tableName, type, colNames);
            JTable table = restype.show();
            JScrollPane Ret_type_result = new JScrollPane(table);
            Ret_type_result.setBounds(3, 333, 470, 158);
            Retrieve_User1.add(Ret_type_result);
         }
      });
      Ret_Cus_type_button.setForeground(SystemColor.textHighlight);
      Ret_Cus_type_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_type_button.setBounds(372, 256, 101, 29);
      Retrieve_User1.add(Ret_Cus_type_button);

      JScrollPane scrollPane = new JScrollPane();
         scrollPane.setBounds(3, 333, 470, 158);
         Retrieve_User1.add(scrollPane);
         
      JLabel label_1 = new JLabel("< Restaurants >");
      label_1.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 19));
      label_1.setBounds(490, 13, 154, 29);
      Retrieve_User1.add(label_1);

      // create the combobox 'Ret_Cus_rst_combobox' of new JComboBox.
      JComboBox Ret_Cus_rst_combobox = new JComboBox();
      Ret_Cus_rst_combobox.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_rst_combobox.setBackground(Color.WHITE);
      Ret_Cus_rst_combobox.setBounds(490, 43, 493, 30);
      // set the model of 'Ret_Cus_rst_combobox' about combobox components.
      Ret_Cus_rst_combobox.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'Ret_Cus_rst_combobox' at 'Retrieve_User1'
      Retrieve_User1.add(Ret_Cus_rst_combobox);

      // create the button 'Ret_Cus_rst_button' of new JButton.
      JButton Ret_Cus_rst_button = new JButton("SHOW");
      // add the action for button 'Ret_Cus_rst_button'.
      Ret_Cus_rst_button.addActionListener(new ActionListener() {
         // show the menu information of restaurants at Retrieve Panel when Customer mode.
         public void actionPerformed(ActionEvent e) {
            // get 'Ret_Cus_rst_combobox' of component in tableName.
            tableName = (String) Ret_Cus_rst_combobox.getSelectedItem();
            // call the 'whichTable' method.
            whichTable();
            // set the columns name of restaurants table.
            String colNames[] = { "name", "menu", "price", "calories", "category" };
            // create the 'recus' of new retrieve_adm class.
            retrieve_adm recus = new retrieve_adm(tableName, index, colNames);
            JTable table;
            try {
               table = recus.show();
               JScrollPane scrollPane_1 = new JScrollPane(table);
               scrollPane_1.setBounds(484, 86, 502, 158);
               Retrieve_User1.add(scrollPane_1);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }
         }
      });

      Ret_Cus_rst_button.setForeground(SystemColor.textHighlight);
      Ret_Cus_rst_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_rst_button.setBounds(882, 13, 101, 29);
      Retrieve_User1.add(Ret_Cus_rst_button);

      JScrollPane scrollPane1 = new JScrollPane();
         scrollPane1.setBounds(484, 86, 502, 158);
         Retrieve_User1.add(scrollPane1);
         
      JLabel label_2 = new JLabel("< Grades >");
      label_2.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 19));
      label_2.setBounds(13, 13, 122, 29);
      Retrieve_User1.add(label_2);

      // create the button 'Ret_Cus_grade_button' of new JButton.
      JButton Ret_Cus_grade_button = new JButton("SHOW");
      // add the action for button 'Ret_Cus_grade_button'
      Ret_Cus_grade_button.addActionListener(new ActionListener() {
          //show the grade of restaurants at Retrieve Panel when Customer mode.
         public void actionPerformed(ActionEvent e) {
            // declare the tableName of "DBCOURSE_Grades"
            tableName = "DBCOURSE_Grades";
            // set the columns name of grade table.
            String colNames[] = { "name", "grades" };
            // create the 'resgrade' of new retrieve_adm class.
            retrieve_adm resgrade = new retrieve_adm(tableName, colNames);
            JTable table;
            try {
               table = resgrade.show();
               JScrollPane Cus_grade_result = new JScrollPane(table);
               Cus_grade_result.setBounds(6, 86, 470, 158);
               Retrieve_User1.add(Cus_grade_result);
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }
         }
      });
      Ret_Cus_grade_button.setForeground(SystemColor.textHighlight);
      Ret_Cus_grade_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_grade_button.setBounds(372, 13, 101, 29);
      Retrieve_User1.add(Ret_Cus_grade_button);

      JScrollPane scrollPane2 = new JScrollPane();
         scrollPane2.setBounds(6, 86, 470, 158);
         Retrieve_User1.add(scrollPane2);
         
      JLabel label_3 = new JLabel("< Attraction >");
      label_3.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 19));
      label_3.setBounds(490, 256, 137, 29);
      Retrieve_User1.add(label_3);

      // create the combobox 'Ret_Cus_attrac_combobox' of new JComboBox.
      JComboBox Ret_Cus_attrac_combobox = new JComboBox();
      Ret_Cus_attrac_combobox.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_attrac_combobox.setBackground(Color.WHITE);
      Ret_Cus_attrac_combobox.setBounds(488, 287, 495, 30);
      // set the model of 'Ret_Cus_attrac_combobox' about combobox components.
      Ret_Cus_attrac_combobox.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      // add combobox 'Ret_Cus_attrac_combobox' at 'Retrieve_User1'.
      Retrieve_User1.add(Ret_Cus_attrac_combobox);

      // create the button 'Ret_Cus_attrac_button' of new JButton.
      JButton Ret_Cus_attrac_button = new JButton("SHOW");
      // add the action for button 'Ret_Cus_attrac_button'.
      Ret_Cus_attrac_button.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
             //show the attraction and city of surrounding of restaurants at Retrieve Pane when Customer mode.
            // get 'Ret_Cus_attrac_combobox' of component in String 'name'
            String name = (String) Ret_Cus_attrac_combobox.getSelectedItem();
            // set the columns name of attraction table.
            String colNames[] = { "city", "attraction" };
            // create the 'res4' of new retrieve_cus class.
            retrieve_cus res4 = new retrieve_cus(name, colNames, 1);
            JTable table = res4.show4();
            JScrollPane scrollPane_3 = new JScrollPane(table);
            scrollPane_3.setBounds(484, 333, 502, 158);
            Retrieve_User1.add(scrollPane_3);
         }
      });
      Ret_Cus_attrac_button.setForeground(SystemColor.textHighlight);
      Ret_Cus_attrac_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_attrac_button.setBounds(882, 256, 101, 29);
      Retrieve_User1.add(Ret_Cus_attrac_button);

      JScrollPane scrollPane3 = new JScrollPane();
         scrollPane3.setBounds(484, 333, 502, 158);
         Retrieve_User1.add(scrollPane3);
         
      // create Panel 'Retrieve_User2' of new JPanel.
      JPanel Retrieve_User2 = new JPanel();
      Retrieve_User2.setBackground(Color.WHITE);
      // add tab about retrieve(Price) customer mode at 'tabbedPane'.
      tabbedPane.addTab("Retrieve(Price)", null, Retrieve_User2, null);
      Retrieve_User2.setLayout(null);

      JLabel label_4 = new JLabel("< Price >");
      label_4.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 17));
      label_4.setBounds(17, 0, 85, 29);
      Retrieve_User2.add(label_4);

      // create the new JTextField about Textfield 'Ret_Cus_price_min_textField'
      JTextField Ret_Cus_price_min_textField = new JTextField();
      Ret_Cus_price_min_textField.setBounds(119, 2, 114, 28);
      // add textfield about 'Ret_Cus_price_min_textField' at 'Retrieve_User2'
      Retrieve_User2.add(Ret_Cus_price_min_textField);
      Ret_Cus_price_min_textField.setColumns(10);

      JLabel label_5 = new JLabel("~ ");
      label_5.setBounds(250, 4, 20, 23);
      Retrieve_User2.add(label_5);

      // create the new JTextField about Textfield 'Ret_Cus_price_max_textField'
      JTextField Ret_Cus_price_max_textField = new JTextField();
      Ret_Cus_price_max_textField.setColumns(10);
      Ret_Cus_price_max_textField.setBounds(275, 2, 114, 28);
      // add textfield about Ret_Cus_price_max_textField at Retrieve_User2
      Retrieve_User2.add(Ret_Cus_price_max_textField);

      // create the button 'Ret_Cus_price_button' of new JButton.
      JButton Ret_Cus_price_button = new JButton("SHOW");
      // when user click the button of price
       //show all information of menu of restaurants at Retrieve Panel when Customer mode.
      Ret_Cus_price_button.addActionListener(new ActionListener() {
          public void actionPerformed(ActionEvent e) {
            tableName = "DBCOURSE_menu, DBCOURSE_foodCategory";
            String colNames[] = { "name", "menu", "price", "calories", "category", "ingredients" };
            // get 'Ret_Cus_price_min_textField' of component in String 'str_price1'
            String str_price1 = (String) Ret_Cus_price_min_textField.getText();
            // get 'Ret_Cus_price_max_textField' of component in String 'str_price2'
            String str_price2 = (String) Ret_Cus_price_max_textField.getText();
            int priceMin = Integer.parseInt(str_price1);
            int priceMax = Integer.parseInt(str_price2);

            // create the 'resSelectCus' of new retrieve_cus class.
            retrieve_cus resSelectCus = new retrieve_cus(tableName, priceMin, priceMax, colNames);
            JTable table = resSelectCus.show();
            JScrollPane scrollPane_4 = new JScrollPane(table);
            scrollPane_4.setBounds(17, 32, 966, 465);
            Retrieve_User2.add(scrollPane_4);
         }
      });
      Ret_Cus_price_button.setForeground(SystemColor.textHighlight);
      Ret_Cus_price_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      Ret_Cus_price_button.setBounds(405, 0, 101, 29);
      Retrieve_User2.add(Ret_Cus_price_button);

      JScrollPane scrollPane5 = new JScrollPane();
      scrollPane5.setBounds(17, 32, 966, 465);
         Retrieve_User2.add(scrollPane5);
         
      JPanel Grades = new JPanel();
      Grades.setLayout(null);
      Grades.setBackground(Color.WHITE);
      tabbedPane.addTab("Grades", null, Grades, null);

      // create the combobox 'grades_comboBox_1' of new JComboBox.
      JComboBox grades_comboBox_1 = new JComboBox();
      // set the model of 'grades_comboBox_1' about combobox components.
      grades_comboBox_1.setModel(new DefaultComboBoxModel(new String[] { "Chienrong", "Dintaifung",
            "California Pizza Kitchen", "Haeundae Smokehouse", "JamaeGuksu", "HanKookJib", "ChungWoo" }));
      grades_comboBox_1.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      grades_comboBox_1.setBackground(Color.WHITE);
      grades_comboBox_1.setBounds(14, 50, 493, 30);
      Grades.add(grades_comboBox_1);

      JLabel label_8 = new JLabel("< Grades >");
      label_8.setFont(new Font("¸¼Àº °íµñ", Font.BOLD, 19));
      label_8.setBounds(13, 13, 122, 29);
      Grades.add(label_8);

      JButton grades_button = new JButton("Enter");// create the button 'Ret_Cus_price_button' of new JButton.
      grades_button.addActionListener(new ActionListener() { // when user click the button of grades in the 'Grades panel
         public void actionPerformed(ActionEvent e) {
            String colNames[] = { "name", "grades" };
            String name = (String) grades_comboBox_1.getSelectedItem();// get the restaurant name in the comboBox
            // get the user's grade to reflect the user's review
            String grades = (String) grades_textField_2.getText();
            update gradeupdate = new update(name, colNames, grades);// use the update's constructor

            try {
               JTable table = gradeupdate.GradesUpdate();// get the return table value and save it on the 'table'
               JScrollPane gra = new JScrollPane(table); // create the Scrollpane include table
               gra.setBounds(24, 92, 919, 269);
               Grades.add(gra); // add 'gra' component to Grades panel
            } catch (SQLException e1) {
               // TODO Auto-generated catch block
               e1.printStackTrace();
            }

         }
      });
      grades_button.setForeground(SystemColor.textHighlight);
      grades_button.setFont(new Font("¸¼Àº °íµñ", Font.PLAIN, 18));
      grades_button.setBounds(855, 51, 101, 29);
      Grades.add(grades_button);

      JScrollPane scrollPane6 = new JScrollPane();
         scrollPane6.setBounds(24, 92, 919, 269);
         Grades.add(scrollPane6);
         
      // create the new JTextField about Textfield 'grades_textField_2'
      grades_textField_2 = new JTextField();
      grades_textField_2.setBounds(535, 50, 274, 30);
      Grades.add(grades_textField_2);
      grades_textField_2.setColumns(10);

   }
   /**
       * whichTable is method that is used 
       * when we know only restaurant's name, not a table's name  
       * restaurant's name is changed into real table's name of database
       */
   public void whichTable() {
      String str = null, idx = null;
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
      tableName = str;
      index = idx;
   }
}
