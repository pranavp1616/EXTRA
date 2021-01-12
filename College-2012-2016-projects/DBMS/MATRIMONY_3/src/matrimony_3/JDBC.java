/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package matrimony_3;
import java.sql.*;

public class JDBC {

    public Connection conn;
    public Statement s;
    Statement getConn()
    {
       
        
        try
        {
        Class.forName("org.postgresql.Driver");
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","iostream");
        s=conn.createStatement();
        
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return s;
        
    }
    public void closeAll()
    {
        try
        {
            conn.close();
            s.close();
        }
        catch(Exception e)
        {
            
        }
    }
    public  JDBC()
    {
        
    }
}
