import matplotlib.pyplot as plt
import random as los

stany=['Z','C','ZD','ZZ']
los.seed()

##### USTAWIENIA #############

rozm=100 #rozmiar planszy (rozm x rozm)
rozmok=100 #rozmiar planszy wyświetlanej
ile=100 #liczba początkowa osobników
czas=100 #czas trwania symulacji (liczba tur)
pauza=0.02 #czas odswieżania wizualizacji
szansa_narodziny=0.25#prawdopodobienstwo urodzenia osobnika przez pół spotkania
#^^przykładowo dla s_n=0.4 szansa na urodzenie 0 osobników to (1-0.4)^2=0.36,
#szansa na urodzenie 1 osobnika to (044*(1-0.4))^2=0.48,a dwóch to (0.4)^2=0.16

###############################

class Osobnik:
    # x=0
    # y=0
    # kierunekX=0
    # kierunekY=0
    # stan='ZZ'
    # wiek=0
    # predkosc=0
    # odpornosc=0
    # zyje=True

    def __init__(self,rodzenie) -> None:
        if(rodzenie==0):
            self.x=los.randint(1,rozm)
            self.y=los.randint(1,rozm)
            self.kierunekX=los.randint(-1,1)
            self.kierunekY=los.randint(-1,1)
            while(self.kierunekY==0 and self.kierunekX==0):
                self.kierunekX=los.randint(-1,1)
                self.kierunekY=los.randint(-1,1)
            self.wiek=los.randint(0,60)
            self.predkosc= los.randint(1,3)
            if ((self.wiek >= 0 and self.wiek < 15) or (self.wiek >= 70 and self.wiek <= 100)):
                self.odpornosc=los.random() * (3-0.01) + 0.01
            elif (self.wiek >= 40 and self.wiek < 70):
                self.odpornosc=los.random() * (6-3.01) + 3.01
            elif (self.wiek >= 15 and self.wiek < 40):
                self.odpornosc=los.random() * (10-6.01) + 6.01
            self.zyje=True
            self.stan=los.choice(stany)
        elif(rodzenie==1):
            self.x=los.randint(1,rozm)
            self.y=los.randint(1,rozm)
            self.kierunekX=los.randint(-1,1)
            self.kierunekY=los.randint(-1,1)
            while (self.kierunekY == 0 and self.kierunekX == 0):
                self.kierunekX=los.randint(-1,1)
                self.kierunekY=los.randint(-1,1)
            self.wiek=0
            self.predkosc=los.randint(1,3)
            self.odpornosc=10
            self.zyje=True
            self.stan='ZZ'

def ruch(osb):
    if(osb.x<=0):
        osb.kierunekX=los.randint(0,1)
    elif(osb.x>=100):
        osb.kierunekX=los.randint(-1,0)
    if (osb.y <= 0):
        osb.kierunekY=los.randint(0,1)
    elif (osb.y >= 100):
        osb.kierunekY=los.randint(-1,0)
    osb.x=osb.x+(osb.kierunekX*osb.predkosc)
    osb.y=osb.y+(osb.kierunekY*osb.predkosc)

def starzenie(osb):
    osb.wiek=osb.wiek+1 #osb.wiek+=1
    if(osb.wiek<15 or osb.wiek>70):
        if(osb.odpornosc>3):
            osb.odpornosc=los.random() * (3-0.01) + 0.01
    elif(osb.wiek>=40 and osb.wiek<70):
        if(osb.odpornosc>6):
            osb.odpornosc=los.random() * (6-3.01) + 3.01

def narodziny(osb1,osb2):
    #odl=max(abs(osb1.x-osb2.x),abs(osb1.y-osb2.y))
    if(osb1.wiek>=20 and osb1.wiek<=40 and osb2.wiek>=20 and osb2.wiek<=40):
        czynarodziny=los.random()
        if(czynarodziny<=szansa_narodziny):
            osobnik_nowy=Osobnik(1)
            osobniki.append(osobnik_nowy)

def smierc(osb):
    if(osb.wiek>=100 or osb.odpornosc<=0):
        osb.zyje=False

def spotkanie(osb1,osb2):
    odl=max(abs(osb1.x - osb2.x),abs(osb1.y - osb2.y))
    if(odl<=2):
        osb1.kierunekX=los.randint(-1,1)
        osb1.kierunekY=los.randint(-1,1)
        while (osb1.kierunekY == 0 and osb1.kierunekX == 0):
            osb1.kierunekX=los.randint(-1,1)
            osb1.kierunekY=los.randint(-1,1)
        osb2.kierunekX=los.randint(-1,1)
        osb2.kierunekY=los.randint(-1,1)
        while (osb2.kierunekY == 0 and osb2.kierunekX == 0):
            osb2.kierunekX=los.randint(-1,1)
            osb2.kierunekY=los.randint(-1,1)
        return True
    else:
        return False

#osb=Osobnik(0)
#osb2=Osobnik(0)

osobniki=[]

#osobniki=[osb,osb2]
for i in range(0,ile):
    osobnik=Osobnik(0)
    osobniki.append(osobnik)

plt.figure()
for tura in range(0,czas):
    for osobniki1 in osobniki:
        for osobniki2 in osobniki:
            if(osobniki1!=osobniki2):
                czyspotkanie=spotkanie(osobniki1,osobniki2)
                if(czyspotkanie==True):
                    narodziny(osobniki1,osobniki2)
    ilezyje = 0
    for osobnik in osobniki:
        if(osobnik.zyje==True):
            ilezyje=ilezyje+1
            if osobnik.stan == 'ZZ':
                plt.plot(osobnik.x,osobnik.y,'.',color='green')
            elif osobnik.stan == 'C':
                plt.plot(osobnik.x,osobnik.y,'.',color='red')
            elif osobnik.stan == 'ZD':
                plt.plot(osobnik.x,osobnik.y,'.',color='orange')
            elif osobnik.stan == 'Z':
                plt.plot(osobnik.x,osobnik.y,'.',color='yellow')
        ruch(osobnik)
        starzenie(osobnik)
        smierc(osobnik)
    plt.axis([0,rozmok,0,rozmok])
    plt.title('Tura: '+str(tura)+'  liczba osobnikow: '+str(ilezyje))
    plt.show(block=False)
    plt.pause(pauza)
    plt.cla()



