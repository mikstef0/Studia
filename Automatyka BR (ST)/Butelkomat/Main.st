
PROGRAM _INIT

	Sterowanie := INITIAL;
	 
END_PROGRAM

PROGRAM _CYCLIC



	CASE Sterowanie OF 
		INITIAL:
			
			Napoje.doBottleUnLock:=FALSE;
			Napoje.doFillBottle:=FALSE;
			Napoje.doTransporter:=FALSE;
			
			
			(* aktywacja - odliczanie czasu wcisniecia start *)
			fDelayON[5].IN:=Napoje.diStart AND Napoje.diStop;
			fDelayON[5].PT:=T#2s;
			fDelayON[5]();
			
			(* aktywacja po przytrzymaniu start *) (* przegrzene styki przy uruchomieniu - niewlaczenie czy awaria? *)
			IF fDelayON[5].Q AND //Napoje.diThermTransporterOK AND 
				Napoje.diStop AND Napoje.diEStop THEN
				
				Napoje.doActive := (Napoje.diStart OR Napoje.doActive) AND
				Napoje.diStop AND Napoje.diEStop;
				Sterowanie := PRACA;
			END_IF;
						
		PRACA:
		
			
			(* Obsluga alarmów *)
			
			fDelayON[0].IN:= NOT Napoje.diBottleGo AND Sterowanie=PRACA; (* E01 - Blad sluzy *)
			fDelayON[0].PT:=T#10s;
			fDelayON[0]();
						
			fDelayON[1].IN:= NOT Napoje.diBottlePresent AND Napoje.diBottleGo; (* E02 - Blad tasmy *)
			fDelayON[1].PT:=T#10s;
			fDelayON[1]();
			
			fDelayON[2].IN:= NOT Napoje.diBottleFull AND Napoje.doFillBottle; (* E03 - Blad napelniania butelek *)
			fDelayON[2].PT:=T#15s;
			fDelayON[2]();
			
			IF fDelayON[0].Q THEN
				Napoje.Alarm.uiAktywnyAlarm[0]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			IF fDelayON[1].Q THEN
				Napoje.Alarm.uiAktywnyAlarm[1]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			IF fDelayON[2].Q THEN
				Napoje.Alarm.uiAktywnyAlarm[2]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			IF NOT Napoje.diThermTransporterOK THEN
				Napoje.Alarm.uiAktywnyAlarm[3]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			IF NOT Napoje.diEStop THEN
				Napoje.Alarm.uiAktywnyAlarm[4]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			
			(* wylaczanie - odliczanie czasu wcisniecia stop *)
			fDelayON[5].IN:=NOT Napoje.diStop AND NOT Napoje.diStart;
			fDelayON[5].PT:=T#2s;
			fDelayON[5]();
		
			(* przystrzymanie przycisku *)
			IF fDelayON[5].Q //OR NOT Napoje.diEStop THEN
				THEN
				Napoje.doActive:=FALSE;
				Sterowanie:=INITIAL;
			END_IF;
			
			(* wcisniecie przycisku *)
			IF NOT fDelayON[5].Q AND NOT Napoje.diStop THEN
			Napoje.doActive:=FALSE;
				Sterowanie:=PAUZA;
			END_IF;
			
			(* Algorytm dzialania *)
			Napoje.doTransporter:=TRUE;
			Napoje.doBottleUnLock:=TRUE;
			
			IF Napoje.diBottleGo THEN
				Napoje.doBottleUnLock:=FALSE;
			END_IF;
			
			IF Napoje.diBottlePresent THEN
				Napoje.doTransporter:=FALSE;
				Napoje.doFillBottle:=TRUE;
			END_IF;
			
			IF Napoje.diBottleFull THEN
				Napoje.doFillBottle:=FALSE;
				Napoje.doTransporter:=TRUE;
				Napoje.doBottleUnLock:=FALSE;
			END_IF;
			
			
			
			
		PAUZA:
			
			(* wznawienie pracy po wcisnieciu start *)
			IF Napoje.diStart AND Napoje.diThermTransporterOK AND
				Napoje.diStop AND Napoje.diEStop THEN
				
				Napoje.doActive := (Napoje.diStart OR Napoje.doActive) AND
				Napoje.diStop AND Napoje.diEStop;
				Sterowanie := PRACA;
			END_IF;
			
			(* Przegrzanie styków *)
			IF NOT Napoje.diThermTransporterOK THEN
				Napoje.Alarm.uiAktywnyAlarm[3]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			(* Wcisniecie wylacznika awaryjnego *)
			IF NOT Napoje.diEStop THEN
				Napoje.Alarm.uiAktywnyAlarm[4]:= TRUE;
				Sterowanie:= AWARIA;
			END_IF;
			
			(* dezaktywacja po przytrzymaniu stop *)
			fDelayON[5].IN:=NOT Napoje.diStop;// AND NOT Napoje.diStart;
			fDelayON[5].PT:=T#2s;
			fDelayON[5]();
			
			IF fDelayON[5].Q// OR NOT Napoje.diEStop THEN AND NOT Napoje.diStart THEN
				THEN
				Napoje.doActive:=FALSE;
				Sterowanie:=INITIAL;
			END_IF;
					
	
		AWARIA:
		
			Napoje.doActive:=FALSE;
			IF NOT Napoje.Alarm.uiAktywnyAlarm[3] AND NOT Napoje.Alarm.uiAktywnyAlarm[4] THEN
				Napoje.doFailure:=TRUE;
			END_IF;
						
			Napoje.doBottleUnLock:=FALSE;
			Napoje.doFillBottle:=FALSE;
			Napoje.doTransporter:=FALSE;
			
			IF Napoje.Alarm.uiAktywnyAlarm[3] OR Napoje.Alarm.uiAktywnyAlarm[4] THEN
				fDelayON[4].IN:=NOT(fDelayON[4].Q);// AND Napoje.doFailure;
				fDelayON[4].PT:=T#1s;
				fDelayON[4]();
	
				IF fDelayON[4].Q THEN
					Napoje.doFailure:=NOT(Napoje.doFailure);
				END_IF;
			END_IF;
			
			
		
			(* wylaczanie - odliczanie czasu wcisniecia stop *)
			fDelayON[5].IN:=NOT Napoje.diStop AND NOT Napoje.diStart;
			fDelayON[5].PT:=T#2s;
			fDelayON[5]();
		
			(* wylaczenie *)
			IF fDelayON[5].Q THEN
				Napoje.doActive:=FALSE;
				Sterowanie:=INITIAL;
			END_IF;
	
			IF Napoje.diConfirmFailure THEN
				Napoje.doFailure:=FALSE;
				FOR i:= 0 TO 4 DO
				Napoje.Alarm.uiAktywnyAlarm[i]:=FALSE;
				END_FOR;
				FOR i:= 0 TO 5 DO
				fDelayON[i].IN:=FALSE;
				fDelayON[i]();
				END_FOR;
				Sterowanie:=INITIAL;
			END_IF;
		
				
	END_CASE;
	
END_PROGRAM

PROGRAM _EXIT

	 
END_PROGRAM

