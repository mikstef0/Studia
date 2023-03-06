#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double srednia_p(int tab[]);
double srednia_np(int tab[]);
double srednia_nieuj(int tab[]);
double srednia_wok(int tab[], int k);
void zad2(double* tab[], int n);
double const mini=0.0001;
double const maxi=1.5;


int main()
{

    srand(time(NULL));
    int tab[10];
    int wybor=6;
    int n;
    double wynik;
    int k;
    printf("Podaj wielkosc tablicy n x n w zadaniu drugim: ");
    scanf("%d", &n);
    double tab2[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           tab2[i][j]=(double)rand()/RAND_MAX*(mini-maxi)+mini;

        }
    }

printf("Zadanie 1:\n");
    for(int i=0; i<10; i++)
    {
        printf("Podaj %d. liczbe: ", i+1);
        scanf("%d", &tab[i]);
    }

    do
    {
     switch(wybor){
     case 1: wynik=srednia_p(tab); printf("%lf \n", wynik); break;
     case 2: wynik=srednia_np(tab); printf("%lf \n", wynik); break;
     case 3: wynik=srednia_nieuj(tab); printf("%lf \n", wynik); break;
     case 4: printf("Wprowadz k: "); getchar(); scanf("&d", &k);
         printf("%lf \n",srednia_wok(tab, k));   break;
     case 5: zad2(tab2, n); break;
     case 6: printf("Menu: \n"); printf("1 - srednia arytm. elementow parzystych\n");
                printf("2 - srednia arytm. elementow niepatzystych\n");  printf("3 - srednia arytm. elementow nieujemnych\n");
                printf("4 - srednia arytm. elementow wiekszych od wybranej liczby\n");  printf("5 - zadanie nr 2\n"); break;


     }
     scanf("%d", &wybor);
    }
    while (wybor!=0);

    return 0;
}

double srednia_p(int tab[])
{
    double srednia=0; int ile=0;
   for(int i=0; i<10; i++) {
        if(tab[i]%2==0) {
   srednia=srednia+tab[i]; ile++; } }
   srednia=srednia/ile;
   return srednia;
}

double srednia_np(int tab[])
{
    double srednia=0; int ile=0;
   for(int i=0; i<10; i++) {
        if(tab[i]%2!=0) {
   srednia=srednia+tab[i]; ile++; } }
   srednia=srednia/ile;
   return srednia;
}

double srednia_nieuj(int tab[])
{
    double srednia=0; int ile=0;
   for(int i=0; i<10; i++) {
        if(tab[i]>=0) {
   srednia=srednia+tab[i]; ile++; } }
   srednia=srednia/ile;
   return srednia;
}

double srednia_wok(int tab[], int k)
{
    double srednia=0; int ile=0;
   for(int i=0; i<10; i++) {
        if(tab[i]-k>=0) {
   srednia=srednia+tab[i]; ile++; } }
   srednia=srednia/ile;
   return srednia;
}

void zad2(double* tab2[], int n)
{

}

