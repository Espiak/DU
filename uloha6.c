#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void skenovanie(char text[51], int *lower, int *upper, int *spaces)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int k = text[i];

        if (islower(k))
        {
            *lower += 1;
        }
        else if (isupper(k))
        {
            *upper += 1;
        }
        else if (k == ' ')
        {
            *spaces += 1;
        }
    }
}
void normal(char text[51])
{
    int zac_slova = 0;
    int kon_slova = 0;
    int velkepismena = 0;

    for (int p = 0; text[p] != '\0'; p++)
    {

        if (text[p] == ' ' && isalpha(text[p + 1])) // najdenie zaciatku slova
        {
            zac_slova = p + 1;
        }
        else if ((isalpha(text[p]) && text[p + 1] == ' ') || (isalpha(text[p]) && text[p + 1] == '\n') || (isalpha(text[p]) && text[p + 1] == '\0')) // najdenie konca slova
        {
            kon_slova = p + 1;

            for (int v = zac_slova; v < kon_slova; v++) // zistenie ci je velke pismeno v slove
            {
                if (isupper(text[v]))
                {
                    velkepismena += 1;
                }
            }

            if (velkepismena > 0)
            {
                for (int l = zac_slova; l < kon_slova; l++) // zamena pismen
                {
                    text[l] = tolower(text[l]);
                }
                text[zac_slova] = toupper(text[zac_slova]);
            }
            else if (velkepismena == 0)
            {
                for (int l = zac_slova; l < kon_slova; l++) // zamena pismen velke
                {
                    text[l] = toupper(text[l]);
                }
            }
            velkepismena = 0;
        }
    }
}
void rm_space(char text[51])
{
    for (int m = 0; text[m] != '\0'; m++)
    {
        if (text[m] == 32 && text[m + 1] == 32) // posuva ked ma dve medzery pri sebe
        {
            for (int q = m; text[q] != '\0'; q++)
            {
                text[q] = text[q + 1];
            }
            m = m - 1;
        }
    }
    if (text[0] == 32) // posuva ked je na zaciatku medzera
    {
        for (int e = 0; text[e] != '\0'; e++)
        {
            text[e] = text[e + 1];
        }
    }
}

void rm_duplikaty(char text[51])
{
    for (int m = 0; text[m] != '\0'; m++)
    {
        if (text[m] == text[m + 1]) // dve rovnake pismena pri sebe
        {
            for (int q = m; text[q] != '\0'; q++)
            {
                text[q] = text[q + 1];
            }
            m = m - 1;
        }
    }
}

int main()
{
    int spaces1, spaces2, upper1, upper2, lower1, lower2;

    char riadky[2];
    fgets(riadky, 2, stdin);
    int R = atoi(riadky);


    for (int h = 0; h < R; h++)
    {

        char text[51];
        spaces1 = 0;
        upper1 = 0;
        lower1 = 0;
        fgets(text, 51, stdin);
        
        skenovanie(text, &lower1, &upper1, &spaces1);
        rm_space(text);
        rm_duplikaty(text);

        normal(text);
        spaces2 = 0;
        upper2 = 0;
        lower2 = 0;

        skenovanie(text, &lower2, &upper2, &spaces2);
        printf("%s", text);
        printf("lowercase: %d -> %d\n", lower1, lower2);
        printf("uppercase: %d -> %d\n", upper1, upper2);
        printf("spaces: %d -> %d\n\n", spaces1, spaces2);
    }
    return 0;
}