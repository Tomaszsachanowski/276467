create or replace PROCEDURE InsertEmployee
( p_FIRST_NAME       EMPLOYEE1.FIRST_NAME%type     DEFAULT null
, p_LAST_NAME        EMPLOYEE1.LAST_NAME%type      DEFAULT null
, p_EMAIL            EMPLOYEE1.EMAIL%type          DEFAULT null
, p_PHONE_NUMBER     EMPLOYEE1.PHONE_NUMBER%type   DEFAULT null
, p_HIRE_DATE        EMPLOYEE1.HIRE_DATE%type      DEFAULT null
, p_JOB_ID           EMPLOYEE1.JOB_ID%type         DEFAULT null
, p_SALARY           EMPLOYEE1.SALARY%type         DEFAULT null
, p_COMMISSION_PCT   EMPLOYEE1.COMMISSION_PCT%type DEFAULT null
, p_MANAGER_ID       EMPLOYEE1.MANAGER_ID%type     DEFAULT null
, p_DEPARTMENT_ID    EMPLOYEE1.DEPARTMENT_ID%type  DEFAULT null)  

IS
--employee_id zostanie sam wygenerowany jako najwyzszy dostêpny numer
   v_EMPLOYEE_ID      EMPLOYEE1.EMPLOYEE_ID%type      ;
   v_FIRST_NAME       EMPLOYEE1.FIRST_NAME%type       :=p_FIRST_NAME;
   v_LAST_NAME        EMPLOYEE1.LAST_NAME%type        :=p_LAST_NAME; 
   v_EMAIL            EMPLOYEE1.EMAIL%type            :=p_EMAIL;
   v_PHONE_NUMBER     EMPLOYEE1.PHONE_NUMBER%type     :=p_PHONE_NUMBER;
   v_HIRE_DATE        EMPLOYEE1.HIRE_DATE%type        :=p_HIRE_DATE;
   v_JOB_ID           EMPLOYEE1.JOB_ID%type           :=p_JOB_ID;
   v_SALARY           EMPLOYEE1.SALARY%type           :=p_SALARY;
   v_COMMISSION_PCT   EMPLOYEE1.COMMISSION_PCT%type   :=p_COMMISSION_PCT;
   v_MANAGER_ID       EMPLOYEE1.MANAGER_ID%type       :=p_MANAGER_ID;
   v_DEPARTMENT_ID    EMPLOYEE1.DEPARTMENT_ID%type    :=p_DEPARTMENT_ID;
--dodatkowe zmienne pomocne przy sprawdzeniu porawnosic danych  
   v_licznik number;
   v_pensja number;
BEGIN 
--znalenienie numeru id dla nowego pracownikaa---
  select MAX(EMPLOYEE_ID)+1 INTO v_EMPLOYEE_ID from EMPLOYEE1;
  
