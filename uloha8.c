#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{   int out_num = 0;
    char *outFile;
    char *f = 0;

    if (argv[1] != "-i")
    {
        char *inFile = argv[1];
    }
    else{
        char *inFile = argv[2];
    }

    for (int i = 1; i < argc; i++)  
    {
        if (strcmp(argv[i], "-o") == 0)
        {
            out_num += 1;
            outFile = argv[i + 1];
            
            if ( out_num > 1)
            {
                printf("Parameter -o provided multiple times\n");
                break;
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