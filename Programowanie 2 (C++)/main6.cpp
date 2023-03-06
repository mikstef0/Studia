/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 14.05.2020 //
/////////////////////////////////////////

#include <iostream>


using namespace std;

class INT
{
    private:
    string s;
    public:
    int liczba;
    void getliczba();
};

void INT::getliczba()
{
    cout<<"Podaj liczbe: ";
    cin>>s;
    bool samecyfry=true;
    for(int i=0;i<s.length();i++)
    {if(s[i]<48 || s[i]>57) {samecyfry=false;} }
    if(samecyfry==true)
    {
    liczba=atoi(s.c_str());
    }
    else
    {
    s="to nie liczba\n";
    throw s;
    }


}

int main()
{
    INT a;

while("nietypowa nieskonczona petla")
{
    try
    {
    a.getliczba();
    cout<<endl;
    }
    catch(string s)
    {
    cout<<s<<endl;
    }
}

    return 0;
}
