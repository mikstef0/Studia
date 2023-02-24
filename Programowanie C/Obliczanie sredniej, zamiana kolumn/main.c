/* MIKOLAJ STEFANISZYN 123A TEST 6 DN. 19/12/2019 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //2


double zad1();
void zad2(int n);
void menu();

int main()
{
    double *tab;
    tab=(double*)malloc(10*sizeof(double)); //tablica do zad.1

    srand(time(NULL));
    int wybor=3;
    int n;

    do
    {

        switch(wybor)
        {
            case 1: system("CLS"); printf("Podaj kolejno 10 liczb:\n");
                    for(int i=0; i<10; i++) { scanf("%lf", &tab[i]); /*printf("%lf", tab[i]);*/ }
                    printf("\nSrednia wynosi: %lf", zad1(tab)); printf("\n");


                 wybor=3; printf("\n"); system("pause"); system("CLS"); break;
            case 2: system("CLS"); printf("Podaj n: "); scanf("%d", &n); zad2(n);  wybor=3; printf("\n"); system("pause"); system("CLS"); break;
            case 3: menu(); scanf("%d", &wybor); break;

        }

    }
    while(wybor!=0);

    free(tab); //usuniecie tablicy do zad.1
    return 0;
}


double zad1(double *tab)
{
    double srednia=0;
    for(int i=0; i<10; i++) { srednia=srednia+tab[i]; /*printf("%lf ", srednia);*/ }
    srednia=srednia/10;
    return srednia;

}

void zad2(int n)
{
    double *tymcz;
    tymcz=(double*)malloc(sizeof(double));
    double maks=10, mini=0;
    double **tab2;
    tab2=(double**)malloc(n*sizeof(double*));
    for(int i=0; i<n; i++) { tab2[i]=(double*)malloc(n*sizeof(double)); }

    printf("Wygenerowana losowa tablica:\n\n");
        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {

                tab2[i][j]=(double)rand()/RAND_MAX*(maks-mini)+mini;
                printf("%lf ", tab2[i][j]);
            } printf("\n");
        }

    printf("\nTablica po zamianie miejscami przekatnych:\n\n");
        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {

                if(i==j)
                {
                    *tymcz=tab2[i][j];
                    tab2[i][j]=tab2[i][n-j-1];
                    tab2[i][n-j-1]=*tymcz;
                }
            }
        }


        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {


                printf("%lf ", tab2[i][j]);
            } printf("\n");
        }


     for(int i=0; i<n; i++) { free(tab2[i]); }
    free(tab2);
    free(tymcz);

}

void menu()
{
    printf("Menu:\n1 - zadanie 1.1\n2 - zadanie 2\n0 - wyjscie\n\n");
}
