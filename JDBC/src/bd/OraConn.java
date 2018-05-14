package bd;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class OraConn {
	
	
	private static Connection connection;
	private static String oracleURL = "jdbc:oracle:thin:@ora3.elka.pw.edu.pl:1521:ora3inf";
	private static String username="tsachano";
	private static String userpasword="tsachano";
	
	public OraConn() {}
	public static Connection getConnection(){ return connection; }
	public static void open(){
		try {
			
		Class.forName("oracle.jdbc.driver.OracleDriver");
			
		}catch (ClassNotFoundException ex) {
			
				System.out.println("Brak sterownika Oracle JDBC.");
				System.out.println(ex.getClass().getCanonicalName());
				System.out.println(ex.getStackTrace()[2].getLineNumber());
				return;
		}
		
		System.out.println("Sterownik Oracle JDBC został zarejestrowany.");
		connection= null;
			
		try {
			
			connection = DriverManager.getConnection(oracleURL, username, userpasword);
		
		}catch (SQLException ex) {
			
			System.out.println("Błąd łączenia z bazą!"+ ex.getMessage());
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			return;
			
		}
	}
	
	
	
	public static  void close(){
		try {
			
			System.out.println("Połączeniejest otwarte.");
			connection.close();
			System.out.println("Połączenie jest zamknięte.");
			
		}catch (SQLException ex) {
			
			ex.printStackTrace();
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			return;
			
		}
	}
	
}
