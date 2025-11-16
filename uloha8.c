#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int out_num = 0;
    char *outFile;
    char *f = 0;
    int i_count = 0;
    char *I = "-i";
    char *inFile = 0;

    if(argc == 1)
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

            FILE *f = fopen(outFile, "a");
            fprintf(f, "Hello world!\n");
            fclose(f);
        }
    }
    return 0;
}