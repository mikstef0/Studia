#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include<cstdlib>
#include<list>
#include<string>
#include <time.h>
#include <math.h>,
#include "tablica.h"
#include<stdlib.h>
//#include<crtdbg.h>
using namespace std;


struct some_object
{
    int field_1;
    char field_2;
    friend bool operator > (const some_object& so1, const some_object& so2)
    {
        return  so1.field_1>so2.field_1 || (so1.field_1==so2.field_1 && so1.field_2>so2.field_2);
    }

    friend bool operator==(const some_object& so1, const some_object& so2)
    {
        return so1.field_1 == so2.field_1 && so1.field_2==so2.field_2;
    }
};



int main()
{

//lista<some_object>* ll=new lista<some_object>();

    tablica<some_object>* tabl = new tablica<some_object>();

    srand(time(NULL));

    const int order=4;
    const int n=pow(10, order);

    some_object so;
    cout<<"DODAWANIE\n\n";
    clock_t t1=(double)clock();
    double max_time_per_element=0.0;
    for(int i=0; i<n; i++)
    {
        so.field_1=rand()%10001;
        so.field_2=rand()%26+97;
        clock_t t1_element=(double)clock();
        tabl->dodaj(so);
        clock_t t2_element=(double)clock();
        double time_per_element=(double)(t2_element-t1_element)/CLOCKS_PER_SEC;
        if(time_per_element>max_time_per_element)
        {
            max_time_per_element=time_per_element;
            cout<<i<<endl;
        }
    }
    clock_t t2=(double)clock();
    double time=(double)(t2-t1)/CLOCKS_PER_SEC;

    printf("Czas dodawania elementow: %f\n", time);
    printf("Najgorszy czas dla elementu: %f\n", max_time_per_element);

    cout<< tabl->to_string(4);
    cout<<"\nZWRACANIE ADR.\n\n";
    t1=(double)clock();
    for(int i=0; i<n; i++)
    {
        clock_t t1_element=(double)clock();
        try
        {
            tabl->zwroc_i(i);
        }
        catch(string error)
        {
            cout<<error;
        }
        clock_t t2_element=(double)clock();
        double time_per_element=(double)(t2_element-t1_element)/CLOCKS_PER_SEC;
        if(time_per_element>max_time_per_element)
        {
            max_time_per_element=time_per_element;
            cout<<i<<endl;
        }
    }
    t2=(double)clock();
    time=(double)(t2-t1)/CLOCKS_PER_SEC;

    printf("\nCzas zwracania adresow elementow: %f\n", time);
    printf("Najgorszy czas dla elementu: %f\n", max_time_per_element);

    //  cout << &tabl->zwroc_i(0);

//    cout<<tabl->zwroc_i(0).field_1;
//    cout<<tabl->zwroc_i(0).field_2;
    cout<<"\nPODMIENIANIE\n\n";
    t1=(double)clock();
    max_time_per_element=0.0;
    for(int i=0; i<n; i++)
    {
        so.field_1=rand()%10001;
        so.field_2=rand()%26+97;
        clock_t t1_element=(double)clock();
        try
        {
            tabl->podmien(i, so);
        }
        catch(string error)
        {
            cout<<error;
        }
        clock_t t2_element=(double)clock();
        double time_per_element=(double)(t2_element-t1_element)/CLOCKS_PER_SEC;
        if(time_per_element>max_time_per_element)
        {
            max_time_per_element=time_per_element;
            cout<<i<<endl;
        }
    }
    t2=(double)clock();
    time=(double)(t2-t1)/CLOCKS_PER_SEC;

    printf("\nCzas podmieniania danych elementow: %f\n", time);
    printf("Najgorszy czas dla elementu: %f\n", max_time_per_element);

    //    cout<<tabl->zwroc_i(0).field_1;
    //    cout<<tabl->zwroc_i(0).field_2;
    cout<<"\nWYPISANIE TO_STRING\n\n";
    t1=(double)clock();
    cout<< tabl->to_string(4);
    t2=(double)clock();
    time=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\nCzas wypisywania to_string: %f\n", time);

    cout<<"\nSORTOWANIE BABELKOWE\n\n";
    t1=(double)clock();
    tabl->posortuj();
    t2=(double)clock();
    time=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\nCzas sortowania: %f\n", time);


    cout<< tabl->to_string(4);


    cout<<"\nCZYSZCZENIE\n\n";
    t1=(double)clock();
    tabl->wyczysc();
    t2=(double)clock();
    time=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\nCzas czyszczenia: %f\n", time);



    tabl->~tablica();

    // delete tabl;


    //  _CrtDumpMemoryLeaks();

    return 0;
}

