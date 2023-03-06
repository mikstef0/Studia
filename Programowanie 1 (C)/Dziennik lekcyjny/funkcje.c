#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "naglowek.h"



void Stworz_Studentow(struct Student*** studenci, const int ilosc) {
	static int count = 0;
	count++;
	if ( count == 1 ) {
		struct Student** temp = (struct Student **)
                                         malloc(sizeof(struct Student*)*ilosc);
		for(int i=0; i< ilosc; i++) {
		   temp[i] = (struct Student *) malloc(sizeof(struct Student));
		}
		// początkowa ilość punktów
		int liczba_ocen = 1;
		for(int i=0; i< ilosc; i++) {
			struct Ocena** oceny = (struct Ocena **)
                                malloc(sizeof(struct Ocena*)*liczba_ocen);
			struct Ocena*  ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
			ocena->wartosc = rand()%4+2;
			ocena->waga = rand()%2+1;
			oceny[liczba_ocen-1] = ocena;
		   temp[i]->ocena = oceny;
			temp[i]->liczba_ocen = liczba_ocen;
		}
		*studenci = temp;
		printf("\n Utworzono baze studentow.");

	}
	else
		printf("\n Baza juz zostala utworzona.");
}

void Stworz_Studentow3(struct Student*** studenci, const int ilosc) {
	static int count = 0;
	count++;
	if ( count == 1 ) {
		struct Student** temp = (struct Student **)
                                         malloc(sizeof(struct Student*)*ilosc);
		for(int i=0; i< ilosc; i++) {
		   temp[i] = (struct Student *) malloc(sizeof(struct Student));
		}
		// początkowa ilość punktów
		int liczba_ocen = 0;
		for(int i=0; i< ilosc; i++) {
			struct Ocena** oceny = (struct Ocena **)
                                malloc(sizeof(struct Ocena*)*liczba_ocen);
			struct Ocena*  ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
			ocena->wartosc = rand()%4+2;
			ocena->waga = rand()%2+1;
			oceny[liczba_ocen-1] = ocena;
		   temp[i]->ocena = oceny;
			temp[i]->liczba_ocen = liczba_ocen;
		}
		*studenci = temp;
		printf("\n Utworzono baze studentow.");

	}
	else
		printf("\n Baza juz zostala utworzona.");
}

void Stworz_Studentow2(struct Student*** studenci, const int ilosc) {
	static int count = 0;
	count++;
	if ( count == 1 ) {
		struct Student** temp = (struct Student **)
                                         malloc(sizeof(struct Student*)*ilosc);
		for(int i=0; i< ilosc; i++) {
		   temp[i] = (struct Student *) malloc(sizeof(struct Student));
		}
		// początkowa ilość punktów
		int liczba_ocen = 1;
		for(int i=0; i< ilosc; i++) {
			struct Ocena** oceny = (struct Ocena **)
                                malloc(sizeof(struct Ocena*)*liczba_ocen);
			struct Ocena*  ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
			ocena->wartosc = 0;
			ocena->waga = 0;
			oceny[liczba_ocen-1] = ocena;
		   temp[i]->ocena = oceny;
			temp[i]->liczba_ocen = liczba_ocen;
		}
		*studenci = temp;
		printf("\n Utworzono baze studentow.");

	}
	else
		printf("\n Baza juz zostala utworzona.");
}

void Pokaz_Studentow(struct Student * const * const studenci, int ilosc) {
	for(int i=0; i< ilosc; i++) {
		int ile = studenci[i]->liczba_ocen;
		printf("\nStudent %d:", i);
		for(int j=0; j < ile; j++)
			printf("\n \t  Ocena: %d; Waga: %d;", studenci[i]->ocena[j]->wartosc, studenci[i]->ocena[j]->waga);
	}
}

void Zapisz_Studentow_Plik(struct Student * const * const studenci, int ilosc) {

    FILE *plik;
   plik = fopen("baza.txt","w");

    fprintf(plik,"%d", ilosc);
    for(int i=0; i< ilosc; i++) {
		int ile = studenci[i]->liczba_ocen;
		fprintf(plik, "%d", ile);
		for(int j=0; j < ile; j++)
			fprintf(plik, "%d%d", studenci[i]->ocena[j]->wartosc, studenci[i]->ocena[j]->waga);
	}
	fprintf(plik, "k\n\n");

	for(int i=0; i< ilosc; i++) {
		int ile = studenci[i]->liczba_ocen;
		fprintf(plik, "\nStudent %d:", i);
		for(int j=0; j < ile; j++)
			fprintf(plik, "\n \t  Ocena: %d; Waga: %d;", studenci[i]->ocena[j]->wartosc, studenci[i]->ocena[j]->waga);
	}
	fclose(plik);
	printf("Zapisano dane do pliku.");
}

