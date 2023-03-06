TYPE
	bramaTyp : 	STRUCT  (*Struktura danych bramy wjazdowej*)
		diGateOpen : BOOL;
		diGateClose : BOOL;
		diEStop : BOOL:=TRUE;
		diSafetySensor : BOOL:=TRUE; 
		diGateClosed : BOOL;
		diGateOpened : BOOL;
		diTemperatura : BOOL;
		
		doOpenGate : BOOL;
		doCloseGate : BOOL;
		doLampa : BOOL;
		
		lampa: BOOL;
		
	END_STRUCT;
END_TYPE