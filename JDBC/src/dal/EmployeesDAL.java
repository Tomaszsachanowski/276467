package dal;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.format.DateTimeFormatter;
import java.util.Vector;
import bd.Employee;
import bd.OraConn;
import java.sql.Statement;



public class EmployeesDAL {

	
	private SQLException ex;
	
	public SQLException getSQLException() { 
		return ex; 
	}
	public EmployeesDAL() { }
//############################################################################
	private Employee rs2Employee(ResultSet resultSet){
		Employee emp = null;
		try {
			int col = 1;
			emp = new Employee(resultSet.getInt(col++));
			emp.setFirstName(resultSet.getNString(col++));
			emp.setLastName(resultSet.getNString(col++));
			emp.setEmail(resultSet.getNString(col++));
			emp.setPhoneNumber(resultSet.getNString(col++));
			emp.setHireDate(resultSet.getDate(col++).toLocalDate());
			emp.setJobId(resultSet.getNString(col++));
			emp.setSalary(resultSet.getInt(col++));
			col++;
			emp.setManagerId(resultSet.getInt(col++));
			emp.setDepartmentId(resultSet.getInt(col++));
		}
		catch (SQLException ex ) {
			this.ex = ex;
			OraConn.close();
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
		}
		return emp;
	}
//############################################################################	
	public Vector <Employee> getEmployees() {
		
		Vector <Employee> employees = new Vector <Employee>();
		try (Statement statement = OraConn.getConnection().createStatement();) {
		String query = "SELECT * FROM EMPLOYEE1";
		ResultSet resultSet = statement.executeQuery(query);
		while (resultSet.next()) {
			employees.add( rs2Employee(resultSet)); }
		}
		catch (SQLException ex ) { 
			System.out.println(ex);
			OraConn.close(); 
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			}
		return employees;
	}
//#################################################################################
	public Employee getEmployeeByEmployeeId(int EmployeeId){
		
		Employee emp = null;
		try (Statement statement = (Statement) OraConn.getConnection().createStatement(); ){
			
			String query = "SELECT * FROM EMPLOYEE1 "
					+ "WHERE EMPLOYEE_ID = " + EmployeeId;
			ResultSet resultSet = statement.executeQuery(query);
			resultSet.next();
			emp = rs2Employee(resultSet);
			
			
		}
		catch (SQLException ex ) { 
			System.out.println(ex); 
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			OraConn.close(); }
		
		return emp;
	}
//#############################################################################
	public void insertEmployee(Employee emp){
		DateTimeFormatter dtf =
		DateTimeFormatter.ofPattern("yyyyMMdd");
		String hireDate = dtf.format(emp.getHireDate());
		try (Statement statement = OraConn.getConnection().createStatement(); ){
			String query = //"INSERT INTO EMPLOYEE1"
					"Insert into EMPLOYEE1 (EMPLOYEE_ID,FIRST_NAME,LAST_NAME,EMAIL,PHONE_NUMBER,HIRE_DATE,JOB_ID,SALARY,COMMISSION_PCT,MANAGER_ID,DEPARTMENT_ID)"
					+ " values ('" + emp.getEmployeeId() 
					+ "','" + emp.getFirstName()
					+ "','" + emp.getLastName()
					+ "','" + emp.getEmail()
					+ "','" + emp.getPhoneNumber()
					+ "',to_date('" + hireDate + "','yyyyMMdd')"
					+ ",'" + emp.getJobId()
					+ "','" + emp.getSalary()
					+ "',"+null //"','" + emp.getCommissionPCT()
					+ ",'" + emp.getManagerId()
					+ "','" + emp.getDepartmentId() + "')";
			statement.executeUpdate(query);
			OraConn.getConnection().commit();
		} catch ( SQLException ex ) { 
			System.out.println(ex);
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			OraConn.close(); 
			}
		}
	
	
	public void delEmployee(Employee emp){
		try (Statement statement = OraConn.getConnection().createStatement();){
			String query = "DELETE FROM EMPLOYEE1 "
					+ "WHERE EMPLOYEE_ID = " + emp.getEmployeeId();
			statement.executeUpdate(query);
			OraConn.getConnection().commit();
		} catch ( SQLException ex ) { 
			System.out.println(ex); 
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			OraConn.close(); 
		}
	}
	

//##########################################################3
	
	public int updateEmployee(Employee emp) {
		try (Statement statement =
				OraConn.getConnection().createStatement(); ) {
			DateTimeFormatter dtf =
			DateTimeFormatter.ofPattern("yyyyMMdd");
			String hireDate = dtf.format(emp.getHireDate());
			
			String query = "UPDATE EMPLOYEE1 SET "
					+ "LAST_NAME ='" + emp.getLastName() + "', "
					+ "FIRST_NAME = '" + emp.getFirstName() + "', "
					+ "EMAIL = '" + emp.getEmail() + "', "
					+ "PHONE_NUMBER = '" + emp.getPhoneNumber() + "', "
					+ "SALARY = '" + emp.getSalary() + "', "
					+ "MANAGER_ID = '" + emp.getManagerId() + "', "
					+ "DEPARTMENT_ID = '" + emp.getDepartmentId() + "', "
					+ "HIRE_DATE = to_date('" + hireDate + "', 'yyyyMMdd') "
					+ "WHERE "
					+ "EMPLOYEE_ID = " + emp.getEmployeeId();
			int affectedRows = statement.executeUpdate(query);
			OraConn.getConnection().commit();
			return affectedRows;
		}
		catch (SQLException ex ) { 
			this.ex = ex;
			System.out.println(ex.getClass().getCanonicalName());
			System.out.println(ex.getStackTrace()[2].getLineNumber());
			return 0;}
}	
}
