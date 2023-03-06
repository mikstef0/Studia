
PROGRAM _INIT
	ControlTyp:=5;
	Suwnica.SilnikDC.PeriodDuration:=100;
	Maszynastanu:=WAIT_FOR_ACTION;
	Suwnica.Enkoder.uiTryb:=195;
END_PROGRAM

PROGRAM _CYCLIC
	CASE ControlTyp OF
		1: //sterowanie logicyne
			Dom.Brama.doZasilanie:=Dom.Brama.Pilot.diOtworz XOR Dom.Brama.Pilot.diZamknij;
			Dom.Brama.doPrawoLewo:=Dom.Brama.Pilot.diOtworz AND NOT Dom.Brama.Pilot.diZamknij;
		
		2: 
			Dom.Brama.doZasilanie:=Dom.Brama.Pilot.uiOtwieranie XOR Dom.Brama.Pilot.uiZamykanie;
			Dom.Brama.doPrawoLewo:=Dom.Brama.Pilot.uiOtwieranie AND NOT Dom.Brama.Pilot.uiZamykanie;
			
			temp1:=Dom.Brama.Pilot.uiOtwieranie;
			
			Dom.Brama.Pilot.uiOtwieranie:=(EDGEPOS(Dom.Brama.Pilot.diOtworz) OR Dom.Brama.Pilot.uiOtwieranie) AND NOT(Dom.Brama.Pilot.diZamknij OR Dom.Brama.Pilot.uiZamykanie OR Dom.Brama.diKrancowkaPrawo); // operacja zapisu do pamiêci
			Dom.Brama.Pilot.uiZamykanie:=(EDGEPOS(Dom.Brama.Pilot.diZamknij) OR Dom.Brama.Pilot.uiZamykanie) AND NOT(Dom.Brama.Pilot.diOtworz OR temp1 OR Dom.Brama.diKrancowkaLewo);
		 

		4: 
			Skaluj[1].x:=INT_TO_REAL(Dom.Brama.Pilot.aiZadajnik[1]);
			Skaluj[1].x1:=0;
			Skaluj[1].y1:=-32768;
			Skaluj[1].x2:=32767;
			Skaluj[1].y2:=32767;
			Skaluj[1]();
			Suwnica.SilnikDC.aoPWM:=REAL_TO_INT(Skaluj[1].y);
			IF EDGEPOS(Suwnica.diStartLS_NC)=TRUE OR EDGEPOS(Suwnica.diEndLS_NC)=TRUE THEN
				Suwnica.SilnikDC.aoPWM:=0;
				
			END_IF;
		
		5:
			(*IF fLoadDefaults THEN
				SuwnicaPar.uiTolPoyzcja:=1000;
				SuwnicaPar.uiHomingSpeed:=2000;
				SuwnicaPar.uiGoToStartSpeed:=
				SuwnicaPar.uiGoToEndSpeed := -15000;
				SuwnicaPar.uiStartPozycja[1] :=14000;
				SuwnicaPar.uiEndPozycja :=
				SuwnicaPar.uiTolPozycja :=
				
				uipositionstart1 14000
				uiendposition1 90000
				homingspeed 2000
				gotostartspeed1 -5000
				gotostartspeed2 5000
				gotoendspeed1 -15000*)
				
			
			CASE Maszynastanu OF
				WAIT_FOR_ACTION:
					IF Suwnica.Operator.diStart AND (Suwnica.Enkoder.aiPozycja <= 100) AND (Suwnica.Enkoder.aiPozycja >= -100) AND Suwnica.diStartLS_NC THEN
						Maszynastanu:=GO_TO_START;
						
					END_IF;
					
					IF Suwnica.Operator.diStart AND ((Suwnica.Enkoder.aiPozycja > 100) OR (Suwnica.Enkoder.aiPozycja < -100) OR Suwnica.diStartLS_NC = FALSE)  THEN
						Maszynastanu:=HOMING;
						
					END_IF;
					
				HOMING:
					Suwnica.SilnikDC.aoPWM:= 12000;
					IF EDGEPOS(Suwnica.diEndLS_NC)=TRUE THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:= GO_TO_START0;
						
					END_IF;
				GO_TO_START0:
					Suwnica.SilnikDC.aoPWM:= -16000;
					IF (Suwnica.Enkoder.aiPozycja <= 42000) AND (Suwnica.Enkoder.aiPozycja >=38000) THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:= WAIT_FOR_ITEM;
					END_IF;
					
					IF Suwnica.Operator.diStop OR Suwnica.Operator.diESTOP THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:=WAIT_FOR_ACTION;
					END_IF;
					
				GO_TO_START:
					Suwnica.SilnikDC.aoPWM:= 16000;
					IF (Suwnica.Enkoder.aiPozycja <= 42000) AND (Suwnica.Enkoder.aiPozycja >=38000) THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:= WAIT_FOR_ITEM;
					END_IF;
					
					IF Suwnica.Operator.diStop OR Suwnica.Operator.diESTOP THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:=WAIT_FOR_ACTION;
					END_IF;
					
				WAIT_FOR_ITEM:
					(*IF Suwnica.Operator.diStop OR Suwnica.Operator.diESTOP THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:=WAIT_FOR_ACTION;*)
					//DelayON[1].IN:=Suwnica.diEndLS_NO;
					DelayON[1].IN:=Suwnica.diStartLS_NO;
					DelayON[1].PT:=T#2s;
					DelayON[1]();
					IF DelayON[1].Q THEN
						DelayON[1].IN:=FALSE;
						DelayON[1]();
						Maszynastanu:=GO_TO_END;
					END_IF;
					
				GO_TO_END:
					Suwnica.SilnikDC.aoPWM:= -16000;
					IF (Suwnica.Enkoder.aiPozycja <= 282000) AND (Suwnica.Enkoder.aiPozycja >=278000) THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						
						
						IF NOT(Suwnica.diEndLS_NO) THEN
							Maszynastanu:=FAILURE;
						ELSE
							Maszynastanu:= WAIT_FOR_OUT;
						END_IF;
						
					END_IF;
					
					IF Suwnica.Operator.diStop OR Suwnica.Operator.diESTOP THEN
						Suwnica.SilnikDC.aoPWM:= 0;
						Maszynastanu:=WAIT_FOR_ACTION;
					END_IF;
					
					
					
				WAIT_FOR_OUT:
					
					
					
					
					DelayON[2].IN:=NOT(Suwnica.diEndLS_NO);
					DelayON[2].PT:=T#2s;
					DelayON[2]();
					IF DelayON[2].Q THEN
						DelayON[2].IN:=FALSE;
						DelayON[2]();
						Maszynastanu:=GO_TO_START;
					
					END_IF;
					
					
					FAILURE:
					Suwnica.SilnikDC.aoPWM:= 0;
					DelayON[3].IN:=NOT DelayON[3].Q;
					DelayON[3].PT:=T#300ms;
					DelayON[3]();
					Suwnica.Operator.doAwaria:=Suwnica.Operator.doAwaria XOR DelayON[3].Q;
				
					
					IF Suwnica.Operator.diReset THEN
						Suwnica.Operator.doAwaria:=FALSE;
						Maszynastanu:=WAIT_FOR_ACTION;
		 			END_IF;

			END_CASE;
			
		
	END_CASE;
	 
END_PROGRAM

PROGRAM _EXIT
	
	 
END_PROGRAM

