
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	kasa.doKasaCzynna := kasa.diKlucz; (* Lampa kasa czynna *)
	
	kasa.doSilnik := ((NOT(kasa.diTryb) AND kasa.diPedal) (* Tryb reczny *)
	OR (kasa.diTryb AND NOT(kasa.diFotokomorka)))  (* Tryb automagiczny *)
	AND kasa.diKlucz;
	
	//wariant dodatkowy - wcisniecie pedalu w trybie auto powoduje ruszenie/zatrzymanie tasmy
	

	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