void Wpisz_Studentow_Plik(struct Student*** studenci1, const int ilosc)
{
  //  Stworz_Studentow(&studenci1, ilosc);
  //  Zwolnij_Pamiec(&studenci1, &ilosc);

    FILE *plik;
    plik = fopen("baza.txt","r");

    if(plik==NULL)
    {
        printf("Blad odczytu pliku.\n");
    }
    else
    {
        char s[rozmiar];
        int l[rozmiar]={0};

        int gdzie=0;

       fgets(s, rozmiar, plik);
       //    puts(s);
//printf("T1");
           while(s[gdzie]!='k')
           {
            l[gdzie]=s[gdzie]-48;  /* printf("\n%c %d\n", s[gdzie], l[gdzie]); */ gdzie++;
           }
           l[gdzie]=-1;

           gdzie=1;


//      Stworz_Studentow2(&studenci1, l[0]);

      for(int i=0; i<l[0]; i++)
        {
                for(int j=0; j<l[gdzie]; j++)
                {
            //        printf("%d, %d, %d %d", i, l[gdzie], l[gdzie+2*j+1], l[gdzie+2*j+2] );
                   Dodaj_Ocene_Studentowi2(studenci1, i, l[gdzie+2*j+1], l[gdzie+2*j+2]);
               //    Dodaj_Ocene_Studentowi(studenci1, l[0]);
                }
                gdzie=gdzie+2*l[gdzie]+1;


        }

    }

 fclose(plik);
 printf("Wpisano dane z pliku.\n");
}


void Zwolnij_Pamiec(struct Student*** studenci, int *ilosc) {
	for(int i=0; i< *ilosc; i++) {
		int ile = (*studenci)[i]->liczba_ocen;
		for(int j=0; j < ile; j++)
			free((*studenci)[i]->ocena[j]);
		free((*studenci)[i]->ocena);
		free((*studenci)[i]);
	}
	free(*studenci);
	*ilosc = 0;
	*studenci = NULL;
}

void Usun_Studenta(struct Student***studenci, int *ilosc) {
	int size_new = *ilosc - 1;
	if ( size_new > 0 ) {
		struct Student** temp = (struct Student **)
                                    malloc(sizeof(struct Student*)*size_new);
		// kopiowanie figur
		for(int i=0; i< size_new; i++)
			temp[i] = (*studenci)[i];
		int size = (*studenci)[size_new]->liczba_ocen;
		// usunięcie punktów z figury
		for(int i=0; i< size; i++)
			free((*studenci)[size_new]->ocena[i]);
		// usunięcie kontenera punktów
		free((*studenci)[size_new]->ocena);
		// usunięcie figury
		free((*studenci)[size_new]);
		//
		*studenci = temp;
		*ilosc = size_new;
		printf("\n Usunieto z bazy jednego studenta.");
	}
	else
		printf("\n Baza nie moze byc pusta. Nie mozna usunac ostatniego studenta.");
}

void Dodaj_Studenta(struct Student*** studenci, int *ilosc) {
	int new_size = *ilosc + 1;
	struct Student** temp = (struct Student **)
                                    malloc(sizeof(struct Student*) * new_size);
	for(int i=0; i< *ilosc; i++) {
		temp[i] = (*studenci)[i];
	}
   temp[*ilosc] = (struct Student *) malloc(sizeof(struct Student));
	// początkowa ilość punktów
	int liczba_ocen = 1;
	struct Ocena** oceny = (struct Punkt **)
                                   malloc(sizeof(struct Ocena*)*liczba_ocen);
	struct Ocena*  ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
	ocena->wartosc = rand()%4+2;
    ocena->waga = rand()%2+1;
	oceny[liczba_ocen-1] = ocena;
	temp[*ilosc]->ocena = oceny;
	temp[*ilosc]->liczba_ocen = liczba_ocen;
	free(*studenci);
	*studenci = temp;
	*ilosc = new_size;
}

void Dodaj_Ocene_Studentowi(struct Student *const * const studenci, const int ilosc)
{
	int komu = rand()%ilosc;
	int size = studenci[komu]->liczba_ocen;
	struct Ocena** oceny = (struct Ocena **)
                                       malloc(sizeof(struct Ocena*)*(size+1));
	for(int i=0; i< size; i++) {
		oceny[i] = studenci[komu]->ocena[i];
	}
	free(studenci[komu]->ocena);
	struct Ocena* ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
	ocena->wartosc = rand()%4+2;
    ocena->waga = rand()%2+1;
   oceny[size] = ocena;
	size++;
	studenci[komu]->liczba_ocen = size;
	studenci[komu]->ocena = oceny;
	}

