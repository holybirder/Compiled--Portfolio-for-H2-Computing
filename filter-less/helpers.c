#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over each row
    //loop over each column for each pixel
    //calculate avg
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red = image[i][j].rgbtRed;
            int Green = image[i][j].rgbtGreen;
            int Blue = image[i][j].rgbtBlue;

            avg = round((Red + Green + Blue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //for each row, for each column,
    //convert red, green, blue of that pixel to the sepia value
    //loop over the rounded final values of red, green, blue -- if exceed 255, make it 255
    int finalred;
    int finalgreen;
    int finalblue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width;  j++)
        {
            finalred = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            finalgreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            finalblue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (finalred > 255)
            {
                finalred = 255;
            }
            if (finalgreen > 255)
            {
                finalgreen = 255;
            }
            if (finalblue > 255)
            {
                finalblue = 255;
            }

            image[i][j].rgbtRed = finalred;
            image[i][j].rgbtGreen = finalgreen;
            image[i][j].rgbtBlue = finalblue;
        }
    }

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //for each row, for each column,
    //if odd -- middle stay still, if odd, swap all
    //get the pixel number to swap with?? --> swap by reversing array
    //swap using pointers
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp [height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy over the pixels
            temp[i][j] = image[i][j];

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float counter = 0.00;

            //go thru all neighbouring pixels in 3x3 grid
            for (int x = -1; x < 2; x++)
            {
                for (int y  = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //if valid, run code to get sum
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    sumRed = sumRed + image[currentX][currentY].rgbtRed;
                    sumGreen = sumGreen + image[currentX][currentY].rgbtGreen;
                    sumBlue = sumBlue + image[currentX][currentY].rgbtBlue;

                    counter ++;
                }

                temp[i][j].rgbtRed = round(sumRed / counter);
                temp[i][j].rgbtGreen = round(sumGreen / counter);
                temp[i][j].rgbtBlue = round(sumBlue / counter);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
