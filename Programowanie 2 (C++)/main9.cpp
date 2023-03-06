/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 07.06.2020 //
/////////////////////////////////////////

using namespace std;

#include <iostream>
#include <map>


void wypiszSTRINT(map<string,int>::iterator i1, map<string,int>::iterator i2)
{   map<string,int>::iterator it;
    for (it = i1; it!=i2; it++) {
    cout << it->first << " " << it->second << endl; }cout<<endl;}

void wypiszINTINT(map<int,int>::iterator i1, map<int,int>::iterator i2)
{   map<int,int>::iterator it;
    for (it = i1; it!=i2; it++) {
    cout << it->first << " " << it->second << endl; } cout<<endl;}

int main()
{



    //1
    map<string, int> m1={{"jeden", 1},{"dwa", 2},{"trzy", 3},{"cztery", 4},{"piec", 5}};
    cout<<"1. Zawartosc m1:"<<endl; wypiszSTRINT(m1.begin(),m1.end());
    //2
    map<string, int> m2(m1);
    cout<<"2. Zawartosc m2:"<<endl; wypiszSTRINT(m2.begin(),m2.end());
    //3
    map<string, int> m3;
    m3=m1;
    cout<<"3. Zawartosc m3:"<<endl; wypiszSTRINT(m3.begin(),m3.end());

    //4
    map<int, int, greater<int> > m4={{1,2},{2,4},{3,8},{4,16},{5,32},{6,64},{7,128},{8,256},{9,512},{10,1024}};
    cout<<"4. Zawartosc m4:"<<endl; wypiszINTINT(m4.begin(),m4.end());

    //5
    cout<<"5. Zawartosc m4[6]"<<endl;
    cout<<m4.find(6)->second<<endl<<endl;

    //6
    cout<<"6. Elementy m4 o kluczach od 2 do 8"<<endl;
    for(int i=2; i<=8; i=i+1)
    cout<<m4.find(i)->first<<' '<<m4.find(i)->second<<endl;
    cout<<endl;

    //7
    for(int i=2;i<=8;i++)
    m4.erase(m4.find(i));
    cout<<"7. Zawartosc m4:"<<endl; wypiszINTINT(m4.begin(),m4.end());

    /*cout<<endl;
    map<int,int>::iterator it;
    for (it=m4.begin(); it!=m4.end(); it++) {
    cout << it->first << " " << it->second << endl; }*/

    //8
    m1.swap(m3);
    cout<<"8. Zawartosc m1:"<<endl; wypiszSTRINT(m1.begin(),m1.end());

    //9

    //m3.insert(pair<string,int>("cztery",4) );

    m3.insert(m1.begin()++, m1.end()--);
    cout<<"9. Zawartosc m3:"<<endl; wypiszSTRINT(m3.begin(),m3.end());

    cout<<endl;

	return 0;
}
