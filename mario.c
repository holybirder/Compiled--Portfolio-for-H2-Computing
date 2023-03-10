//mario: print out a half-pyramid(in the mario game) which has a height according to the input number
//assignment instructions: https://cs50.harvard.edu/x/2022/psets/1/mario/less/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int space = 0; space < height - (i + 1); space++)
        {
            printf(" ");
        }
        for (int width = 0; width < (i + 1); width++)
        {
            printf("#");
        }
        printf("\n");
    }
}
