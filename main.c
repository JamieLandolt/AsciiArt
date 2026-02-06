#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WIDTH 100
#define HEIGHT 100

#define USAGEMSG "Usage: ./main [filename] [channels]. Alternatively, ./main help for more info."
#define HELPMSG "Filename: The name of the image file (e.g. clare.png)\n Channels: The number of channels in the image file. Typically 3 for JPEGs or RGB (coloured) images (4 if it has an alpha value) and 1 for Greyscale images (2 if it has an alpha value)."

#define TOOLITTLEARGS "Expected 1 arguments (filename) received less"
#define TOOMANYARGS "Expected 1 argument (filename) received more"
#define PROCESSINGMSG "Processing Image"

void processImage(char* filename) {
    int desired_channels = 1;
    int x;
    int y;
    int channels;

    unsigned char* image = stbi_load(filename, &x, &y, &channels, desired_channels);
    printf("X: %d, Y: %d, Channels: %d\n", x, y, channels);
    for (int i = 0; i < x; i++) {
        printf("%d, %c\n", i, image[i]);
    }
    stbi_image_free(image);
}

int main(int argc, char** argv) {
    switch (argc) {
        case 1:
            printf("%s\n", TOOLITTLEARGS);
            printf("%s\n", USAGEMSG);
            break;
        case 2:
            printf("%s\n", PROCESSINGMSG);
            if (strcmp(argv[1], "help") == 0) {
                printf("%s\n", HELPMSG);
            } else { // They entered a filename, presumably
                processImage(argv[1]);
            }
            break;
        default:
            printf("%s\n", TOOLITTLEARGS);
            printf("%s\n", USAGEMSG);
            break;
    }

    return 1;
}
