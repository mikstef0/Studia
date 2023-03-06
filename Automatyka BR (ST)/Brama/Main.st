
PROGRAM _INIT

	 
END_PROGRAM

PROGRAM _CYCLIC

	brama.doOpenGate:=((brama.diGateOpen OR brama.lampa) AND NOT brama.diGateOpened) AND brama.diEStop AND NOT(brama.diTemperatura) AND NOT brama.doCloseGate;
	brama.lampa:=brama.doOpenGate XOR brama.doCloseGate;
	brama.doCloseGate:=((brama.diGateClose OR brama.lampa) AND NOT brama.diGateClosed) AND brama.diEStop AND brama.diSafetySensor AND NOT(brama.diTemperatura) AND NOT brama.doOpenGate;
	brama.lampa:=brama.doOpenGate XOR brama.doCloseGate;
	
	fai
	fDelayON.PT:=T#1s;
	fDelayON();
	
	IF fDelayON.Q THEN
		brama.doLampa:=NOT(brama.doLampa);
	END_IF;
	
END_PROGRAM

PROGRAM _EXIT

	 
END_PROGRAM

