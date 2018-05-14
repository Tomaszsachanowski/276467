package model;

import java.math.BigDecimal;

public class CRUD {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		EmployeeCRUD employeeCRUD = new EmployeeCRUD();
	
		
	//	employeeCRUD.readEmployee(301);
	//employeeCRUD.updateSalary(301);
employeeCRUD.readEmployee(employeeCRUD.getEmployeeByEmployeeId(302));

Employee1 emp=new Employee1(employeeCRUD.getEmployeeByEmployeeId(197),new BigDecimal(303));
	emp.setFirstName("Dominik");
	emp.setLastName("Młynek");
	employeeCRUD.createEmployee(emp);
	employeeCRUD.readEmployee(303);
	employeeCRUD.readEmployee(303);
//employeeCRUD.deleteEmployee(303);
		//employeeCRUD.deleteEmployee(id);
		//employeeCRUD.finalize();

	}

}