void Dodaj_Ocene_Studentowi2(struct Student *const * const studenci, int komu, int oc, int wag)
{
	int size = studenci[komu]->liczba_ocen;
	struct Ocena** oceny = (struct Ocena **)
                                       malloc(sizeof(struct Ocena*)*(size+1));
	for(int i=0; i< size; i++) {
		oceny[i] = studenci[komu]->ocena[i];
	}
	free(studenci[komu]->ocena);
	struct Ocena* ocena = (struct Ocena *) malloc(sizeof(struct Ocena));
	ocena->wartosc = oc;
    ocena->waga = wag;
   oceny[size] = ocena;
	size++;
	studenci[komu]->liczba_ocen = size;
	studenci[komu]->ocena = oceny;
	}

void Usun_Ocene_Studentowi(struct Student * const * const studenci, const int liczba_ocen)
{
	// Funkcja usuwa ostatni punkt z losowo wybranej figury
	int komu = rand()%liczba_ocen;
	int size = studenci[komu]->liczba_ocen;
	if (size > 0 ) {
		struct Ocena** oceny = (struct Ocena **)
                                        malloc(sizeof(struct Ocena*)*(size-1));
		for(int i=0; i< size-1; i++) {
			oceny[i] = studenci[komu]->ocena[i];
		}
		// usuwamy punkt (ostatni w kontenerze punktów)
		free(studenci[komu]->ocena[size-1]);
		// usuwamy stary kontener punktów
		free(studenci[komu]->ocena);
		studenci[komu]->liczba_ocen = size-1;
		studenci[komu]->ocena = oceny;
		printf("\n Usunieto jedna ocene losowemu studentowi.");
			}
	else
		printf("\n Nie mozna usunac oceny. Wybrany student nie ma juz ocen. ");
}
/*
void Menu()
{
	int ilosc = 3, wybor;
	char ilosc2;
	char ch;
	struct Student** studenci1 = NULL;
	srand(time(NULL));
	system("cls");
	srand ( time(NULL) );
	do
	{
		printf("Menu\n");
	 	printf("%d. Stworz baze studentow \n", licz());
	 	printf("%d. Dodaj studenta \n", licz());
	 	printf("%d. Usun studenta \n", licz());
	 	printf("%d. Wpisz ocene losowemu studentowi \n", licz());
	 	printf("%d. Usun ocene loswemu studentowi \n", licz());
	 	printf("%d. Pokaz wykaz ocen \n", licz());
	 	printf("%d. Wypisz wykaz ocen do pliku \n", licz());
	 	printf("%d. Wpisz wykaz ocen z pliku \n", licz());
	 	printf("0. Wyjscie \n");
	 	printf("\nWybierz opcje: ");
	 	scanf("%d",&wybor);
	 	ch = getchar();
	 	switch(wybor) {
			case 1:
		//		Stworz_Studentow(&studenci1, ilosc);
				Stworz_Studentow3(&studenci1, ilosc);

			//	printf("Baza studentow zostala stworzona \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 2:
				Dodaj_Studenta(&studenci1, &ilosc);
				printf("Dodano do bazy jednego studenta.\n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 3:
				Usun_Studenta(&studenci1, &ilosc);
			//	printf("Usunieto losowego studenta z bazy. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 4:
				Dodaj_Ocene_Studentowi(studenci1, ilosc);
				printf("Dopisano jedna ocene losowemu studentowi. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 5:
				Usun_Ocene_Studentowi(studenci1, ilosc);
			//	printf("Usunieto jedna ocene losowemu studentowi. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 6:
				Pokaz_Studentow(studenci1, ilosc);
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
            case 7:
				Zapisz_Studentow_Plik(studenci1, ilosc);
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
            case 8:
            //    Stworz_Studentow(&studenci1, ilosc);
            //    Zwolnij_Pamiec(&studenci1, &ilosc);
                {

                }

                FILE *plik=fopen("baza.txt", "r"); ilosc2=fgetc(plik); ilosc=ilosc2-48; fclose(plik);// printf("%c", ilosc2);
             //  Stworz_Studentow(&studenci1, ilosc);
             Stworz_Studentow3(&studenci1, ilosc);
				Wpisz_Studentow_Plik(studenci1, ilosc);
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		 	case 0:
		 		printf("Dziekuje. \n");
				Zwolnij_Pamiec(&studenci1, &ilosc);
		 		break;
		 	default:
		 		printf("Bledny wybor, sprobuj ponownie.\n");
		  		while (( ch = getchar()) != '\n');
				system("cls");
		 		break;
		 }
	} while (wybor != 0);
	printf("\n");
}
*/
