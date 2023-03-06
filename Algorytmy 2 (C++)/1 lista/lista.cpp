#include<iostream>
#include<cstdlib>
#include<list>
#include "lista.h"
using namespace std;

/*
struct some_object
{
    int field_1;
    char field_2;
    bool operator < (const some_object& so) const
    {
    }
    void *pokaz()
    {
    cout << "Pole 1: "<< field_1 <<endl;
    cout << "Pole 2: "<< field_2 <<endl;
    }
};
*/

int main()
{
    struct some_object
    {
        int field_1;
        char field_2;
    };

//    lista<some_object> ll();
lista<some_object>* ll=new lista<some_object>();


    some_object so;
    so.field_1 = 123;
    so.field_2 ='a';
    ll->dodaj(so);
    ll->pokaz_i();
    ll->usunpierwszy();

    return 0;
}

