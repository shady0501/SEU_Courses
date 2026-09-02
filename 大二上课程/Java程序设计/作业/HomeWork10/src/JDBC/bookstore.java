package JDBC;

import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class bookstore {
	public void setBookstore() throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.cj.jdbc.Driver");
		
		String dbURL = "jdbc:mysql://localhost:3306/" + "MyDB?user=root&password=password";
		Connection connection = DriverManager.getConnection(dbURL);
		
		String sql = "INSERT INTO tab (name, sales, date) VALUES (?, ?, ?)";
		PreparedStatement pstmt = connection.prepareStatement(sql);

		pstmt.setString(1, "Los Angeles");
		pstmt.setInt(2, 1500);
		Date date = Date.valueOf("1999-01-09");
		pstmt.setDate(3, date);
		pstmt.addBatch();
		pstmt.clearParameters();
		
		pstmt.setString(1, "San Diego");
		pstmt.setInt(2, 250);
		date = Date.valueOf("1999-01-07");
		pstmt.setDate(3, date);
		pstmt.addBatch();
		pstmt.clearParameters();

		pstmt.setString(1, "Los Angeles");
		pstmt.setInt(2, 300);
		date = Date.valueOf("1999-01-08");
		pstmt.setDate(3, date);
		pstmt.addBatch();
		pstmt.clearParameters();

		pstmt.setString(1, "Boston");
		pstmt.setInt(2, 700);
		date = Date.valueOf("1999-01-08");
		pstmt.setDate(3, date);
		pstmt.addBatch();
		pstmt.clearParameters();
		
		pstmt.executeBatch();
		pstmt.clearBatch();
		
		pstmt.close();
		connection.close();
	}
	
	public void show() throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.cj.jdbc.Driver");

		String dbURL = "jdbc:mysql://localhost:3306/" + "MyDB?user=root&password=password";
		Connection connection = DriverManager.getConnection(dbURL);

		String sql = "SELECT * FROM tab";
		PreparedStatement pstmt = connection.prepareStatement(sql);
		ResultSet resultSet = pstmt.executeQuery();
		
		String[] str = {"store_name    ","Sales    ","Date"};
		int length = 0;
		for(String head : str) {
			System.out.print(head);
			length += head.length();
		}
		System.out.print("\n");
		for(int i=0; i<length; ++i) {
			System.out.print("-");
		}
		System.out.print("\n");

		while(resultSet.next()) {
			String name = resultSet.getString("name");
			int sales = resultSet.getInt("sales");
			Date date = resultSet.getDate("date");
			
			System.out.printf("%-"+str[0].length()+"s%-"+str[1].length()
					+"d%-"+str[2].length()+"s%n",name, sales, date);
		}
		
		resultSet.close();
		pstmt.close();
		connection.close();
	}
	
	public void delete() throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.cj.jdbc.Driver");

		String dbURL = "jdbc:mysql://localhost:3306/" + "MyDB?user=root&password=password";
		Connection connection = DriverManager.getConnection(dbURL);

		String sql = "DELETE FROM tab";
		PreparedStatement pstmt = connection.prepareStatement(sql);
		pstmt.executeUpdate();
		
		pstmt.close();
		connection.close();
	}

	public static void main(String[] args) {
		bookstore bst = new bookstore();
		try {
			bst.delete();
			bst.setBookstore();
			bst.show();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
