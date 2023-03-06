using namespace std;





template<typename T>
class tablica
{
public:
    tablica()
    {
        rozmiar=1;
        ile=0;
        tab = new T[rozmiar];
    }
    ~tablica()
    {
        delete [] tab;
    }



    void dodaj(const T& dane)
    {
        if(ile<rozmiar)
        {
        tab[ile]=dane;
        ile++;
        }

        else
        {
        T* temp;
        temp = new T[ile];
        for(int i=0; i<ile; i++)
            {
            temp[i]=tab[i];
            }
        delete [] tab;
        rozmiar=rozmiar*2;
        tab = new T[rozmiar];
        for(int i=0; i<ile; i++)
            {
            tab[i]=temp[i];
            }
        tab[ile]=dane;
        ile++;
        }

    }


    T& zwroc_i(int indeks)
    {
     if(indeks<ile)
     {      return tab[indeks];    }
     else
     {      throw((string)"niepowodzenie");   }

    }


    void podmien(int indeks, const T& dane)
    {
    if(indeks<ile)
     {      tab[indeks]=dane;    }
     else
     {      throw((string)"niepowodzenie");   }

    }


    void wyczysc()
    {
    delete [] tab;
    ile=0;
    rozmiar=1;
    tab = new T[rozmiar];

    }

    string to_string(int liczba)
        {
        string tnapis;



       tnapis=tnapis+"\nLiczba elementów listy: ";
       tnapis=tnapis+std::to_string(ile);
       tnapis=tnapis+"\n";
       tnapis=tnapis+"Pierwsze ";
       tnapis=tnapis+std::to_string(liczba);
       tnapis=tnapis+" elementow:\n";

     //   lis+= to_string(n);
        for(int i=0;i<liczba;i++)
        {
        tnapis=tnapis+std::to_string(zwroc_i(i).field_1);
        tnapis=tnapis+" ";
        tnapis=tnapis+zwroc_i(i).field_2;
        tnapis=tnapis+"\n";
        }
            return tnapis;
        }


        void posortuj()
        {
        T* temp;
        temp = new T[1];

        for(int i=0;i<ile-1;i++)
        {
            for(int j=1;j<ile-i;j++)
            {
            if(!(tab[j]>tab[j-1]))
                {
                temp[0]=tab[j];
                tab[j]=tab[j-1];
                tab[j-1]=temp[0];
                }
            }

        }
            delete temp;

        }



private:
    int ile;
    int rozmiar;
    T* tab;
};




