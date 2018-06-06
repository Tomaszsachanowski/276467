CREATE OR REPLACE TYPE VARIANCJA  
AS OBJECT (
v_counter NUMBER,
v_suma NUMBER,
v_kwadrat NUMBER,

STATIC FUNCTION ODCIAggregateInitialize
  ( sctx IN OUT VARIANCJA) RETURN NUMBER,
MEMBER FUNCTION ODCIAggregateIterate
  ( self IN OUT VARIANCJA,value IN number) RETURN NUMBER,
MEMBER FUNCTION ODCIAggregateTerminate
  (self IN VARIANCJA, returnValue OUT number, flags IN number) RETURN NUMBER,
MEMBER FUNCTION ODCIAggregateMerge
  (self IN OUT VARIANCJA,ctx2 IN VARIANCJA) RETURN NUMBER
);
/
CREATE OR REPLACE TYPE BODY VARIANCJA  AS
STATIC FUNCTION ODCIAggregateInitialize
  ( sctx IN OUT VARIANCJA) RETURN NUMBER IS 
  BEGIN
      --dbms_output.put_line('NON-NULL INIT');
      sctx := VARIANCJA(0, 0, 0); 
    RETURN ODCIConst.Success;
  END;
MEMBER FUNCTION ODCIAggregateIterate
  ( self IN OUT VARIANCJA, value IN number) RETURN NUMBER IS
  BEGIN
    DBMS_OUTPUT.PUT_LINE('Iterate ' || TO_CHAR(value));
    IF value IS NULL THEN 
        /* Will never happen */
        DBMS_OUTPUT.PUT_LINE('Null on iterate');
    END IF;
    self.v_suma := self.v_suma + value;
    self.v_kwadrat := self.v_kwadrat + value*value;
    self.v_counter := self.v_counter + 1;
    RETURN ODCIConst.Success;
  END;
MEMBER FUNCTION ODCIAggregateTerminate
  ( self IN VARIANCJA, returnValue OUT number, flags IN number) RETURN NUMBER IS
  BEGIN
   -- dbms_output.put_line('Terminate ' || to_char(flags) || to_char(self.runningsum));
    IF self.v_counter <> 0 AND self.v_counter <> 1 THEN
    returnvalue := (v_kwadrat-(v_suma*v_suma)/v_counter)/(v_counter-1);     
    ELSE
      /* It *is* possible to have an empty group, so avoid divide-by-zero. */
      returnValue := 0;
    END IF;
    RETURN ODCIConst.Success;
  END;
MEMBER FUNCTION ODCIAggregateMerge
  (self IN OUT VARIANCJA, ctx2 IN VARIANCJA) RETURN NUMBER IS
  BEGIN
  self.v_suma := self.v_suma + ctx2.v_suma; 
  self.v_counter := self.v_counter + ctx2.v_counter; 
  self.v_kwadrat := self.v_kwadrat + ctx2.v_kwadrat; 
    RETURN ODCIConst.Success;
  END;
END;
/
