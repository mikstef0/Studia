//MIKO£AJ STEFANISZYN GR. 113A 04.04.2020

#include <iostream>

using namespace std;


  class macierz {
        private:
     float tab[3][3];
     short int rozmiar;
        public:
     macierz();
     void wczytajdane();
     void wypisz();
     friend macierz* dodajmacierze(macierz* m1, macierz* m2);
     };

     macierz::macierz()
     {
         for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) {
         tab[i][j]=0;  }  }
     }

     void macierz::wczytajdane()
     {
        float liczba;
        cout << "Wprowadz kolejno 9 liczb (float) do wpisania do macierzy: "<<endl;
         for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) {

         cin >> liczba;
         tab[i][j]=liczba;

           }  }
     }

     void macierz::wypisz()
     {
     cout << endl<< "Macierz:"<<endl;
         for(int i=0;i<3;i++) {
         for(int j=0;j<3;j++) {
         cout << tab[i][j]<< " ";  } cout << endl; } cout <<endl;
     }

     macierz* dodajmacierze(macierz* m1, macierz* m2)
     {
     macierz* m3;
     m3=new macierz;
   //  cout << "Nowa macierz:"<<endl;
     for(int i=0;i<3;i++) {
     for(int j=0;j<3;j++) {
     m3->tab[i][j]=m1->tab[i][j]+m2->tab[i][j];

  //   cout << m3->tab[i][j] << " ";

     }
   //  cout << endl;
       }
     return m3;
     }




int main()
{

    macierz* m1;
    macierz* m2;
    m1=new macierz;
    m2=new macierz;

        cout<<"Macierz m1:"<<endl;
    m1->wczytajdane();
    m1->wypisz();
        cout<<"Macierz m2:"<<endl;
    m2->wczytajdane();
    m2->wypisz();

   cout<<"Adres macierzy wynikowej: "<<dodajmacierze(m1, m2)<<endl;
    dodajmacierze(m1, m2)->wypisz(); // wypisanie macierzy wynikowej

    delete m1;
    delete m2;
     return 0;
}
