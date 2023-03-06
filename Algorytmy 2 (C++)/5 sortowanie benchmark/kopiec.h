#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
using namespace std;


template<class T>
class kopiec_bin
{
public:
   T* kopiec;
   int rozm;
   int rozm_w;


    int prawy(int rodzic)
    {
        int p=2*rodzic+2;
        if (p<rozm)
            return p;
        else
            return -1;
    }

    int lewy(int rodzic)
    {
        int l=2*rodzic+1;
        if (l<rozm)
            return l;
        else
            return -1;
    }


    int rodzic(int dziecko)
    {
        int r=(dziecko-1)/2;
        if (dziecko==0)
            return -1;
        else
            return r;
    }

    void przekopcowanie_gora(int indeks)
    {
        if (indeks >= 0 && rodzic(indeks) >= 0 && kopiec[rodzic(indeks)] < kopiec[indeks])
        {
            T temp = kopiec[indeks];
            kopiec[indeks] = kopiec[rodzic(indeks)];
            kopiec[rodzic(indeks)] = temp;
            przekopcowanie_gora(rodzic(indeks));
        }
    }

    void przekopcowanie_dol(int indeks)
    {
        int dziecko1 = lewy(indeks);
        int dziecko2 = prawy(indeks);
        if (dziecko1 >= 0 && dziecko2 >= 0 && kopiec[dziecko1] < kopiec[dziecko2])
        {
            dziecko1 = dziecko2;
        }
        if (dziecko1 > 0 && kopiec[indeks] < kopiec[dziecko1])
        {
            T temp = kopiec[indeks];
            kopiec[indeks] = kopiec[dziecko1];
            kopiec[dziecko1] = temp;
            przekopcowanie_dol(dziecko1);
        }
    }


public:
    kopiec_bin(T kop[], int ile) {
    kopiec=kop;
    rozm=ile;
    rozm_w=ile;
    przekopcowanie_dol(0);
    }


  /*  void dodaj(T el)
    {
        kopiec.push_back(el);
        przekopcowanie_gora(kopiec.size()-1);
    }
*/

  /*
    T usun_max()
    {
   if (kopiec.size() == 0) {
      throw("Blad: kopiec jest pusty");
   }
   T zwr=kopiec.front();
   kopiec[0] = kopiec.at(kopiec.size()-1);
   kopiec.pop_back();
   przekopcowanie_dol(0);
   return zwr;
}
*/


    void to_string()
    {
        cout<<"Liczba elementow: "<<rozm_w<<endl;
  //      typename vector <T>::iterator it = kopiec.begin();
        cout<<"Zawartosc kopca:"<<endl;
      //  while (it != kopiec.end())
      int ile=0;
      while(ile<10 && ile<rozm_w)
        {
            cout<<kopiec[ile]<<endl;;
        //    it++;
            ile++;
        }
        cout<<endl;
    }

    void sort_dol()
    {
      for(int i=rozm-1; i>=0; i--)
    {
    swap(kopiec[i], kopiec[0]);
    przekopcowanie_dol(0);
    rozm--;
    }

    }

    void sort_gora()
    {
      for(int i=0; i<rozm_w; i++)
    {
    swap(kopiec[i], kopiec[0]);
    przekopcowanie_gora(rozm-1);
    rozm--;
    }

    }



    int rozmiar()
    {
    //    return size(kopiec);
    }

    void wyczysc()
    {
//    kopiec.clear();
  //  while(kopiec.empty()==false)
  //      {
  //      usun_max();
  //      }
    }


};








