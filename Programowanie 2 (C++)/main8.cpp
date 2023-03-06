/////////////////////////////////////////
// Mikolaj Stefaniszyn 113A 06.01.2020 //
/////////////////////////////////////////

using namespace std;

#include <iostream>
#include <vector>
#include <list>


class Person
{
public:
	string name, surname;
public:
	Person()
	{	};
	Person(string n, string s) : name(n), surname(s)
	{	}

	void print()
	{
		cout<<surname<< " "<< name<<" ";
	}

	bool operator<(const Person& os) const
	{
		return (surname<os.surname);
	}
};


void enter(Person* os, int nr)
{
	cout<<"Podaj imie naziwsko "<<nr<<". osoby: ";
	string im, naz;
	cin>>im;
	cout<<endl;
	os->name=im;
	cin>>naz;
	os->surname=naz;
}

void print(list<Person>* lista)
{
	list<Person>::iterator it;
	for (it = lista->begin(); it != lista->end(); it++)
    { cout<<it->surname <<" "<< it->name <<" "<<endl; }
	cout<<endl;
}

bool compare(Person& first, Person& second)
{
	if(first.surname!=second.surname)
    return (first.surname<second.surname);
	else return(first.name<second.name);
}


int main()
{
    Person osoby[5];
    for(int i=0;i<5;i++)
	{ enter(&osoby[i], i+1); }
	std::list<Person> lista;
	for(int i=0;i<5;i++) {
	lista.push_back(osoby[i]); }
	cout<<"Lista wprowadzona: "<<endl;
	print(&lista);
	lista.sort(compare);
	cout<<"Posortowana lista:"<<endl;
	print(&lista);

	return 0;
}
