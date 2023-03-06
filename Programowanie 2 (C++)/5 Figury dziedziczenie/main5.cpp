/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 10.05.2020 //
/////////////////////////////////////////

#include <iostream>


using namespace std;

class czworokat
{
    protected:
    int a, b, c, d;
    public:
    czworokat(int aa, int bb, int cc, int dd);
    void wypisz();
    virtual int pole() {}
};

czworokat::czworokat(int aa, int bb, int cc, int dd)
{
    a=aa;
    b=bb;
    c=cc;
    d=dd;
}

void czworokat::wypisz()
{
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
cout<<"c="<<c<<endl;
cout<<"d="<<d<<endl;
}

class prostokat : public czworokat
{
    public:
    prostokat(int aa, int bb);
    void wymiary(int w1, int w2);
    virtual int pole()
    {
    return a*b;
    }
};

prostokat::prostokat(int aa, int bb):czworokat(aa,bb,aa,bb)
{}
   // a=aa; c=aa;
   // b=bb; d=bb;
//}

void prostokat::wymiary(int w1, int w2)
{
    a=w1; c=w1;
    b=w2; d=w2;
}

class kwadrat : public czworokat
{
    public:
    kwadrat(int aa);
    void wymiar(int w1);
    virtual int pole()
    {
    return a*a;
    }
};

kwadrat::kwadrat(int aa):czworokat(aa,aa,aa,aa)
{}

void kwadrat::wymiar(int w1)
{
    a=w1; c=w1;
    b=w1; d=w1;
}


int main()
{
    int a, b;
    czworokat *Czworokat;


    cout<<"Podaj dlugosc boku KWADRATU: ";
    cin>>a;

    kwadrat* Kwadrat=new kwadrat(a);
    Czworokat=Kwadrat;
cout<<endl;
    cout<<"Pole KWADRATU = "<<Czworokat->pole()<<endl;
cout<<endl<<endl;
    cout<<"Podaj dlugosci pierwszego boku PROSTOKATA: ";
    cin>>a;
    cout<<"Podaj dlugosci drugiego boku PROSTOKATA: ";
    cin>>b;
cout<<endl;
    prostokat* Prostokat=new prostokat(a,b);
    Czworokat=Prostokat;
    cout<<"Pole PROSTOKATA = "<<Prostokat->pole()<<endl;

    return 0;
}
