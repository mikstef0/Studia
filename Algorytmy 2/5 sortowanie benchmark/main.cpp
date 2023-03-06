#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iterator>
#include "kopiec.h"
#include "sortowanie.h"

using namespace std;

struct some_object
{
    int field_1;
    char field_2;

    some_object()
    {
        field_1=rand()%10;
        field_2=rand()%1+97;
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

    int indeks()
    {
    return field_1;
    }



};


int main() {
  //  int kop[6]={3,2,2,0,0,0};
  cout<<"HEAP SORT";
    int* tab;
    tab=new int[6];
    tab[0]=3; tab[1]=2; tab[2]=2;
    int ile=6;
    srand(time(NULL));
    const int MAXORDER=1;
    kopiec_bin<int> *bh=new kopiec_bin<int>(tab, ile);

 //   bh->sort_gora();
 //   bh->sort_dol();

    bh->to_string();

    delete bh;

    for(int i=0; i<6; i++) cout<<tab[i];
    cout<<endl;

    cout<<"COUNTING SORT"<<endl;
  //  zliczanie(tab, ile, 5);

    for(int i=0; i<6; i++) cout<<tab[i];
    cout<<endl;

    cout<<"BUCKET SORT"<<endl;
    kubelki_int(tab, ile, 6, 6);

    for(int i=0; i<6; i++) cout<<tab[i];

    some_object* t;
    t=new some_object[4];
    t[0].field_1=5; t[0].field_2='b';
    t[1].field_1=5; t[1].field_2='a';
    t[2].field_1=5; t[2].field_2='e';
    t[3].field_1=5; t[3].field_2='d';

    kubelki_t(t, 4, 8,8);
cout<<endl;
    cout<<t[0];
    cout<<t[1];
    cout<<t[2];
    cout<<t[3];
    delete [] t;
    delete [] tab;

    return 0;


}
