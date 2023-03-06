using namespace std;


struct some_object
{
    int field_1;
    char field_2;
    bool operator < (const some_object& so) const
    {
    }
    void pokaz()
    {
    cout << "Pole 1: "<< field_1 <<endl;
    cout << "Pole 2: "<< field_2 <<endl;
    }
};

template<typename T>
class wezel
{
public:
//reszta interfejsu
 /*   const T& pobierz_dane() const
    {
        return dane;
    }
    T& pobierz_dane()
    {
        return dane;
    } */
   // void pokazw(const some_object &dane){
   // dane.pokaz(); }
    //}

    wezel<T> *popr, *nast;
    T dane;
};

template<typename T>
class lista
{
public:
    lista()
    {
        glowa = nullptr;
        ogon = nullptr;
        n=0;
    }
    ~lista();
    //reszta interfejsu
    void dodaj(const T& dane)
   /* {
      //  wezel<T>* w=new wezel<T>(dane);
        ogon= new wezel<T>;

        //w->popr=nullptr;
    //    w->dane=dane;


        if(glowa!=nullptr)
        {
            glowa=ogon;
        }
        else ogon->popr->nast=ogon;

    } */
    {
        wezel<T>* temp = new wezel<T>;
        temp->dane = dane;
        temp->nast = nullptr;
        if (glowa == nullptr)
        {
            glowa = temp;
            ogon = temp;
        }
        else {
            ogon->nast = temp;
            temp->popr = ogon;
            ogon = ogon->nast;
        }
        n++;

    }

    void wstaw_pocz(const T& dane)
    {
        wezel<T>* temp = new wezel<T>;
        temp->dane = dane;
        temp->nast = nullptr;
        if (glowa == nullptr)
        {
            glowa = temp;
            ogon = temp;
        }
        else {
            glowa->popr=temp;
            temp->nast=glowa;
            glowa=glowa->popr;
        }
        n++;

    }


    void usunpierwszy()
    {
        wezel<T>* usuwany=new wezel<T>;
        usuwany=glowa;
        glowa=glowa->nast;
        delete usuwany;
    }

        void usunostatni()
    {
        wezel<T>* usuwany=new wezel<T>;
        usuwany=ogon;
        ogon=ogon->popr;
        delete usuwany;
    }

        void pokaz_i()
    {
        wezel<T>* biezacy=new wezel<T>;
        biezacy=glowa;
        while(biezacy!=nullptr)
        {
        biezacy->dane.pokaz();

     //   cout << biezacy->dane << endl;
        biezacy=biezacy->nast;
        }
    }



private:
    wezel<T> *glowa, *ogon;
    int n;
};




