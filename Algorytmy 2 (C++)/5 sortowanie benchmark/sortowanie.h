#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <list>
using namespace std;


void zliczanie(int* tab, int rozmiar, int szerokosc)
{
int* licznosc;
licznosc=new int[szerokosc];

for(int i=0;i<rozmiar;i++)
{
licznosc[tab[i]]++;
}

for(int i=0;i<rozmiar;i++)
{
tab[i]=0;
}

int k=0;
for(int i=0;i<rozmiar;i++)
{
    for(int j=0; j<licznosc[i]; j++)
    {
    tab[k]=i;
    k++;
    }
}

delete [] licznosc;
}


void kubelki_int(int* tab, int rozmiar, int maks, int liczba_kubelkow)
{
list<int> *kubelki;
kubelki=new list<int>[rozmiar];
int szerokosc=maks/rozmiar;


for(int i=0;i<rozmiar;i++)
{
kubelki[tab[i]/szerokosc].push_back(tab[i]);
}

for(int i=0;i<rozmiar;i++)
	if(kubelki[i].size()>1)
		kubelki[i].sort();



for(int i=0, k=0;i<rozmiar;i++) {
list<int>::iterator it;
		for(it=kubelki[i].begin(); it!=kubelki[i].end(); ++it)
		{
			tab[k]=*it;
			k++;
		}
}

kubelki->clear();
delete [] kubelki;
}

template<typename T>
void kubelki_t(T* tab, int rozmiar, int maks, int liczba_kubelkow)
{
list<T> *kubelki;
kubelki=new list<T>[rozmiar];
int szerokosc=maks/rozmiar;


for(int i=0;i<rozmiar;i++)
{
kubelki[tab[i].indeks()/szerokosc].push_back(tab[i]);
}

for(int i=0;i<rozmiar;i++)
	if(kubelki[i].size()>1)
		kubelki[i].sort();



for(int i=0, k=0;i<rozmiar;i++) {
typename list<T>::iterator it;
		for(it=kubelki[i].begin(); it!=kubelki[i].end(); ++it)
		{
			tab[k]=*it;
			k++;
		}
}

kubelki->clear();
delete [] kubelki;
}
