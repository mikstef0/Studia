/* MIKO£AJ STEFANISZYN gr. 123A TEST NR 3 DN. 28/11/2019 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main()
{
    /* ZADANIE 2.1 */
    int dalej=-1;
    int d=1;
    int karta=-1;
    int karta1; int karta2;
    int punkty1=0; int punkty2=0;
    srand(time(NULL));
    char karty[6][12]={"dziewiatka", "dziesiatka", "walet", "dama", "krol", "as"};
    int punktacja[6]={0,10,2,3,4,11};


    printf("Gra w oczko. Wybierz dowolna karte - Wprowadz odpowiednio:\n");
    printf("0 - 9 (0 pkt)\n1 - 10 (10 pkt)\n2 - walet (2 pkt)\n3 - dama (3 pkt)\n4 - krol (4 pkt)\n5 - as (11 pkt)\n\n");
    do
    { scanf("%d", &karta); }
    while(karta!=0 && karta!=1 && karta!=2 && karta!=3 && karta!=4 && karta!=5);
    karta1=karta;
    karta2=rand()%6;
    printf("Twoja karta: %s (%d pkt)\n", karty[karta1], punktacja[karta1]);
    printf("Karta komputera: %s (%d pkt)\n\n", karty[karta2], punktacja[karta2]);
    punkty1+=punktacja[karta1];
    punkty2+=punktacja[karta2];
    system("pause");



    while(dalej!=0) {
        system("cls");
        printf("Twoje punkty: %d\n", punkty1);
        printf("Punkty komputera: %d\n\n", punkty2);
        printf("Czy chcesz grac dalej? Wybierz 1, aby grac dalej lub 0, aby zakonczyc gre:\n");
        scanf("%i", &dalej);
        if(dalej==1)
        {
    karta1=rand()%6;
    karta2=rand()%6;
    system("cls");
    printf("Twoja karta: %s (%d pkt)\n", karty[karta1], punktacja[karta1]);
    printf("Karta komputera: %s (%d pkt)\n\n", karty[karta2], punktacja[karta2]);
    punkty1+=punktacja[karta1];
    punkty2+=punktacja[karta2];
    system("pause");
        }
    }

   printf("Twoje punkty: %d\n", punkty1);
   printf("Punkty komputera: %d\n\n", punkty2);


    if(punkty1==punkty2 || (punkty2>21 && punkty1>21)) { printf("Remis.\n"); }
    else if(punkty1>21) { printf("Zwyciezca: komputer.\n"); }
    else if(punkty2>21) { printf("Zwyciezca: Ty.\n"); }
    else if(punkty1>punkty2) { printf("Zwyciezca: Ty.\n"); }
    else  { printf("Zwyciezca: komputer.\n"); }
    printf("\n");




    return 0;
}
