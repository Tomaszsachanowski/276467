SELECT * FROM EMPLOYEE1 where EMPLOYEE_ID=197;
SELECT * FROM EMPLOYEE1 where EMPLOYEE_ID=201;

--anonimowy blok do sprawdzenia w WOKRKSEET

DECLARE
   z_p_FIRST_NAME       EMPLOYEE1.FIRST_NAME%type;
   z_p_LAST_NAME        EMPLOYEE1.LAST_NAME%type; 
   z_p_EMAIL            EMPLOYEE1.EMAIL%type;
   z_p_PHONE_NUMBER     EMPLOYEE1.PHONE_NUMBER%type;
   z_p_HIRE_DATE        EMPLOYEE1.HIRE_DATE%type;
   z_p_JOB_ID           EMPLOYEE1.JOB_ID%type;
   z_p_SALARY           EMPLOYEE1.SALARY%type;
   z_p_COMMISSION_PCT   EMPLOYEE1.COMMISSION_PCT%type;
   z_p_MANAGER_ID       EMPLOYEE1.MANAGER_ID%type;
   z_p_DEPARTMENT_ID    EMPLOYEE1.DEPARTMENT_ID%type;
BEGIN
z_p_FIRST_NAME  := 'MIROSLAW';
z_p_LAST_NAME   :='KOWALSKI';
select EMAIL            into z_p_EMAIL            from EMPLOYEE1 where EMPLOYEE_ID=197;
select PHONE_NUMBER     into z_p_PHONE_NUMBER     from EMPLOYEE1 where EMPLOYEE_ID=197;
select HIRE_DATE        into z_p_HIRE_DATE        from EMPLOYEE1 where EMPLOYEE_ID=197;
select JOB_ID           into z_p_JOB_ID           from EMPLOYEE1 where EMPLOYEE_ID=197;
select SALARY           into z_p_SALARY           from EMPLOYEE1 where EMPLOYEE_ID=197;
select COMMISSION_PCT   into z_p_COMMISSION_PCT   from EMPLOYEE1 where EMPLOYEE_ID=197;
select MANAGER_ID       into z_p_MANAGER_ID       from EMPLOYEE1 where EMPLOYEE_ID=197;
select DEPARTMENT_ID    into z_p_DEPARTMENT_ID    from EMPLOYEE1 where EMPLOYEE_ID=197;
-- spawdzenie porawnosci wstawiania do tabeli
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,z_p_SALARY,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
--co gdy watosci sa null
--InsertEmployee(null,null,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,z_p_SALARY,z_p_COMMISSION_PCT,null,null);
--co gdy watosci sa null
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,null,null,null,null,null,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
--co gdy zly manager
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,z_p_SALARY,z_p_COMMISSION_PCT,999,z_p_DEPARTMENT_ID);
--co gdy zly depratament
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,z_p_SALARY,z_p_COMMISSION_PCT,z_p_MANAGER_ID,99);
--co gdy zla kod stanowiska
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,'CO_ZLE',z_p_SALARY,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
-- co gdy pensja nie z tego zakresu
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,-234,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
--InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,z_p_HIRE_DATE,z_p_JOB_ID,100000,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
--co gdy zla data 2020.11.23
InsertEmployee(z_p_FIRST_NAME,z_p_LAST_NAME,z_p_EMAIL,z_p_PHONE_NUMBER,'20/11/23',z_p_JOB_ID,z_p_SALARY,z_p_COMMISSION_PCT,z_p_MANAGER_ID,z_p_DEPARTMENT_ID);
END;	
SELECT * FROM EMPLOYEE1 where EMPLOYEE_ID>320;
DELETE FROM employee1 WHERE employee_id >= 304;
