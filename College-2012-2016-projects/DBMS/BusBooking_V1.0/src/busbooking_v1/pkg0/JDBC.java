package busbooking_v1.pkg0;

import java.sql.*;

public class JDBC {
    // data members
        public Connection conn;
        public Statement s;

    // member functions
    public JDBC() {
    }

    public JDBC(Connection conn, Statement s) {
        this.conn = conn;
        this.s = s;
    }
    
    public Statement getConn()
    {
        try
        {
            Class.forName("org.postgresql.Driver");
            conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","iostream");
            s = conn.createStatement();
           
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return s;
    }
    
    public void CloseAll()
    {
        try
        {
            conn.close();
            s.close();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
}
