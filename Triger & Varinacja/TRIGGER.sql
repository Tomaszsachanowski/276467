create or replace TRIGGER TRIGGER1 
BEFORE UPDATE OR INSERT ON   EMPLOYEE1
For EACH ROW

WHEN (NEW.SALARY<0)
BEGIN
RAISE_APPLICATION_ERROR(-20999,'Nie mozna wstaawic ujemnej pensji!');

END;