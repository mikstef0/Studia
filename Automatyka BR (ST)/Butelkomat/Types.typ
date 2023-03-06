TYPE
	NapojeTyp :	STRUCT  (*Struktura danych bramy wjazdowej*)
		diStart : BOOL; (* Przycisk Start *)
		diStop : BOOL:=TRUE; (* Przycisk Stop *)
		diEStop : BOOL:=TRUE; (* Wylacznik bezpieczenstwa *)
		diThermTransporterOK : BOOL:=TRUE; (* Termik –za gorace styki przekaznika  silnika tranportera butelek *)
		diConfirmFailure : BOOL; (* Przycisk potwierdzenia awarii *)
		diBottleGo : BOOL; (* Czujnik potwierdzajacy wypuszczenie butelki *)
		diBottlePresent : BOOL; (* Czujnik wykrywajacybutelke pod nalewakiem *)
		diBottleFull : BOOL; (* Czujnik potwierdzajacynapelnienie butelki *)
		
		doActive : BOOL; (* Lampka zielona „System aktywny” *)
		doFailure : BOOL; (* Lampka czerwona „Awaria” *)
		doTransporter : BOOL; (* Zasilanie silnika transportera butelek *)
		doBottleUnLock : BOOL; (* Otwarcie sluzy  *)
		doFillBottle : BOOL; (* Otwarcie zaworu napelniania *)
		Alarm : AlarmTyp; (* Do obslugi systemu alarmów *)
		
	END_STRUCT;
	
	AlarmTyp : STRUCT
		uiAktywnyAlarm : ARRAY[0..4] OF BOOL; (* Flagi identyfikacji aktywnego alarmu *)
		uiPotwierdzAlarm : ARRAY[0..4] OF BOOL; (* Potwierdzanie alarmu o okreœlonym indeksie *)
	END_STRUCT;
		
	NapojeControlTyp :
	(
	(* Maszyna stanu napelniania butelek *)
	INITIAL := 0, (* Czekanie na start systemu *)
	PRACA := 1, (* Normalna praca *)
	PAUZA := 2, (* Pauza *)
	AWARIA := 3 (* Obsluga stanów awaryjnych *)
	);

END_TYPE