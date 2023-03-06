/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 23.05.2020 //
/////////////////////////////////////////

#include <iostream>
#include <vector>


using namespace std;

int main()
{
    // 1:
    vector<int> a={3,50,10};
    cout<<"\n1) Utworzono wektor a i zainicjalizowano wart. 3,50,10.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;

   //2:
    a.insert( a.begin(),-50);
    cout<<"\n2) Na poczatku wektora a dopisano -50.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;

    //3:
    a.insert(a.end(), 3, 1);
    cout<<"\n3) Na koncu wektora a dopisano 3 jedynki.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;

    //4:
    vector<int> b;
    for(int i=1;i<=4;i++) {
    b.push_back(i); }
    cout<<"\n4) Utworzono wektor b. Wektor b wypelniono wartosciami 1,2,3,4.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"Wektor b:  ";
    for(int i=0; i<b.size();i++) cout<<b[i]<<" "; cout<<endl;

    //5:
    b.insert(b.begin()+2,a.begin(),a.begin()+3);
    cout<<"\n5) Do wektora b na od 2. pozycji dopisano 3 pierwsze elementy wektora a.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"Wektor b:  ";
    for(int i=0; i<b.size();i++) cout<<b[i]<<" "; cout<<endl;
//    for(int i=0; i<7;i++) cout<<b[i]<<" ";

    //6:
    int tab[5]={-1,-2,-3,-4};
    cout<<"\n6) Utworzono tablice 5-elementowa tab i zainicjalizowano ja wartosciami: -1,-2,-3,-4.\n ";


    //7:
    a.insert(a.end(),tab,tab+5);
    cout<<"\n7) Do wektora a dopisano 5 elementów tablicy: -4, -3, -2, -1, 0.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"Wektor b:  ";
    for(int i=0; i<b.size();i++) cout<<b[i]<<" "; cout<<endl;

    //8:
    a.erase(a.begin()+1, a.end()-1);
    cout<<"\n8) Z wektora a usunieto elementy pomiedzy pierwszym a ostatnim.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"Wektor b:  ";
    for(int i=0; i<b.size();i++) cout<<b[i]<<" "; cout<<endl;

    //9:
    a.swap(b);
    cout<<"\n9) Zamieniono wektor b z a.\nWektor a:  ";
    for(int i=0; i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"Wektor b:  ";
    for(int i=0; i<b.size();i++) cout<<b[i]<<" "; cout<<endl<<endl;

    cout<<"To jest juz koniec, nie ma juz nic."<<endl;

    return 0;
}
