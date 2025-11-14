#include <stdio.h>
#include <stdlib.h>
int posun(int smer, int stlpce, int pozicia_v_poli, int pozicia_v_stlpci, int riadky, int pozicia_v_riadku)
{
    if (smer == 1 && (stlpce - 1) * pozicia_v_stlpci < pozicia_v_poli) // dole cez okraj
    {
        pozicia_v_stlpci = pozicia_v_stlpci - stlpce;
        return pozicia_v_stlpci;
    }
    else if (smer == 1) // dole
    {
        pozicia_v_stlpci = pozicia_v_stlpci + 1;
        return pozicia_v_stlpci;
    }
    else if (smer == 2 && pozicia_v_stlpci * stlpce + stlpce == pozicia_v_poli) // v pravo  cez okraj
    {
        pozicia_v_riadku = pozicia_v_riadku - riadky;
        return pozicia_v_riadku;
    }
    else if (smer == 2) // v pravo
    {
        pozicia_v_riadku = pozicia_v_riadku + 1;
        return pozicia_v_riadku;
    }
    else if (smer == 3 && pozicia_v_poli < stlpce) // hore cez okraj
    {
        pozicia_v_stlpci = pozicia_v_stlpci - riadky;
        return pozicia_v_stlpci;
    }
    else if (smer == 3) // hore
    {
        pozicia_v_stlpci = pozicia_v_stlpci - 1;
        return pozicia_v_stlpci;
    }
    else if (smer == 4 && pozicia_v_stlpci * stlpce + 0 == pozicia_v_poli) // v lavo cez okraj
    {
        pozicia_v_riadku = pozicia_v_riadku + stlpce;
        return pozicia_v_riadku;
    }
    else if (smer == 4) // v lavo
    {
        pozicia_v_riadku = pozicia_v_riadku - 1;
        return pozicia_v_riadku;
    }
    return 0;
}

void nastavenie_hodnot(int stlpce, int riadky, char *pole)
{

    for (int z = 0; z < riadky; z++)
    {
        for (int i = 0; i < stlpce; i++)
        {
            int l = z * stlpce + i;
            pole[l] = '.';
        }
    }
}
void vypis(int stlpce, int riadky, char *pole)
{
    for (int z = 0; z < riadky; z++)
    {

        for (int i = 0; i < stlpce; i++)
        {
            int l = z * stlpce + i;
            printf("%c", pole[l]);
        }

        printf("\n");
    }
}

int main()
{
    int riadky, stlpce;
    scanf("%d", &riadky);
    scanf("%d", &stlpce);
    char *pole = (char *)malloc(riadky * stlpce * sizeof(char));
    int smer = 2;
    nastavenie_hodnot(stlpce, riadky, pole);
    char krok;
    int pozicia_v_stlpci = 0;
    int pozicia_v_riadku = 0;

    while (krok != 'x')
    {

        int pozicia_v_poli = pozicia_v_riadku * stlpce + pozicia_v_stlpci;

        scanf(" %c", &krok);

        if (krok == 'm')
        {
            if (smer == 1 || smer == 3)
            {
                pozicia_v_stlpci = posun(smer, stlpce, pozicia_v_poli, pozicia_v_stlpci, riadky, pozicia_v_riadku);
            }
            else if (smer == 2 || smer == 4)
            {
                pozicia_v_riadku = posun(smer, stlpce, pozicia_v_poli, pozicia_v_stlpci, riadky, pozicia_v_riadku);
            }
        }
        else if (krok == 'o')
        {
            pole[pozicia_v_poli] = 'o';
        }
        else if (krok == 'r')
        {
            smer = smer - 1;
            if (smer == 0)
            {
                smer = 4;
            }
        }
        else if (krok == 'l')
        {
            smer = smer + 1;
            if (smer >= 5)
            {
                smer = 1;
            }
        }
        else if (krok == 'f')
        {
        }
    }
    printf("\n");
    vypis(stlpce, riadky, pole);

    free(pole);
    return 0;
}
