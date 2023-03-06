TYPE
(*	OperatorTyp : STRUCT
		diStart : BOOL;
		diStop : BOOL;
		diReset : BOOL;
		doAktywny : BOOL;
		doPrawo : BOOL;
		doLewo : BOOL;
	END_STRUCT;*)
	
	GateTyp : STRUCT
		diOtwarte : BOOL;
		diZamkniete : BOOL;
		doZasilanie : BOOL;
		doPrawoLewo : BOOL;
		doLampa : BOOL;
		uiOtwarte : BOOL;
		uiZamkniete : BOOL;
		uiZasilanie : BOOL;
		uiPrawoLewo : BOOL;
		uiLampa : BOOL;
		Pilot : PilotTyp;
		diKrancowkaLewo : BOOL;
		diKrancowkaPrawo : BOOL;
		SilnikDC : SilnikDCTyp;
	END_STRUCT;
	
	SilnikDCTyp : STRUCT
		aoPWM : INT;
		PeriodDuration : UINT;
	END_STRUCT;
	
	EnkoderABTyp : STRUCT (*enkoder do suwnicy, jak chcemy np przeskalowac pozycje na milimetry*)
		aiPozycja : DINT;
		uiPozycja : REAL;
		uiTryb : USINT; (**ustawiæ na 195*)
	END_STRUCT;
	
	PilotTyp : STRUCT
		diOtworz : BOOL;
		diZamknij : BOOL;
		doStanBramy : BOOL;
		uiOtwieranie : BOOL;
		uiZamykanie : BOOL;
		aiZadajnik : ARRAY[1..2] OF INT;
	END_STRUCT;
	
	HouseTyp : STRUCT
		Brama : GateTyp;
	END_STRUCT;
	
	
	StatemachineTyp:
		(
		WAIT_FOR_ACTION :=1,
		HOMING :=2,
		GO_TO_START :=3,
		WAIT_FOR_ITEM :=4,
		GO_TO_END :=5,
		WAIT_FOR_OUT :=6,
		FAILURE :=7,
		GO_TO_START0:=8
	);
	

	
	SuwnicaTyp : STRUCT
		diStartLS_NC : BOOL;
		diStartLS_NO : BOOL;
		diEndLS_NC : BOOL;
		diEndLS_NO : BOOL;
		diItemStart : BOOL;
		diItemEnd : BOOL;
		SilnikDC : SilnikDCTyp;
		Enkoder : EnkoderABTyp;
		Operator : OperatorTyp;
	(*	aiPozycja : DINT; *)
	END_STRUCT;

	OperatorTyp :STRUCT
		diStart : BOOL;
		diStop : BOOL;
		diESTOP : BOOL;
		diReset : BOOL;
		doAktywny : BOOL;
		doAwaria : BOOL;
	
	END_STRUCT;
	
	SuwnicaParTyp : STRUCT
		uiHomingSpeed : INT;
		uiGoToStartSpeed: ARRAY[1..2] OF UINT;
		uiGoToEndSpeed : INT;
		uiStartPozycja : ARRAY[1..2] OF DINT;
		uiEndPozycja : ARRAY[1..2] OF DINT;
		uiTolPozycja : DINT;
		
	END_STRUCT;
END_TYPE