--zalozenie moje ze jak jakas dana jest nie wasciwa z wytycznymi to zostanie ustawiona wartosc domyslna
-- te wartosci sa uzytkownika 201 wiec jak jakas wartosc jest nei odpowiednia to bedzie identyczna co 
--dla rekordu pracownika 201
--sprawdzanie czy wszsytkie parametru sa nie null
  IF p_FIRST_NAME  is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    v_FIRST_NAME  := 'DOMYSLNY_imie';
    end if;

  IF p_LAST_NAME is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    v_LAST_NAME  := 'DOMYSLNY_nazwisko';
  end IF;
  IF p_EMAIL is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select EMAIL            into v_EMAIL                  from EMPLOYEE1 where EMPLOYEE_ID=201;  
  end IF;
    IF p_PHONE_NUMBER is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select PHONE_NUMBER     into v_PHONE_NUMBER            from EMPLOYEE1 where EMPLOYEE_ID=201;  
   end IF;
   IF v_HIRE_DATE is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select HIRE_DATE        into v_HIRE_DATE              from EMPLOYEE1 where EMPLOYEE_ID=201;  
   end IF;
   IF v_JOB_ID is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select JOB_ID           into v_JOB_ID                 from EMPLOYEE1 where EMPLOYEE_ID=201;  
   end IF;
   IF v_SALARY is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select SALARY           into v_SALARY                 from EMPLOYEE1 where EMPLOYEE_ID=201;  
  end IF;
  IF v_COMMISSION_PCT is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select COMMISSION_PCT  into v_COMMISSION_PCT          from EMPLOYEE1 where EMPLOYEE_ID=201;  
  end IF;
  IF v_MANAGER_ID is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select MANAGER_ID      into v_MANAGER_ID              from EMPLOYEE1 where EMPLOYEE_ID=201;  
  end IF;
  IF v_DEPARTMENT_ID is null THEN
    dbms_output.put_line('WARTOSC JEST PUSTA zostanie ustawiona watosc domyslna');
    select DEPARTMENT_ID  into v_DEPARTMENT_ID            from EMPLOYEE1 where EMPLOYEE_ID=201;  
  end IF;
   ----------------------------------------------------------------------------------------------- 
    ----------------------------------------------------------------------------------------------
 --wartoci niewlasciwe 

  --zly manger-----------------------------------------------------------
    select COUNT(*) INTO v_licznik from EMPLOYEE1 where EMPLOYEE_ID=v_MANAGER_ID; 
    if v_licznik = 0 then
    dbms_output.put_line('BRAK TAKIEGO MENAGERA zostanie ustawiona watosc domyslna');
    select MANAGER_ID  into v_MANAGER_ID            from EMPLOYEE1 where EMPLOYEE_ID=201;  
    end IF;
    --zly departament--------------------------------------------------
    select COUNT(*) INTO v_licznik from DEPARTMENTS1 where DEPARTMENT_ID = v_DEPARTMENT_ID; 
    if v_licznik = 0 then
    dbms_output.put_line('BRAK TAKIEGO DEPATAMENTU zostanie ustawiona watosc domyslna');
    select DEPARTMENT_ID  into v_DEPARTMENT_ID            from EMPLOYEE1 where EMPLOYEE_ID=201;  
    end IF;
    --zly kod stanowiska --------------------------------------------------------------------
    select COUNT(*) INTO v_licznik from JOBS1 where JOB_ID = v_JOB_ID; 
    if v_licznik = 0 then
    dbms_output.put_line('BRAK TAKIEGO KODU STANOWISKA zostanie ustawiona watosc domyslna');
    select JOB_ID  into v_JOB_ID            from EMPLOYEE1 where EMPLOYEE_ID=201;  
    end IF;
    --pensja z spoza zakresu---------------------------------------------------------
    
    SELECT MIN_SALARY into v_pensja FROM JOBS1 WHERE JOB_ID = v_JOB_ID;
    if v_SALARY< v_pensja then
    dbms_output.put_line('PENSJA ZA MA£A zostanie ustawiona watosc domyslna');
    select (MIN_SALARY+MAX_SALARY)/2  into v_SALARY            from JOBS1 where JOB_ID = v_JOB_ID;  
    end IF;
    SELECT MAX_SALARY into v_pensja FROM JOBS1 WHERE JOB_ID = v_JOB_ID;
    if v_SALARY > v_pensja then
    dbms_output.put_line('PENSJA ZA DUZA zostanie ustawiona watosc domyslna');
    select (MIN_SALARY+MAX_SALARY)/2  into v_SALARY            from JOBS1 where JOB_ID = v_JOB_ID;  
    end IF;
    
    
  --zla data---------------------------------------------------------------------------------------
  if v_HIRE_DATE> current_date then
      dbms_output.put_line('DATA zla zostanie ustawiona watosc domyslna');
    select HIRE_DATE  into v_HIRE_DATE            from EMPLOYEE1 where EMPLOYEE_ID=201;  
    end IF;
    
------------------------------------------------------------------------------------------
--wstawienie rekordu-------------

  INSERT INTO EMPLOYEE1(EMPLOYEE_ID,  FIRST_NAME, LAST_NAME,  EMAIL
    , PHONE_NUMBER, HIRE_DATE,  JOB_ID, SALARY, COMMISSION_PCT  
    , MANAGER_ID,DEPARTMENT_ID) 
      VALUES(v_EMPLOYEE_ID, v_FIRST_NAME, v_LAST_NAME,  v_EMAIL
      , v_PHONE_NUMBER, v_HIRE_DATE,  v_JOB_ID, v_SALARY
      , v_COMMISSION_PCT, v_MANAGER_ID, v_DEPARTMENT_ID );

END InsertEmployee;