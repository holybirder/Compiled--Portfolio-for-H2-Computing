//recover: a programme that recovers deleted JPEG files from memory card, opens up a new file, and writes the recovered JPEG into it using malloc wihout memory leaks
//assignment instructions: https://cs50.harvard.edu/x/2022/psets/4/recover/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    //openfile and point to it
    FILE *infilepointer = fopen(argv[1], "r");
    //check if valid file
    if (infilepointer == NULL)
    {
        printf("Invalid file. Cannot open.\n");
        return 2;
    }

    //store each 512 bytes into a block in an array called buffer
    unsigned char buffer[512];

    //count images
    int imagecounter = 0;

    // pointer to recovered jpeg files
    FILE *outfilepointer = NULL;

    //pointer to file name's first char
    char arr[8];
    char *outfilename = arr;

    while (fread(buffer, sizeof(char), 512, infilepointer))
    {
        //check if is jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //create file name
            sprintf(outfilename, "%03i.jpg", imagecounter);
            outfilepointer = fopen(outfilename, "w");
            imagecounter++;

        }
        if (outfilepointer != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outfilepointer);
        }

    }

    fclose(outfilepointer);
    fclose(infilepointer);

    return 0;
}
