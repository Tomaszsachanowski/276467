package model;

import java.math.BigDecimal;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;


public class EmployeeCRUD {
	private EntityManagerFactory entityManagerFactory;

	EmployeeCRUD () { 
	entityManagerFactory =  Persistence.createEntityManagerFactory("FirstJPA");
	}

	
	
	public void createEmployee(Employee1 employee) {
	EntityManager entityManager =	entityManagerFactory.createEntityManager();
	entityManager.getTransaction().begin();
	entityManager.persist(employee);
	entityManager.getTransaction().commit();
	entityManager.close();
	}
	public void deleteEmployee(int id){
		EntityManager entityManager = entityManagerFactory.createEntityManager();
		entityManager.getTransaction().begin();
		Employee1 employee = entityManager.find(Employee1.class, new BigDecimal(id));
		entityManager.remove(employee);
		entityManager.getTransaction().commit();
		entityManager.close();
}	
	
	public void readEmployee(int id) {
		EntityManager entityManager = entityManagerFactory.createEntityManager();
		entityManager.getTransaction().begin();
		Employee1 employee = entityManager.find(Employee1.class, new BigDecimal(id));
		System.out.println("\n"
				+ "ID: " + employee.getJobId().toString()
				+ "\nFirst_Name: " + employee.getFirstName()
				+ "\nLast_Name: " + employee.getLastName()
				+ "\nEmployee_ID: "+ employee.getEmployeeId()
				+ "\nEmail: " + employee.getEmail()
				+ "\nDept_ID: " + employee.getDepartmentId().toString()
				+ "\nDate: " + employee.getHireDate().toString()
				+ "\nJob_ID: " + employee.getJobId()
				+ "\nSalary: " + employee.getSalary().toString()
				+ "\nPhone: " + employee.getPhoneNumber().toString()
				
				);
		
		
		entityManager.getTransaction().commit();
		entityManager.close();
		
		
	}
	public void readEmployee(Employee1 employee) {
		EntityManager entityManager = entityManagerFactory.createEntityManager();
		entityManager.getTransaction().begin();
		System.out.println("\n"
				+ "ID: " + employee.getJobId().toString()
				+ "\nFirst_Name: " + employee.getFirstName()
				+ "\nLast_Name: " + employee.getLastName()
				+ "\nEmployee_ID: "+ employee.getEmployeeId()
				+ "\nEmail: " + employee.getEmail()
				+ "\nDept_ID: " + employee.getDepartmentId().toString()
				+ "\nDate: " + employee.getHireDate().toString()
				+ "\nJob_ID: " + employee.getJobId()
				+ "\nSalary: " + employee.getSalary().toString()
				+ "\nPhone: " + employee.getPhoneNumber().toString()
				);
		
		entityManager.getTransaction().commit();
		entityManager.close();
		
		
	}
	
	public Employee1 getEmployeeByEmployeeId(int id) {
		EntityManager entityManager = entityManagerFactory.createEntityManager();
		entityManager.getTransaction().begin();
		Employee1 employee = entityManager.find(Employee1.class, new BigDecimal(id));
		entityManager.getTransaction().commit();
		entityManager.close();
		return employee;
		
	}
	public void updateSalary(int id){
		EntityManager entityManager = entityManagerFactory.createEntityManager();
		entityManager.getTransaction().begin();
		Employee1 employee = entityManager.find(Employee1.class, new BigDecimal(id));
		employee.setSalary(employee.getSalary().multiply(new BigDecimal(1.1)));
		entityManager.getTransaction().commit();
		entityManager.close();
}
	@Override
	public void finalize() {
		entityManagerFactory.close();
}
}
