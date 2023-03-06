/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 25.04.2020 //
/////////////////////////////////////////

#include <iostream>


using namespace std;

class ulamek
{
    private:
    int licznik;
    int mianownik;
    public:
    ulamek(int licz, int mian);
    void wypisz();
    ulamek operator + (const ulamek &);
    ulamek operator - (const ulamek &);
    ulamek operator * (const ulamek &);
    ulamek operator / (const ulamek &);
};

ulamek::ulamek(int licz, int mian)
{
    licznik=licz;
    mianownik=mian;
}

void ulamek::wypisz()
{
    cout<<licznik<<"/"<<mianownik;
}

ulamek ulamek::operator * (const ulamek &ul2)
{
    ulamek temp=ulamek(licznik, mianownik);
    temp.mianownik=mianownik*ul2.mianownik;
    temp.licznik=licznik*ul2.licznik;
    return temp;
}

ulamek ulamek::operator / (const ulamek &ul2)
{
    ulamek temp=ulamek(licznik, mianownik);
    temp.mianownik=mianownik*ul2.licznik;
    temp.licznik=licznik*ul2.mianownik;
    return temp;
}

ulamek ulamek::operator + (const ulamek &ul2)
{
    ulamek temp=ulamek(licznik, mianownik);
    temp.mianownik=mianownik*ul2.mianownik;
    temp.licznik=(licznik*ul2.mianownik)+(mianownik*ul2.licznik);
    return temp;
}

ulamek ulamek::operator - (const ulamek &ul2)
{
    ulamek temp=ulamek(licznik, mianownik);
    temp.mianownik=mianownik*ul2.mianownik;
    temp.licznik=(licznik*ul2.mianownik)-(mianownik*ul2.licznik);
    return temp;
}



int main()
{
    int m1, m2, l1, l2;

    ulamek u1=ulamek(0,0);
    ulamek u2=ulamek(0,0);
    ulamek wynik=ulamek(0,0);

    do
    {
    cout<<"Podaj licznik 1. ulamka: "; cin >> l1;
    cout<<"Podaj mianownik 1. ulamka: "; cin >> m1;
    cout<<"Podaj licznik 2. ulamka: "; cin >> l2;
    cout<<"Podaj mianownik 2. ulamka: "; cin >> m2;
    if(!m1||!m2) {cout<<"Jeden z mianownikow jest rowny 0, wprowadz ulamki od nowa.\n";}
    }
    while(!m1 && !m2);


    system("clear");
    //dodawanie:

    cout<<endl<<"Dodawanie:"<<endl;
    u1=ulamek(l1, m1);
    u2=ulamek(l2, m2);

    wynik=u1+u2;
    u1.wypisz(); cout<<" + ";
    u2.wypisz(); cout<<" = "; wynik.wypisz();
    cout<<endl<<endl;


    //odejmowanie:

    cout<<"Odejmowanie:"<<endl;
    u1=ulamek(l1, m1);
    u2=ulamek(l2, m2);

    wynik=u1-u2;
    u1.wypisz(); cout<<" - ";
    u2.wypisz(); cout<<" = "; wynik.wypisz();
    cout<<endl<<endl;

    //mnozenie:

    cout<<"Mnozenie:"<<endl;
    u1=ulamek(l1, m1);
    u2=ulamek(l2, m2);

    wynik=u1*u2;
    u1.wypisz(); cout<<" * ";
    u2.wypisz(); cout<<" = "; wynik.wypisz();
    cout<<endl<<endl;


    //dzielenie:

    cout<<"Dzielenie:"<<endl;
    u1=ulamek(l1, m1);
    u2=ulamek(l2, m2);

    wynik=u1/u2;
    u1.wypisz(); cout<<" / ";
    u2.wypisz(); cout<<" = "; wynik.wypisz();
    cout<<endl<<endl;






    return 0;
}
