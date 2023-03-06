#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include "drzewo.h"
using namespace std;



struct some_object
{
    int field_1;
    char field_2;

    some_object()
    {
        field_1=rand()%10001;
        field_2=rand()%26+97;
    }

    friend bool operator < (const some_object& so1, const some_object& so2)
    {
        return  so1.field_1<so2.field_1 || (so1.field_1==so2.field_1 && so1.field_2<so2.field_2);
    }

    friend bool operator > (const some_object& so1, const some_object& so2)
    {
        return  so1.field_1>so2.field_1 || (so1.field_1==so2.field_1 && so1.field_2>so2.field_2);
    }

    friend bool operator==(const some_object& so1, const some_object& so2)
    {
        return so1.field_1 == so2.field_1 && so1.field_2==so2.field_2;
    }


    friend ostream& operator<<(ostream& os, const some_object& so)
    {
        os << so.field_1 << ' ' << so.field_2;
        return os;
    }

};


int main()
{
/*
    drzewo <int> bst1;
    for(int i:{8, 4, 12, 2, 6, 10, 3} )
    {
        bst1.dodaj(i);
    }
    bst1.usun(8);
    bst1.to_string();
    return 0;
*/
    const  int  MAX_ORDER = 6; //  maksymalny  rzad  wielkosci  dodawanych  danych

    drzewo <some_object>* bst = new  drzewo<some_object>();//  stworzenie drzewa

    for (int o = 1; o <= MAX_ORDER; o++)
    {
        const  int n = pow(10, o);//  rozmiar  danych
        cout<<"\nLICZBA ELEMENTOW: "<<n<<endl;
//  dodawanie  do  drzewa
        clock_t  t1 = (double)clock();
        for (int i = 0; i < n; i++)
        {
            some_object so=some_object();
            bst->dodaj(so);//  dodanie
        }
        clock_t  t2 = (double)clock();
        double czas=(double)(t2-t1)/CLOCKS_PER_SEC;
        cout<<"Czas dodawania elementow: "<<(double)czas<<endl;
        cout<<"Srednia czas dodawania elementu: "<<(double)czas/n<<endl;
        if(n<=10) bst->to_string();
//  wypis  na  ekran  aktualnej  postaci  drzewa (skrotowej ) wrazz  pomiarami  czasowymi  i w/wwielkosciami
//  wyszukiwanie
        const  int m = pow(10, 4);//  liczba  prob  wyszukiwania
        int  hits = 0;//  liczba  trafien
        t1 = (double)clock();
        for (int i = 0; i < m; i++)
        {
            some_object so=some_object();
            try
            {
                bst->wyszukaj(so);
                hits++;
            }
            catch(string e) {  }
        }
        cout<<"Liczba wyszukan: "<<m<<endl;
        cout<<"Liczba trafien: "<<hits<<endl;
        t2 = (double)clock();//  wypis  na  ekran  pomiarow  czasowych  i  liczby  trafien
        czas=(double)(t2-t1)/CLOCKS_PER_SEC;
        cout<<"Czas szukania elementow: "<<(double)czas<<endl;
        cout<<"Srednia czas szukania elementu: "<<(double)czas/n<<endl;
        cout<<"Wysokosc drzewa: "<<bst->wysokosc<<endl;
        cout<<"Wysokosc/rozmiar = "<<(double)bst->wysokosc/n<<endl;
        cout<<"Log2(rozmiar) = "<<log2(n)<<endl;
        cout<<"Wysokosc/Log2(rozmiar) = "<<bst->wysokosc/log2(n)<<endl;

    }
    delete  bst;
    return 0;



}
