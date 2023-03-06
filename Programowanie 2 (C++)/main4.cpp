/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 25.04.2020 //
/////////////////////////////////////////

#include <iostream>


using namespace std;

class osoba
{
    string imie;
    string nazwisko;
    public:
    osoba(string name, string surname);
    void wypisz();
};

osoba::osoba(string name, string surname)
{
    imie=name;
    nazwisko=surname;
}

void osoba::wypisz()
{
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
}

////////////////

class ksiazka
{
    string tytul;
    osoba autor=osoba("","");
    public:
    ksiazka();
    ksiazka(string title, string name, string surname);
    void wypisz();
};

ksiazka::ksiazka()
{
}

ksiazka::ksiazka(string title, string name, string surname)
{
    tytul=title;
    autor=osoba(name, surname);
}

void ksiazka::wypisz()
{
cout<<endl;
cout<<"AUTOR: ";
autor.wypisz();
cout<<"Tytul: "<<tytul<<endl;
}

/////////

class czytelnik : public osoba
{
    ksiazka przeczytane[10];
    public:
    czytelnik(string name, string surname);
    czytelnik(string name, string surname, ksiazka k1, ksiazka k2, ksiazka k3);
    void wypiszksiazki();

};

czytelnik::czytelnik(string name, string surname):osoba(name, surname)
{}

czytelnik::czytelnik(string name, string surname, ksiazka k1, ksiazka k2, ksiazka k3):osoba(name, surname)
{
przeczytane[0]=k1;
przeczytane[1]=k2;
przeczytane[2]=k3;

}

void czytelnik::wypiszksiazki()
{
cout<<"CZYTELNIK: "<<endl;
this->wypisz();
for(int i=0;i<3;i++)
przeczytane[i].wypisz();
}



int main()
{
    ksiazka ks1=ksiazka("Pan Tadeusz", "Adam", "Mickewicz");
    ksiazka ks2=ksiazka("Symfonia C++", "Jerzy", "Grebosz");
    ksiazka ks3=ksiazka("Ksiazka telefoniczna", "autor", "nieznany");
    ksiazka ks4=ksiazka("Wiersze", "Julian", "Tuwim");
    ksiazka ks5=ksiazka("Informatyka poziom rozszerzony", "Grazyna", "Koba");
    czytelnik os1=czytelnik("Jan", "Kowalski", ks1, ks2, ks3);
    czytelnik os2=czytelnik("Adam", "Mickiewicz", ks3, ks4, ks5);
    czytelnik os3=czytelnik("Szewczyk", "Dratewka", ks1, ks3, ks5);


        cout<<endl<<"*CZYTELNIK OS1*"<<endl;
    os1.wypiszksiazki();
    cout<<endl<<"*CZYTELNIK OS2*"<<endl;
    os2.wypiszksiazki();
    cout<<endl<<"*CZYTELNIK OS3*"<<endl;
    os3.wypiszksiazki();

    cout<<endl;



    return 0;
}
