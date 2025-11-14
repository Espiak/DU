#include <stdio.h>
int pocet[9];

int invalidne_cislo;

void scanovanie(int rozsah ,int hodnota){

    if (hodnota == rozsah)
            {
                pocet[0] = pocet[0] + 1;
            }
            else if (hodnota == rozsah + 1)
            {
                pocet[1] = pocet[1] + 1;
            }
            else if (hodnota == rozsah + 2)
            {
                pocet[2] = pocet[2] + 1;
            }
            else if (hodnota == rozsah + 3)
            {
                pocet[3] = pocet[3] + 1;
            }
            else if (hodnota == rozsah + 4)
            {
                pocet[4] = pocet[4] + 1;
            }
            else if (hodnota == rozsah + 5)
            {
                pocet[5] = pocet[5] + 1;
            }
            else if (hodnota == rozsah + 6)
            {
                pocet[6] = pocet[6] + 1;
            }
            else if (hodnota == rozsah + 7)
            {
                pocet[7] = pocet[7] + 1;
            }
            else if (hodnota == rozsah + 8)
            {
                pocet[8] = pocet[8] + 1;
            }
            else
            {
                pocet[9] = pocet[9] + 1; // neinvalidne cisla
            }
}
void vykreslenie(int m){
    int j = 0;
 for (int k = m; k < m + 9; k++)
        {

            if(m+8 > 10 && m+8 < 100){
            printf("%d", k);
            }else if(m+8 > 100 && m+8 < 1000){
            printf("%3d", k);
            }else if(m+8 > 1000 && m+8 < 10000){
            printf("%4d", k);
            }else if(m+8 > 10000 && m+8 < 100000){
            printf("%5d", k);
            }else if(m+8 > 100000 && m+8 < 1000000){
            printf("%6d", k);
            }else
            {printf("%d", k);}


            if (pocet[j] >= 1)
                {
                    printf(" ");
                }
            for (int hastagy = 0; hastagy < pocet[j]; hastagy++)
            {
               
                
                printf("#");
            }
            j = j + 1;
            printf("\n");
        }

        if (pocet[9] != 0)
        {
            printf("invalid: ");
            for (int nein = 0; nein < pocet[9]; nein++)
            {
                printf("#");
            }
            printf("\n");
        }
}



int main()
{
    int m, n;
    char smer;
    int cislo;
    scanf("%c", &smer);
  

    if (smer == 'v')
    {
    }
    else if (smer == 'h')
    {   
        scanf("%d", &n); // pocet hodnout na zapocet do stlpcu
        scanf("%d", &m); // zaciatocna hodnota
        for (int l = 0; l < n; l++)
        {
            scanf("%d", &cislo);
            scanovanie(m,cislo);
        }

        vykreslenie(m);
       
        return 0;
    }
    else
    {
        printf("Neplatny mod vykresleni");
        printf("\n");
        return 1;
    }

    
}
