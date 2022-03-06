
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author LENOVO
 */
public class db {
    public static void main(String[] args) throws Exception {
        Class.forName("com.mysql.jdbc.Driver").newInstance();
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/testing?zeroDateTimeBehavior=convertToNull", "root", "");
        int[] s1 = new int[10],s2 = new int[10];
        String[] date = new String[10];
        Statement st = con.createStatement();
        String sql = ("SELECT timestamp,sensor1,c2 FROM pollution ORDER BY timestamp DESC LIMIT 10;");
        ResultSet rs = st.executeQuery(sql);
        int i=9;
        while(rs.next()) {  
            s1[i] = rs.getInt("sensor1");
            s2[i] = rs.getInt("sensor2");
            date[i] = rs.getString("timestamp");
            System.out.println(" "+s1[i]+" "+s2[i]+" "+date[i].split(" ")[1].split("\\.")[0]);
            i--;
        }

        con.close();
    }
}
