#include<iostream>
using namespace std;

template<class T>
class drzewo
{
private:
    struct wezel
    {
        T dane;
        wezel* lewy;
        wezel* prawy;
        wezel* rodzic;
    //    int poziom=0;
        int indeks=0;

    };




    void dodaj_wezel(wezel *&wezel_wsk, wezel *&nowy, int indeks)
    {
        if (wezel_wsk == nullptr)
        {
            wezel_wsk = nowy;
        }
        else if (nowy->dane < wezel_wsk->dane)
        {
            dodaj_wezel(wezel_wsk->lewy, nowy, indeks);
      //      nowy->poziom++;
        }
        else
        {
            dodaj_wezel(wezel_wsk->prawy, nowy, indeks);
     //       nowy->poziom++;
        }
        nowy->indeks=indeks;
 //       if(nowy->poziom>wysokosc) wysokosc=nowy->poziom;


    }
    void usun_drzewo(wezel* wezel_wsk)
    {
        if(wezel_wsk)
        {
            if(wezel_wsk->lewy)
                usun_drzewo(wezel_wsk->lewy);
            if(wezel_wsk->prawy)
                usun_drzewo(wezel_wsk->prawy);
            delete wezel_wsk;
        }
    }


    void usun_wezel(wezel *&wezel_wsk)
    {
            wezel *temp = nullptr;
            if(wezel_wsk==nullptr)
                cout << "Nie mozna usunac pustego wezla"<<endl;
            else if(wezel_wsk->prawy==nullptr)
            {
                temp=wezel_wsk;
                wezel_wsk=wezel_wsk->lewy;
                delete temp;
            }
            else if(wezel_wsk->lewy==nullptr)
            {
                temp=wezel_wsk;
                wezel_wsk=wezel_wsk->prawy;
                delete temp;
            }



            /* else
              {
                  temp=wezel_wsk->prawy;
                  while(temp->lewy)
                      temp=temp->lewy;

                  temp->lewy=wezel_wsk->lewy;
                  temp = wezel_wsk;

                  wezel_wsk = wezel_wsk->prawy;
                  delete temp; */


                          temp=wezel_wsk->lewy;
                        while(temp->prawy)
                            temp=temp->prawy;

                        temp->lewy=wezel_wsk->prawy;
                        temp = wezel_wsk;

                        wezel_wsk = wezel_wsk->lewy;
                        delete temp;




        }




        void in_order(wezel *wezel_wsk) const
        {
            if(wezel_wsk)
            {
                in_order(wezel_wsk->lewy);
                cout<< wezel_wsk->dane<<endl;
                in_order(wezel_wsk->prawy);
            }

        }



        void to_string(wezel *wezel_wsk, int poziom=0) const // inorder
        {

            if(wezel_wsk)
            {
                to_string(wezel_wsk->lewy, poziom+1);
                if(!(wezel_wsk->lewy==nullptr) && !(wezel_wsk->prawy==nullptr))
                {
                    cout<<wezel_wsk->indeks<<" [L: "<<wezel_wsk->lewy->indeks<<" R: "<<wezel_wsk->prawy->indeks<<" lvl: "<<poziom<<"] dane: "<<wezel_wsk->dane<<endl;
                }
                if((wezel_wsk->lewy==nullptr) && !(wezel_wsk->prawy==nullptr))
                {
                    cout<<wezel_wsk->indeks<<" [L: "<<"N"<<" R: "<<wezel_wsk->prawy->indeks<<" lvl: "<<poziom<<"] dane: "<<wezel_wsk->dane<<endl;
                }
                if(!(wezel_wsk->lewy==nullptr) && (wezel_wsk->prawy==nullptr))
                {
                    cout<<wezel_wsk->indeks<<" [L: "<<wezel_wsk->lewy->indeks<<" R: "<<"N"<<" lvl: "<<poziom<<"] dane: "<<wezel_wsk->dane<<endl;
                }
                if((wezel_wsk->lewy==nullptr) && (wezel_wsk->prawy==nullptr))
                {
                    cout<<wezel_wsk->indeks<<" [L: "<<"N"<<" R: "<<"N"<<" lvl: "<<poziom<<"] dane: "<<wezel_wsk->dane<<endl;
                }
                to_string(wezel_wsk->prawy, poziom+1);
            }


        }




        void pre_order(wezel *wezel_wsk) const
        {
            if(wezel_wsk)
            {
                cout<< wezel_wsk->dane<<endl;
                pre_order(wezel_wsk->lewy);
                pre_order(wezel_wsk->prawy);
            }

        }




public:
        wezel* korzen=nullptr;
        drzewo()
        {
            korzen = nullptr;
        }

        ~drzewo()
        {
            usun_drzewo(korzen);
        }

        void dodaj(T dane)
        {
            int indeks;
            wezel *nowy = nullptr;
            nowy = new wezel;
            nowy->dane = dane;
            nowy->lewy = nowy->prawy = nullptr;

            indeks=ind++;
            ile++;
            dodaj_wezel(korzen, nowy, indeks);

        }

        wezel *&wyszukaj(T dane)
        {
            wezel *wezel_wsk = korzen;

            while(wezel_wsk)
            {
                if(wezel_wsk->dane == dane)
                    return wezel_wsk;

                else if (dane < wezel_wsk->dane)
                    wezel_wsk=wezel_wsk->lewy;
                else
                    wezel_wsk=wezel_wsk->prawy;

            }
            // throw("niepowodzenie");
            throw((string)"niepowodzenie");

        }

        void usun_wezel1(T dane, wezel *&wezel_wsk)
        {
             if(dane < wezel_wsk->dane)
                 usun_wezel1(dane, wezel_wsk->lewy);
             else if (dane > wezel_wsk->dane)
                 usun_wezel1(dane, wezel_wsk->prawy);
             else usun_wezel(wezel_wsk);

        }


        void usun(T dane)
        {
            usun_wezel1(dane, korzen);
            ile--;
        }


        void in_order() const
        {
            in_order(korzen);
        }

        void pre_order() const
        {
            pre_order(korzen);
        }

        void to_string() const
        {
            to_string(korzen);
            cout<<"Wysokosc drzewa: "<<wysokosc<<endl;
            cout<<"Liczba elementow: "<<ile<<endl;
        }

        void usun_drzewo()
        {
            usun_drzewo(korzen);
        }




        int ind=0;
        int wysokosc=0;
        int ile=0;

    };























