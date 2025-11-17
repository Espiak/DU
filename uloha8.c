#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    /*FILE *f = fopen(outFile, "a");
      fprintf(f, "Hello world!\n");
      fclose(f);*/

    int out_num = 0;
    const char *outFile;
    char *f = 0;
    int i_count = 0;
    char *I = "-i";
    const char *inFile = 0;

    if (argc == 1)
    {
        printf("Input path not provided\n");
        return 1;
    }
    if (strcmp(argv[1], I) == 0 && strcmp(argv[2], I) == 1)
    {
        inFile = argv[1];
    }
    else
    {
        inFile = argv[2];

        for (int k = 0; k < argc; k++)
        {
            if (strcmp(argv[k], I) == 0)
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

    for (int i = 1; i < argc; i++)
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

    
    
    printf("%s ", txt);

    int c = strlen(argv[1]) - 4;
    int parameter = 0;
const char *txt = argv[1] + (c);
    for (int j = 1; j < argc; j++)
    {
        
        c = strlen(argv[j]) - 4;

        if (strcmp(argv[j], "-i") != 0)
        {
            if (strcmp(argv[j], "-o") != 0)
            {
                if (strcmp(argv[j] + (c), ".txt") != 0)
                {
                    parameter += 1;
                    if ( parameter > 1)
                    {
                       printf("Too many parameters provided\n");
                       break;
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

    return 0;
}