#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
    uint8_t id_length;
    uint8_t color_map_type;
    uint8_t image_type;
    uint8_t color_map[5];
    uint8_t x_origin[2];
    uint8_t y_origin[2];
    uint8_t width[2];
    uint8_t height[2];
    uint8_t depth;
    uint8_t descriptor;
    
} TGAHeader;

int main(int argc, char const *argv[])
{

TGAHeader header;
header.id_length = 20; 

//
FILE* file = fopen("pokus1.tga", "rb");
assert(file);

assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

printf("Image type: %d, pixel depth: %d, resolution%dx%d\n", header.image_type, header.depth, header.width[1],header.height[1]);

    return 0;
}
