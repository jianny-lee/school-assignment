package team2;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.sql.*;
import java.awt.event.ActionEvent;
import java.awt.Color;
import javax.swing.ImageIcon;
/**
 * class that is a window for selection
 * @author YoungEun Lee, Dokyung Lee, HyoJin Lee
 *
 */
public class Open {
   static Connection myConn;
   private JFrame frmOpen;

   /**
    * Launch the application.
    */
   public static void main(String[] args) {
      try {
        Class.forName("com.mysql.cj.jdbc.Driver");
         myConn = DriverManager.getConnection("jdbc:mysql://localhost:3307/team2?serverTimezone=Asia/Seoul&useSSL=false", "team2", "team2");
         System.out.println("µ•¿Ã≈Õ∫£¿ÃΩ∫ø° ¡¢º”«ﬂΩ¿¥œ¥Ÿ.");
    
      } catch (Exception e) {
         e.printStackTrace();
         System.out.println(e.getMessage());
      }
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            try {
               Open window = new Open();
               window.frmOpen.setVisible(true);
            } catch (Exception e) {
               e.printStackTrace();
            }
         }
      });
   }

   /**
    * initialize the application.
    */
   public Open() {
      initialize();
   }

   /**
    * Initialize the contents of the frame.
    */
   private void initialize() {
      frmOpen = new JFrame();//create frame 'frmOpen' of new JFrame.
      frmOpen.getContentPane().setBackground(Color.WHITE);
      frmOpen.setBackground(Color.BLACK);
      frmOpen.setTitle("Open - KRAVEL");
      frmOpen.setBounds(0, 0, 623, 360);
      frmOpen.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      frmOpen.getContentPane().setLayout(null);
      frmOpen.setLocationRelativeTo(null);

   // create the button 'btnNewButton' of new JButton.
      JButton btnNewButton = new JButton("Administrator");
    //add the action for button 'btnNewButton'.
      btnNewButton.addActionListener(new ActionListener() {
         /**
           * show the Administrator Panel
           */
         public void actionPerformed(ActionEvent e) {
            Adm nw = new Adm(); //create the 'nw' of new Adm class.
            nw.AdmScreen(); //run the AdmScreen method.

         }
      });
      btnNewButton.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.PLAIN, 18));
      btnNewButton.setBounds(97, 180, 168, 46);
      frmOpen.getContentPane().add(btnNewButton);

      // create the button 'btnCustomer' of new JButton.
      JButton btnCustomer = new JButton("Customer");
      //add the action for button 'btnCustomer'.
      btnCustomer.addActionListener(new ActionListener() {
         /**
           * show the Customer Panel
           */
         public void actionPerformed(ActionEvent e) {
            Cus nw = new Cus(); //create the 'nw' of new Cus class
            nw.CusScreen(); //run the CusScreen method.
         }
      });
      btnCustomer.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.PLAIN, 18));
      btnCustomer.setBounds(334, 180, 168, 46);
      frmOpen.getContentPane().add(btnCustomer);

      JLabel lblS = new JLabel("Select the service you want ");
      lblS.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.BOLD, 25));
      lblS.setBounds(133, 110, 369, 34);
      frmOpen.getContentPane().add(lblS);

      JLabel lblHiWelcomeTo = new JLabel("Welcome to \"KRAVEL - Traveling in Korea\"");
      lblHiWelcomeTo.setForeground(new Color(0, 100, 0));
      lblHiWelcomeTo.setFont(new Font("Footlight MT Light", Font.PLAIN, 15));
      lblHiWelcomeTo.setBounds(136, 77, 326, 25);
      frmOpen.getContentPane().add(lblHiWelcomeTo);
      
   // create the button 'btnNewButton_1' of new JButton.
      JButton btnNewButton_1 = new JButton("Disconnect");
    //add the action for button 'btnNewButton_1'.
      btnNewButton_1.addActionListener(new ActionListener() {
         /**
           * close the window and disconnect. 
           */
         public void actionPerformed(ActionEvent arg0) {
             try {
                //if myConn is not null and myConn is not closed
                  if( myConn != null && !myConn.isClosed()){
                     myConn.close(); //disconnect the myConn
                    }
                  System.out.println("connection ¡§ªÛ¡æ∑·");
            } catch (SQLException e) {
               // TODO Auto-generated catch block
               e.printStackTrace();
            }
         }
      });
      btnNewButton_1.setBounds(217, 242, 168, 34);
      frmOpen.getContentPane().add(btnNewButton_1);
   }
}
