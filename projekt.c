#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>

#pragma pack(push, 1)
typedef struct
{
    uint8_t id_length;
    uint8_t color_map_type;
    uint8_t image_type;
    uint8_t color_map[5];
    uint16_t x_origin;
    uint16_t y_origin;
    uint16_t width;
    uint16_t height;
    uint8_t depth;
    uint8_t descriptor;
} TGAHeader;
#pragma pack(pop)

typedef struct
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

Pixel *load_pixels(TGAHeader header, FILE *file)
{

    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * header.width * header.height);

    assert(fread(pixels, sizeof(Pixel) * header.width * header.height, 1, file) == 1);

    return pixels;
}

int croping(int width, int height, int x_start, int y_start, TGAHeader header, FILE *file, FILE *outfile)
{

    // fread(&pixels, sizeof(Pixel) * header.width * header.height, 1, file);
    header.width = width;
    header.height = height;
    fwrite(&header, sizeof(header), 1, outfile);
    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * width * height);

    for (int row = x_start; row < x_start + width; row++)
    {
        for (int col = y_start; col < y_start + width; col++)
        {
            Pixel *pixel = pixels + (row * width + col);
        }
    }

    fwrite(&pixels, sizeof(Pixel), width * height, outfile);
}

int main(int argc, char const *argv[])
{
    int exit = 1;
    char space[] = " ";
    char line[] = ",";
    char comand[35];
    TGAHeader header;
    int AVRG = 0;

    printf("sizeof(TGAHeader) = %ld\n", sizeof(TGAHeader));

    FILE *file = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");
    assert(outfile);
    assert(file);
    assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

    Pixel *pixels = load_pixels(header, file);

    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    Pixel *pixel = (Pixel *)malloc(sizeof(Pixel) * header.width * header.height);

    for (int i = 0; i < 20; i++)
    {

        fgets(comand, 35, stdin);
        printf("comand[s] :%s\n", comand);

        char *text = strtok(comand, space);

        printf("%s\n", text);

        if (strcmp(text, "resize") == 0) // resize
        {
            printf("its equal resize\n");
        }
        else if (strcmp(text, "crop") == 0) // crop
        {
            printf("crop funguje\n");

            x = atoi(strtok(NULL, line));
            printf("x:%d\t", x);
            y = atoi(strtok(NULL, line));
            printf("y:%d\t", y);
            width = atoi(strtok(NULL, line));
            printf("widht:%d\t", width);
            height = atoi(strtok(NULL, "\n"));
            printf("height:%d\n", height);

            Pixel *croped = (Pixel *)malloc(sizeof(Pixel) * width * height);
            int m = 0;

            for (int row = y; row < y + height; row++)
            {
                for (int col = x; col < x + width; col++)
                {
                    croped[m] = pixels[row * header.width + col];
                    m++;
                }
            }
            header.width = width;
            header.height = height;
            header.x_origin = 0;
            header.y_origin = 0;
            fwrite(&header, sizeof(header), 1, outfile);
            fwrite(croped, sizeof(Pixel), width * height, outfile);

            // croping(width, height, x, y, header, file, outfile);
        }
        else if (strcmp(text, "copy") == 0) // copy //copy x1,y1,w,h x2,y2
        {
            int x1 = atoi(strtok(NULL, line));
            printf("x1:%d\t", x1);
            int y1 = atoi(strtok(NULL, line));
            printf("y1:%d\t", y1);
            width = atoi(strtok(NULL, line));
            printf("widht:%d\t", width);
            height = atoi(strtok(NULL, line));
            printf("height:%d\t", height);
            int x2 = atoi(strtok(NULL, line));
            printf("x2:%d\t", x2);
            int y2 = atoi(strtok(NULL, "\n"));
            printf("y2:%d\n", y2);

            Pixel *croped = (Pixel *)malloc(sizeof(Pixel) * width * height);
            int m = 0;

            for (int i = 0; i < header.width*header.height; i++)
            {
                pixel[i]= pixels[i];
            }
            
            for (int row = y1; row < y1 + height; row++)
            {
                for (int col = x1; col < x1 + width; col++)
                {
                    croped[m] = pixels[row * header.width + col];
                    m++;
                }
            }


            m = 0;
            for (int row = y2; row < y2 + height; row++)
            {
                for (int col = x2; col < x2 + width; col++)
                {
                    pixel[row * header.width + col] = croped[m];
                    m++;
                }
            }

            free(croped);
        }
        else if (strcmp(text, "move") == 0) // move
        {
            int move_x = 0;
            int move_y = 0;
            x = atoi(strtok(NULL, line));
            printf("x:%d\t", x);
            y = atoi(strtok(NULL, "\n"));
            printf("y:%d\n", y);

            for (int row = 0; row < header.height; row++)
            {
                for (int col = 0; col < header.width; col++)
                {
                    move_x = row + x;
                    if (move_x > header.height)
                    {
                        move_x = move_x - header.height;
                    }

                    move_y = col + y;
                    if (move_y > header.width)
                    {
                        move_y = move_y - header.width;
                    }
                    pixel[(move_x)*header.width + (move_y)] = pixels[row * header.width + col];
                }
            }
        }
        else if (comand[0] == 'b' && comand[1] == 'w') // bw
        {

            for (int row = 0; row < header.height; row++)
            {
                for (int col = 0; col < header.width; col++)
                {
                    int pos = row * header.width + col;
                    pixel[pos] = pixels[pos];
                    AVRG = (pixel[pos].red + pixel[pos].green + pixel[pos].blue) / 3;
                    pixel[pos].red = AVRG;
                    pixel[pos].green = AVRG;
                    pixel[pos].blue = AVRG;
                }
            }
        }
        else if (comand[0] == 'i' && comand[1] == 'n') // info
        {
            printf("Image type: %d, pixel depth: %d, resolution %dx%d\n", header.image_type, header.depth, header.width, header.height);
        }
        else if (comand[0] == 's' && comand[1] == 'a') // save
        {

            fwrite(&header, sizeof header, 1, outfile);
            fwrite(pixel, sizeof(Pixel), header.width * header.height, outfile);
        }
        else if (comand[0] == 'e' && comand[1] == 'x') // exit
        {
            return 0;
            i = i + 50;
            printf("exit funguje");
        }
        else
        {
            printf("wrong parameters\n");
        }
    }
    fclose(outfile);
    fclose(file);
    free(pixel);
    free(pixels);
    return 1;
}
