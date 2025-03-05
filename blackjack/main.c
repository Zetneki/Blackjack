#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "conio.h"
#define N 52

int main() {

    printf("--------------------------------------BLACKJACK---------------------------------------\n");

    printf("Udvozlom!\n\nVeletlenszeru ertekeket fog felhuzni egy paklibol.\n"
           "A cel, hogy ne lepje tul a 21 erteket, es nagyobb osszeget huzzon, mint az oszto.\n");
    printf("\nNyomja meg az entert az inditashoz.\n");
    getch();
    system("cls");

    jump:

    srand(time(0));

    FILE* f = fopen("pakli.txt", "w");

    int a = 0;

    for (int i = 0; i < N; ++i) {
        a = rand() % 10 + 1;
        fprintf(f, "%d ", a);
    }

    fclose(f);

    int lapok[N];
    int osszeg = 0;

    FILE* g = fopen("pakli.txt", "r");

    for (int i = 0; i < N; ++i) {
        fscanf(f, "%d", &lapok[i]);
    }

    fclose(g);

    char valasz[5];

    for (int i = 0; i < N/2; ++i) {

        osszeg += lapok[i];

        printf("--------------------------------------BLACKJACK---------------------------------------\n");

        printf("\nOn a %d-es szamot huzta.\nKezeben levo lapok erteke %d.\n", lapok[i], osszeg);
        if (osszeg > 21) {
            printf("\n\nOn kiesett.\n");
            printf("\n\nSzeretne ujra jatszani? (igen/nem)\n");
            scanf("\n%[^\n]s", valasz);
            if (strcmp(valasz, "igen") == 0) {
                system("cls");
                goto jump;
            }
            getch();
            return 0;
        } else if (osszeg == 21) {
            printf("\n\nOn nyert.\nKartyainak osszege: %d\n", osszeg);
            printf("\n\nSzeretne ujra jatszani? (igen/nem)\n");
            scanf("\n%[^\n]s", valasz);
            if (strcmp(valasz, "igen") == 0) {
                system("cls");
                goto jump;
            }
            getch();
            return 0;
        } else if (osszeg < 21) {
            printf("A kezeben levo eddigi lapok ertekei: ");
            for (int j = 0; j <= i; ++j) {
                printf("%d ", lapok[j]);
            }
            printf("\n\nSzeretne meg huzni lapot? (igen/nem)\n");
            scanf("\n%[^\n]s", valasz);
            system("cls");

            if (strcmp(valasz, "nem") == 0) {
                printf("--------------------------------------BLACKJACK---------------------------------------\n\n");
                printf("A jatek soran megszerzett lapok ertekei: ");
                for (int j = 0; j <= i; ++j) {
                    printf("%d ", lapok[j]);
                }
                printf("\nEzek osszege: %d", osszeg);
                break;
            }
        }
    }

    int ertek = 0;

    for (int i = N/2; i < N; ++i) {

        ertek += lapok[i];
        if (ertek > 21) {
            printf("\n\nAz oszto kiesett, on nyert.\nAz oszto kartyainak erteke: %d\n", ertek);
            break;
        } else if (ertek <= 21 && ertek > osszeg) {
            printf("\n\nAz oszto nyert, on kiesett.\nAz oszto kartyainak erteke : %d\n", ertek);
            break;
        } else if (ertek == osszeg) {
            printf("\n\nAz eredmeny dontetlen.\nAz oszto kartyainak erteke : %d\n", ertek);
            break;
        }
    }

    printf("\n\nSzeretne ujra jatszani? (igen/nem)\n");
    scanf("\n%[^\n]s", valasz);
    if (strcmp(valasz, "igen") == 0) {
        system("cls");
        goto jump;
    }
    getch();
    return 0;
}
