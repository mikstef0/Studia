#ifndef NAGLOWEK_H_INCLUDED
#define NAGLOWEK_H_INCLUDED

#define rozmiar 192


struct Ocena {
	int  wartosc;
	int  waga;
};

struct Student {
	int  liczba_ocen;
	struct Ocena **ocena;
};

int licz();
void PokazMenu();
void Stworz_Studentow(struct Student***, const int);
void Dodaj_Studenta(struct Student***, int *);
void Usun_Studenta(struct Student***, int *);
void Dodaj_Ocene_Studenowi(struct Student* const * const, const int);
void Usun_Ocene_Studentowi(struct Student* const * const, const int);
void Pokaz_Studentow(struct Student * const * const , const int);
void Zwolnij_Pamiec(struct Student***, int *);
static void Menu();
void Dodaj_Ocene_Studentowi2(struct Student *const * const studenci, int komu, int oc, int wag);
void Stworz_Studentow2(struct Student*** studenci, const int ilosc);
void Stworz_Studentow3(struct Student*** studenci, const int ilosc);
void Zapisz_Studentow_Plik(struct Student * const * const studenci, int ilosc);
void Wpisz_Studentow_Plik(struct Student*** studenci1, const int ilosc);

#endif // NAGLOWEK_H_INCLUDED
