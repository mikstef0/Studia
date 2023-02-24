#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "naglowek.h"


int licz()
{
    static int a=0;
    if (a==8) a=0;
    a++;
    return a;
}


static void Menu()
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
	 	printf("%d. Stworz nowa baze studentow \n", licz());
	 	printf("%d. Stworz baze i wpisz wykaz ocen z pliku \n", licz());
	 	printf("%d. Dodaj studenta \n", licz());
	 	printf("%d. Usun studenta \n", licz());
	 	printf("%d. Wpisz ocene losowemu studentowi \n", licz());
	 	printf("%d. Usun ocene loswemu studentowi \n", licz());
	 	printf("%d. Pokaz wykaz ocen \n", licz());
	 	printf("%d. Wypisz wykaz ocen do pliku \n", licz());
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
		  	case 3:
				Dodaj_Studenta(&studenci1, &ilosc);
				printf("Dodano do bazy jednego studenta.\n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 4:
				Usun_Studenta(&studenci1, &ilosc);
			//	printf("Usunieto losowego studenta z bazy. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 5:
				Dodaj_Ocene_Studentowi(studenci1, ilosc);
				printf("Dopisano jedna ocene losowemu studentowi. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 6:
				Usun_Ocene_Studentowi(studenci1, ilosc);
			//	printf("Usunieto jedna ocene losowemu studentowi. \n");
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
		  	case 7:
				Pokaz_Studentow(studenci1, ilosc);
		  		while (( ch = getchar()) != '\n');
		  		system("cls");
		  		break;
            case 8:
				Zapisz_Studentow_Plik(studenci1, ilosc);
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

void PokazMenu()
{
    Menu();
}
