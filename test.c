#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");


    char kk[101];  
    char ll[101];  
    size_t len_hladany = strlen(argv[1]);
    int riadok_cislo = 0;

    while (fgets(kk, sizeof(kk), f)) {
        riadok_cislo++;

    kk[strcspn(kk, "\n")] = '\0';

        size_t len_riadku = strlen(kk);
        if (len_hladany > len_riadku) continue; // hľadaný string je dlhší než riadok

        for (size_t i = 0; i <= len_riadku - len_hladany; i++) {
            // Bezpečné kopírovanie
            strncpy(ll, kk + i, len_hladany);
            ll[len_hladany] = '\0'; // ukonči substring

            if (strcmp(ll, argv[1]) == 0) {
                printf("Najdeny string '%s' v riadku %d: %s\n", ll, riadok_cislo, kk);
            }
        }
    }

    fclose(f);
    return 0;
}
