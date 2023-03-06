//MIKO£AJ STEFANISZYN GR. 113A 30.03.2020


#include <iostream>
#include <time.h>

using namespace std;


  class przypomnienie {
     int dzien, miesiac, rok;
     string tresc;
     public:
     przypomnienie();
     przypomnienie(int d, int m, int r);
     przypomnienie(const przypomnienie &prz2);
     ~przypomnienie();
     void zapiszwiadomosc(string tresc_przyp);
     void wypisz();
     };

     przypomnienie::przypomnienie()
     {
         time_t czassyst = time(0);
          tm *data = localtime(&czassyst);
         dzien=data->tm_mday;
         miesiac=1+data->tm_mon;
         rok=1900+data->tm_year;
     }


     przypomnienie::przypomnienie(int d, int m, int r)
     {
        // przypomnienie* prz2=new przypomnienie;
         dzien=d;
         miesiac=m;
         rok=r;
     }

     przypomnienie::przypomnienie(const przypomnienie &prz2)
     {
        dzien=prz2.dzien;
         miesiac=prz2.miesiac;
         rok=prz2.rok;
         tresc=prz2.tresc;

     }

     przypomnienie::~przypomnienie()
     {
        cout << "Uruchomiono destruktor - usuwanie przypomnienia:" << endl;
        cout << "Data: "<< dzien << "."<< miesiac<<"."<<rok<<endl;
        cout << "Tresc: "<<tresc<<endl<<endl;
     }

    void przypomnienie::zapiszwiadomosc(string tresc_przyp)
    {
        tresc=tresc_przyp;
    }

    void przypomnienie::wypisz()
    {
        cout << "Przypomnienie:" << endl;
        cout << "Data: "<< dzien << "."<< miesiac<<"."<<rok<<endl;
        cout << "Tresc: "<<tresc<<endl<<endl; }

//////////////////////////




int main()
{
    string tresc_przyp;

     przypomnienie prz1; // utworzenie obiektu (przypomnienia 1 - prz1) za pomoc¹ konstruktora bez parametrów
     przypomnienie* prz2=new przypomnienie(3,9,2020); // utworzenie obiektu (prz2) za pomoc¹ konstruktora z parametrami



    prz1.wypisz();
    prz2->wypisz(); // wypisanie obiektow (przypomnien) po ich utworzeniu


    cout << "Podaj tresc 1. (obiekt statyczny) przypomnienia: ";
    getline(cin, tresc_przyp);
    prz1.zapiszwiadomosc(tresc_przyp);

    cout << "Podaj tresc 2. (obiekt dynamiczny) przypomnienia: ";
    getline(cin, tresc_przyp);
    prz2->zapiszwiadomosc(tresc_przyp);

    przypomnienie* prz3=new przypomnienie(*prz2);
    cout << endl<< "Utworzono przypomnienie nr 3 (kopia przypomnienia nr 2)";


    cout << endl << endl;

    prz1.wypisz();
    prz2->wypisz();
    prz3->wypisz();





    delete prz2;
    delete prz3;

     return 0;
}
