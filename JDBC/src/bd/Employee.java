package bd;
import java.time.LocalDate;

public class Employee {

		private int employeeId;
		private String firstName;
		private String lastName;
		private String email;
		private int salary;
		private int commissionPCT;
		private int managerId;
		private int departmentId;
		private String phoneNumber;
		private LocalDate hireDate;
		private String jobId;

	
	public Employee() { }
	
	public Employee(int employeeId) {
		this.employeeId = employeeId;
	}

	public int getEmployeeId() {
		return employeeId;
	}
	public String getLastName() {
		return lastName;
	}

	public String getFirstName() {
		return firstName;
	}
	public String getEmail() {
		return email;
	}
	public String getPhoneNumber() {
		return phoneNumber;
	}

	public LocalDate getHireDate() {
		return hireDate;
	}
	public String getJobId() {
		return jobId;
	}

	public int getCommissionPCT() {
		return commissionPCT;
	}

	public int getManagerId() {
		return managerId;
	}

	public int getSalary() {
		return salary;
	}

	public int getDepartmentId() {
		return departmentId;
	}

//#######################################################################	
	
	public void setEmployeeId(int employeeId) {
		this.employeeId = employeeId;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}


	public void setEmail(String email) {
		this.email = email;
	}


	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}

	public void setHireDate(LocalDate hireDate) {
		this.hireDate = hireDate;
	}


	public void setJobId(String jobId) {
		this.jobId = jobId;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public void setCommissionPCT(int commissionPCT) {
		this.commissionPCT = commissionPCT;
	}

	public void setManagerId(int managerId) {
		this.managerId = managerId;
	}

	public void setDepartmentId(int departmentId) {
		this.departmentId = departmentId;
	}
	

}
