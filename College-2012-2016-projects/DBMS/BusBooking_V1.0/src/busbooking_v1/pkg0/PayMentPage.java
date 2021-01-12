/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package busbooking_v1.pkg0;

import com.sun.javafx.geom.Vec2d;
import java.sql.Date;
import java.sql.ResultSet;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Random;
import java.util.Vector;

public class PayMentPage extends javax.swing.JPanel {

    // data members
    BaseFrame bFrame;
    String busID;
    float total_fare;
    int seats;
    int TextField_Length;
    Vector<String> ticket_id_booked;
    // member functions
    public PayMentPage() {
        initComponents();
        
    }
    public PayMentPage(BaseFrame f,String p,float tot_fare,int s)
    {
        initComponents();
        ticket_id_booked = new Vector<String>();
        bFrame = f;
        busID= p;
        total_fare = tot_fare;
        seats = s;
        TextField_Length = 10;
        DisplayTextFieldInfo();
    }
    public void DisplayTextFieldInfo()
    {
        Total_Fare_TextField.setColumns(TextField_Length);
        Total_Fare_TextField.setText(total_fare+"");
        
        Seats_for_booking_TextField.setColumns(TextField_Length);
        Seats_for_booking_TextField.setText(seats+"");
        
        name_textfield.setColumns(TextField_Length);
        name_textfield.setText("");
        
        Phone_TextField.setColumns(TextField_Length);
        Phone_TextField.setText("");
        
        Address_TextField.setColumns(TextField_Length);
        Address_TextField.setText("");
        
        username_textfield.setColumns(TextField_Length);
        username_textfield.setText("");
        
        password_textfield.setColumns(TextField_Length);
        password_textfield.setText("");
        
        account_number_text_field.setColumns(TextField_Length);
        account_number_text_field.setText("");
        
        
        if(seats == 1)
        {
            pass2_textfield.hide();
            pass3_textfield.hide();
            pass4_textfield.hide();
            pass5_textfield.hide();
            
            pass2.hide();
            pass3.hide();
            pass4.hide();
            pass5.hide();
        }
        else if(seats == 2)
        {
            pass2_textfield.show();
            pass3_textfield.hide();
            pass4_textfield.hide();
            pass5_textfield.hide();
            
            pass2.show();
            pass3.hide();
            pass4.hide();
            pass5.hide();
            
        }
        else if(seats == 3)
        {
            pass2_textfield.show();
            pass3_textfield.show();
            pass4_textfield.hide();
            pass5_textfield.hide();
            
            pass2.show();
            pass3.show();
            pass4.hide();
            pass5.hide();
        }
        else if(seats == 4)
        {
            pass2_textfield.show();
            pass3_textfield.show();
            pass4_textfield.show();
            pass5_textfield.hide();
            
            
            pass2.show();
            pass3.show();
            pass4.show();
            pass5.hide();
        }
        else if(seats == 5)
        {
            
            pass2_textfield.show();
            pass3_textfield.show();
            pass4_textfield.show();
            pass5_textfield.show();
            
            
            pass2.show();
            pass3.show();
            pass4.show();
            pass5.show();
        }
        bFrame.repaint();
        bFrame.revalidate();
        
    }
    public double UniqueTicketIDGenerator(String BID,int seat_number)
    {
        
        double ans=0;
        
        String date;
        String dep_time;
        
        String sql = "select * from bus where bus_id = '"+BID+"';";
        JDBC j = new JDBC();
        Statement stmt = j.getConn();
        try
        {
            ResultSet rs  = stmt.executeQuery(sql);
            rs.next();
            
            date = rs.getString("dateofjourney");
            String temp = date.replaceAll("-","0");
            
            ans = ans + Integer.parseInt(temp);
            
            dep_time = rs.getString("departure_time");
            temp = dep_time.replaceAll(":","0");
            
            ans = ans + Integer.parseInt(temp);
            
            ans = ans + Integer.parseInt(BID)+seat_number;
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        
        return ans%10000;
        
        //return (Integer.parseInt(busID)*seats)%13;
    }
       
    public boolean  ValidateBankDetails(String username,String password,String account_number)
    {
        JDBC j_temp = new JDBC();
        Statement stmt = j_temp.getConn();
        String sql = "select * from bank where username = '"+username+"'"
                + "and account_number = '"+
                account_number+"';";
        try{
            
            ResultSet rs=stmt.executeQuery(sql);
            rs.next();
            
            if(rs.getString("password").equals(password_textfield.getText()))
            {
                if(Float.parseFloat(rs.getString("amount")) > total_fare)
                return true;
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return false;
        
    }
    
    public int calculateSeatNumber(String busID)
    {
        int seat=0;
        try
        {
            JDBC j = new JDBC();
            Statement stmt = j.getConn();
            String sql = "select seats_booked from bus where bus_id = '"+busID+"';";
            ResultSet rs = stmt.executeQuery(sql);
            rs.next();
            seat = Integer.parseInt(rs.getString("seats_booked"));
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
                
        return seat+1;
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        name_textfield = new javax.swing.JTextField();
        Phone_TextField = new javax.swing.JTextField();
        Address_TextField = new javax.swing.JTextField();
        username_textfield = new javax.swing.JTextField();
        password_textfield = new javax.swing.JTextField();
        account_number_text_field = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        Total_Fare_TextField = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        STATUS = new javax.swing.JLabel();
        Seats_for_booking_TextField = new javax.swing.JTextField();
        pass3_textfield = new javax.swing.JTextField();
        pass2_textfield = new javax.swing.JTextField();
        pass4_textfield = new javax.swing.JTextField();
        pass5_textfield = new javax.swing.JTextField();
        pass2 = new javax.swing.JLabel();
        pass3 = new javax.swing.JLabel();
        pass4 = new javax.swing.JLabel();
        pass5 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jButton2 = new javax.swing.JButton();

        jLabel2.setText("Name");

        jLabel3.setText("Phone");

        jLabel4.setText("Address");

        jLabel5.setText("username");

        jLabel6.setText("password");

        jLabel7.setText("account number");

        jLabel8.setText("BANK DETAILS");

        name_textfield.setText("jTextField1");

        Phone_TextField.setText("jTextField1");

        Address_TextField.setText("jTextField1");

        username_textfield.setText("jTextField1");
        username_textfield.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                username_textfieldActionPerformed(evt);
            }
        });

        password_textfield.setText("jTextField2");

        account_number_text_field.setText("jTextField3");

        jButton1.setText("Submit");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel9.setText("Fare ");

        Total_Fare_TextField.setEditable(false);
        Total_Fare_TextField.setText("jTextField1");

        jLabel10.setText("Seats for Booking");

        STATUS.setText(".");

        Seats_for_booking_TextField.setEditable(false);
        Seats_for_booking_TextField.setText("jTextField1");

        pass3_textfield.setText("jTextField1");

        pass2_textfield.setText("jTextField2");

        pass4_textfield.setText("jTextField3");

        pass5_textfield.setText("jTextField4");

        pass2.setText("Passenger2");

        pass3.setText("Passenger3");

        pass4.setText("Passenger4");

        pass5.setText("Passenger5");

        jLabel15.setText("Passenger Details");

        jButton2.setText("View Ticket");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(88, 88, 88)
                                .addComponent(jLabel9))
                            .addComponent(jLabel2, javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3, javax.swing.GroupLayout.Alignment.LEADING))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(Total_Fare_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(33, 33, 33)
                        .addComponent(jLabel10)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(Seats_for_booking_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(36, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel15)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(pass2)
                                    .addComponent(pass3)
                                    .addComponent(pass4)
                                    .addComponent(pass5))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(pass3_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(pass2_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(pass4_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(pass5_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel4)
                                .addGap(26, 26, 26)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(Phone_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(Address_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(name_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel7)
                                .addGap(18, 18, 18)
                                .addComponent(account_number_text_field, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel5)
                                    .addComponent(jLabel6))
                                .addGap(48, 48, 48)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(password_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(username_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addComponent(STATUS, javax.swing.GroupLayout.PREFERRED_SIZE, 49, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel8)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(44, 44, 44)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jButton2)
                                    .addComponent(jButton1))))
                        .addGap(52, 52, 52))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(Total_Fare_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel10)
                    .addComponent(Seats_for_booking_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(jLabel15))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(name_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(username_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel6)
                        .addComponent(password_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel3)
                        .addComponent(Phone_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel4)
                            .addComponent(Address_TextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(pass2_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pass2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(pass3)
                            .addComponent(pass3_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton1))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(pass4_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pass4))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(pass5_textfield, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pass5)
                            .addComponent(jButton2)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel7)
                            .addComponent(account_number_text_field, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(11, 11, 11)
                        .addComponent(STATUS)))
                .addContainerGap(19, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void username_textfieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_username_textfieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_username_textfieldActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
            
           String username = username_textfield.getText();
           String password = password_textfield.getText();
           String account_number = account_number_text_field.getText();
           String passenger_name="";
           
           int max_Seats= Integer.parseInt(Seats_for_booking_TextField.getText());
           
           for(int i=0;i<max_Seats;i++)
           {
               if(ValidateBankDetails(username,password,account_number)==true)
               {
                    STATUS.setText("Authentication Successfull");
                  
                        int new_seatnumber = calculateSeatNumber(busID);
                        double temp = UniqueTicketIDGenerator(busID,new_seatnumber); 
                        String new_ticketID = (int)temp +"" ;
                        
                        ticket_id_booked.add(new_ticketID);
                        
                        if(i==0)
                        {
                            passenger_name = name_textfield.getText();

                            
                        }
                        else if(i==1)
                        {
                            passenger_name = pass2_textfield.getText();
                        }
                        
                        else if(i==2)
                        {
                            passenger_name = pass3_textfield.getText();
                        }
                        
                        else if(i==3)
                        {
                            passenger_name = pass4_textfield.getText();
                        }
                        
                        else if(i==4)
                        {
                            passenger_name = pass5_textfield.getText();
                        }
                        
                        String sql = "insert into ticket (ticket_id,"
                            + "bus_id,person_name,phone,address,seat_no,username,account_number)"
                            + "values ('";
                        sql= sql+ new_ticketID +"','"+busID+"','"+passenger_name+"','"+
                            Phone_TextField.getText()+"','"+Address_TextField.getText()+"','"
                            +new_seatnumber+"','"+username+"','"+account_number+"');";

                     JDBC j = new JDBC();
                     Statement stmt2 = j.getConn();

                     try
                     {
                       
                         stmt2.executeUpdate(sql); // ticket updates

                         sql = "update bank "
                                 +"set amount = amount - "+total_fare+""
                                 + " where username = '"+username+"';";

                        
                         stmt2.executeUpdate(sql);

                         sql = "update bus "
                                 +"set seats_booked = seats_booked +1"+
                                 " where bus_id = '"+busID+"';";

                       
                         stmt2.executeUpdate(sql);

                     }
                     catch(Exception e)
                     {
                        e.printStackTrace();
                     }

               }
                       
               
           
           else
           {
               STATUS.setText("Authentication Error");
           }
       }// end of for loop
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed

        bFrame.remove(this);
        ViewTicketPanel ticket = new ViewTicketPanel(bFrame,ticket_id_booked);
        bFrame.add(ticket);
        bFrame.repaint();
        bFrame.revalidate();
    }//GEN-LAST:event_jButton2ActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField Address_TextField;
    private javax.swing.JTextField Phone_TextField;
    private javax.swing.JLabel STATUS;
    private javax.swing.JTextField Seats_for_booking_TextField;
    private javax.swing.JTextField Total_Fare_TextField;
    private javax.swing.JTextField account_number_text_field;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JTextField name_textfield;
    private javax.swing.JLabel pass2;
    private javax.swing.JTextField pass2_textfield;
    private javax.swing.JLabel pass3;
    private javax.swing.JTextField pass3_textfield;
    private javax.swing.JLabel pass4;
    private javax.swing.JTextField pass4_textfield;
    private javax.swing.JLabel pass5;
    private javax.swing.JTextField pass5_textfield;
    private javax.swing.JTextField password_textfield;
    private javax.swing.JTextField username_textfield;
    // End of variables declaration//GEN-END:variables
}
