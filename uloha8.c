#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{

    int out_num = 0;
    int i_count = 0;
    const char *outFile = 0;
    const char *inFile = 0;

    if (argc == 1)
    {
        printf("Input path not provided\n");
        return 1;
    }
    if (strcmp(argv[1], "-i") == 0 && strcmp(argv[2], "-i") == 1)
    {
        inFile = argv[2];
    }
    else
    {

        for (int k = 0; k < argc; k++) // error na prilela "-i"
        {
            if (strcmp(argv[k], "-i") == 0)
            {
                i_count += 1;
            }
            if (i_count >= 2)
            {
                printf("Parameter -i provided multiple times\n");
                return 1;
            }
        }
    }

    for (int i = 1; i < argc; i++) // error na chybajuci output.txt subor
    {
        if (strcmp(argv[i], "-o") == 0)
        {
            out_num += 1;
            outFile = argv[i + 1];

            if (out_num > 1)
            {
                printf("Parameter -o provided multiple times\n");
                return 1;
            }
            else if (outFile == 0)
            {
                printf("Missing output path\n");
                return 1;
            }
        }
    }

    int c = strlen(argv[1]) - 4;
    int parameter = 0;
    const char *p_positoin = 0;

    for (int j = 1; j < argc; j++) // error na prilis vela parametrov
    {
        c = strlen(argv[j]) - 4;

        if (strcmp(argv[j], "-i") != 0)
        {
            if (strcmp(argv[j], "-o") != 0)
            {
                if (strcmp(argv[j] + (c), ".txt") != 0)
                {
                    parameter += 1;
                    p_positoin = argv[j];
                    if (parameter > 1)
                    {
                        printf("Too many parameters provided\n");
                        return 1;
                    }
                }
            }
        }
    }

    if (argc == 2 || strlen(argv[2]) == 2)
    {
        printf("Needle not provided\n");
        return 1;
    }

    for (int q = 0; q < argc; q++) // error na ziadny input subor
    {
        if (strcmp(argv[q], "-i") == 0 && argv[q + 1] == 0)
        {
            printf("Input path not provided\n");
            return 1;
        }
    }

    const char *txt = 0;
    for (int x = 1; x < argc; x++) // najdenie input filu
    {
        c = strlen(argv[x]) - 4;
        txt = argv[x] + c;
        if (strcmp(txt, ".txt") == 0)
        {
            if (strcmp(argv[x - 1], "-o") != 0)
            {
                inFile = argv[+x];
            }
        }
    }
// FILE *f = fopen(outFile, "a");
    // fprintf(f, "Hello world!\n");


    char text[101];
    FILE *f = fopen(inFile, "r");

    int string_len = strlen(p_positoin);
    char *comparing = (char *)malloc(string_len * sizeof(char));

    for (int w = 0; w < string_len; w++)
    {
        fgets(text, sizeof(text), f);
        strncpy(comparing, text[w], string_len);
       
        if (strcmp(comparing, text[w]) == 0)
        {
            printf("%s\n", text);
        }
        
    }
    
    printf("%s\n", p_positoin);
    printf("%s\n", text);
    printf("%s\n", comparing);
    fclose(f);
    return 0;
}