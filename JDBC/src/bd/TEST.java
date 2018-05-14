package bd;
import dal.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Vector;

public class TEST {

	public static void main(String[] args) {
		EmployeesDAL dal = new EmployeesDAL();
		OraConn.open();
//wypisanie zawartosci tabeli		
		Vector <Employee> wektor=dal.getEmployees();
		for(Employee temp:wektor)
			System.out.println(temp.getFirstName()+" "+" "+temp.getLastName()+" "+temp.getPhoneNumber()+" "+temp.getHireDate()+" "+temp.getEmployeeId()+" " + temp.getSalary()+"\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//stworzenie nowego pracownika	
					Employee emp3=dal.getEmployeeByEmployeeId(195); //pobranei dnaych od pracownika 195
Employee emp2=new Employee(303);
							//dal.delEmployee(emp2);
	emp2.setFirstName("ADAM");
	emp2.setLastName("KOWALCZYK");
	emp2.setEmail(emp3.getEmail());
	emp2.setPhoneNumber(emp3.getPhoneNumber());
	emp2.setHireDate(emp3.getHireDate());
	emp2.setJobId(emp3.getJobId());
	emp2.setSalary(emp3.getSalary());
	emp2.setManagerId(emp3.getManagerId());
	emp2.setDepartmentId(emp3.getDepartmentId());
				dal.insertEmployee(emp2);
	//wypisnaie nowej zawartosic tabeli z nowym rekordem
System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
wektor=dal.getEmployees();
for(Employee temp:wektor)
	System.out.println(temp.getFirstName()+" "+" "+temp.getLastName()+" "+temp.getPhoneNumber()+" "+temp.getHireDate()+" "+temp.getEmployeeId()+" " + temp.getSalary()+"\n");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//usuniecie nowostworzonego pracownika
			dal.delEmployee(emp2);
System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
wektor=dal.getEmployees();
for(Employee temp:wektor)
System.out.println(temp.getFirstName()+" "+" "+temp.getLastName()+" "+temp.getPhoneNumber()+" "+temp.getHireDate()+" "+temp.getEmployeeId()+" " + temp.getSalary()+"\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// uaktualnienie dnaych w pracowniku 302
	emp3=dal.getEmployeeByEmployeeId(302);//pobranie dnaych od pracownika 302
				emp3.setSalary(9966);
				emp3.setLastName("SACH");
				dal.updateEmployee(emp3);
	System.out.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	wektor=dal.getEmployees();
	for(Employee temp:wektor)
	System.out.println(temp.getFirstName()+" "+" "+temp.getLastName()+" "+temp.getPhoneNumber()+" "+temp.getHireDate()+" "+temp.getEmployeeId()+" " + temp.getSalary()+"\n");

	OraConn.close();

	}

}
