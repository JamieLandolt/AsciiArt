#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WIDTH 165
#define HEIGHT 240

#define USAGEMSG "Usage: ./main [filename] [channels]. Alternatively, ./main help for more info."
#define HELPMSG "Filename: The name of the image file (e.g. clare.png)\n Channels: The number of channels in the image file. Typically 3 for JPEGs or RGB (coloured) images (4 if it has an alpha value) and 1 for Greyscale images (2 if it has an alpha value)."

#define TOOLITTLEARGS "Expected 1 arguments (filename) received less"
#define TOOMANYARGS "Expected 1 argument (filename) received more"
#define PROCESSINGMSG "Processing Image"

// constant strings
const char* const ascii = " .'`^\",:;l!i><+_-?][}{1)(|\\/fjrxuvczXYUJCLQOZmwqpdbkho*#MW&8%B@$";

// function prototypes
char get_colour(int num);
void draw(unsigned char* grayscale, int width, int height);


void processImage(char* filename) {
    int desired_channels = 1;
    int x;
    int y;
    int channels;

    unsigned char* image = stbi_load(filename, &x, &y, &channels, desired_channels);
    draw(image, x, y);
    /*
    printf("X: %d, Y: %d, Channels: %d\n", x, y, channels);
    for (int i = 0; i < x; i++) {
        printf("%d, %c\n", i, image[i]);
    }
    */
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
}

/* get_colour()
 * returns the char to be used in ascii image given grayscale
 */
char get_colour(int num) {
    int index = (num / 4) % 64;
    return ascii[index];
}

void draw(unsigned char* grayscale, int width, int height) {
    printf("W: %d, H: %d\n", width, height);
    for (int x = 0; x < width; x++) {
        printf("%d", x % 10);
    }
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y*width + x;
            printf("%c", get_colour(grayscale[index]));
        }
        printf("\n");
    }
    printf("\n");
} 
