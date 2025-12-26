#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
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

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;


Pixel* load_pixels(TGAHeader header, FILE* file)
{

    Pixel* pixels = (Pixel*) malloc(sizeof(Pixel) *  header.width *  header.height);

    assert(fread(pixels, sizeof(Pixel) * header.width * header.height, 1, file) == 1);

    return pixels;
}



int main(int argc, char const *argv[])
{
int exit = 1;
char space[] = " ";
char comand[20];
TGAHeader header;



FILE* file = fopen(argv[1], "rb");
assert(file);
assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);


fgets(comand,20,stdin);
printf("comand[s] :%s\n",comand);
char *text = strtok(comand,space);

printf("comand[s] :%s\n",comand);
printf("%s\n",text);




Pixel* pixels = load_pixels(header, file); 

for (int row = 0; row < header.height; row++) {
    for (int col = 0; col < header.width; col++) 
    {
        Pixel* pixel = pixels + (row * header.width + col);
        pixel->red = 0;
    }
}




if(strcmp(text,"resize") == 0)//resize
{
    printf("its equal resize\n");

}
else if(strcmp(text,"crop") == 0)//crop
{

}else if(strcmp(text,"copy") == 0)//copy
{

}else if(strcmp(text,"move") == 0)//move
{

}else if(comand[0] == 'b' && comand[1] == 'w')//bw
{

}else if(comand[0] == 'i' && comand[1] == 'n')//info

{
printf("Image type: %d, pixel depth: %d, resolution %dx%d\n", header.image_type, header.depth, header.width,header.height);
}else if(comand[0] == 's' && comand[1] == 'a')//save
{

}else if(comand[0] == 'e' && comand[1] == 'x')//exit
{
return 0;

printf("exit funguje");

}else
{
    printf("wrong parameters");
}

    return 1;

}
