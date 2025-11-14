#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct akcia
{
    int cislo_dna;
    char nazov_akcie[6];
    float koniec_dna;
    float zac_dna;
    float rozdiel;
    char obchody[7];
    int transakcie;
};
void most_shares(struct akcia akcia, int most_sales)
{

    if (most_sales == 201)
    {
        printf("<html>\n");
        printf("<body>\n");
        printf("<div>\n");
        printf("Ticker AMC was not found\n");
        printf("</div>\n");
        printf("<table>\n");
        printf("<thead>\n");
        printf("<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n");
        printf("</thead>\n<tbody>\n");
    }
    else
    {

        printf("<html>\n");
        printf("<body>\n");
        printf("<div>\n");
        printf("<h1>%s: highest volume</h1>\n", akcia.nazov_akcie);
        printf("<div>Day: %d</div>\n", akcia.cislo_dna);
        printf("<div>Start price: %.2f</div>\n", akcia.koniec_dna);
        printf("<div>End price: %.2f</div>\n", akcia.zac_dna);
        if (strlen(akcia.obchody) == 7)
        {
            printf("<div>Volume: %c_%c%c%c_%c%c%c</div>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6]);
        }
        else
        {
            printf("<div>Volume: %c%c_%c%c%c_%c%c%c</div>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6], akcia.obchody[7]);
        }
        printf("</div>\n");
        printf("<table>\n");
        printf("<thead>\n");
        printf("<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n");
        printf("</thead>\n<tbody>\n");
    }
}
void html_out(struct akcia akcia)
{

    printf("<tr>\n");
    printf("\t<td>%d</td>\n", akcia.cislo_dna);
    printf("\t<td>%s</td>\n", akcia.nazov_akcie);
    printf("\t<td>%.2f</td>\n", akcia.koniec_dna);
    printf("\t<td>%.2f</td>\n", akcia.zac_dna);
    printf("\t<td>%.2f</td>\n", akcia.rozdiel);
    if (strlen(akcia.obchody) == 7)
    {
        printf("\t<td>%c_%c%c%c_%c%c%c</td>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6]);
    }
    else
    {
        printf("\t<td>%c%c_%c%c%c_%c%c%c</td>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6], akcia.obchody[7]);
    }
    printf("</tr>\n");
}
void html_out_b(struct akcia akcia)
{

    printf("<tr>\n");
    printf("\t<td><b>%d</b></td>\n", akcia.cislo_dna);
    printf("\t<td><b>%s</b></td>\n", akcia.nazov_akcie);
    printf("\t<td><b>%.2f</b></td>\n", akcia.koniec_dna);
    printf("\t<td><b>%.2f</b></td>\n", akcia.zac_dna);
    printf("\t<td><b>%.2f</b></td>\n", akcia.rozdiel);
    if (strlen(akcia.obchody) == 7)
    {
        printf("\t<td><b>%c_%c%c%c_%c%c%c</b></td>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6]);
    }
    else
    {
        printf("\t<td><b>%c%c_%c%c%c_%c%c%c</b></td>\n", akcia.obchody[0], akcia.obchody[1], akcia.obchody[2], akcia.obchody[3], akcia.obchody[4], akcia.obchody[5], akcia.obchody[6], akcia.obchody[7]);
    }
    printf("</tr>\n");
}

int main(int argc, char const *argv[])
{
    if (argc <= 2)
    {
        printf("Wrong parameters\n");
        return 1;
    }
    else
    {

        int lines = atoi(argv[2]);
        char hodnoty[33];
        struct akcia akcia[202];
        int most_sales = 201;
        akcia[201].transakcie = 0;
    

        for (int i = 0; i < lines; i++)
        {

            fgets(hodnoty, sizeof(hodnoty), stdin);

            char p[] = ",";
            akcia[i].cislo_dna = atoi(strtok(hodnoty, p));
            strcpy(akcia[i].nazov_akcie, strtok(NULL, p));
            akcia[i].koniec_dna = atof(strtok(NULL, p));
            akcia[i].zac_dna = atof(strtok(NULL, p));
            akcia[i].rozdiel = akcia[i].zac_dna - akcia[i].koniec_dna;
            strcpy(akcia[i].obchody, strtok(NULL, p));
            akcia[i].transakcie = atoi(akcia[i].obchody);

            if (akcia[i].obchody[6] < '0' || akcia[i].obchody[6] > '9')
            {
                akcia[i].obchody[6] = '\0';
            }
            if (akcia[i].obchody[7] < '0' || akcia[i].obchody[7] > '9')
            {
                akcia[i].obchody[7] = '\0';
            }

            for (int z = 0; z < 6; z++)
            {
                if (akcia[i].nazov_akcie[z] == '\n' || akcia[i].nazov_akcie[z] == '\r')
                {
                    akcia[i].nazov_akcie[z] = '\0';
                }
            }

            if (strcmp(akcia[i].nazov_akcie, argv[1]) == 0)
            {
                if (akcia[most_sales].transakcie < akcia[i].transakcie)
                {
                    most_sales = i;
                }
            }
        }

        most_shares(akcia[most_sales], most_sales);

        for (int i = lines - 1; i >= 0; i--)
        {
            if (strcmp(akcia[i].nazov_akcie, argv[1]) == 0)
            {
                html_out_b(akcia[i]);
            }
            else
            {
                html_out(akcia[i]);
            }
        }

        printf("</tbody>\n</table>\n</body>\n</html>\n");
    return 0;    
    }
    return 0;
}