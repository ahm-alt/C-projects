#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int av;
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            av = 0;
            // gray average
            av = (int) round((image[i][n].rgbtBlue + image[i][n].rgbtGreen + image[i][n].rgbtRed) / 3.0);
            image[i][n].rgbtBlue = av;
            image[i][n].rgbtRed = av;
            image[i][n].rgbtGreen = av;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            red = 0;
            green = 0;
            blue = 0;
            //sepia blue
            blue = (int) round(.272 * image[i][n].rgbtRed + .534 * image[i][n].rgbtGreen + .131 * image[i][n].rgbtBlue);
            //sepia red
            red = (int) round(.393 * image[i][n].rgbtRed + .769 * image[i][n].rgbtGreen + .189 * image[i][n].rgbtBlue);
            //sepia green
            green = (int) round(.349 * image[i][n].rgbtRed + .686 * image[i][n].rgbtGreen + .168 * image[i][n].rgbtBlue);
            //check
            if (blue > 255)
            {
                image[i][n].rgbtBlue = 255;
            }
            else
            {
                image[i][n].rgbtBlue = blue;
            }
            if (red > 255)
            {
                image[i][n].rgbtRed = 255;
            }
            else
            {
                image[i][n].rgbtRed = red;
            }
            if (green > 255)
            {
                image[i][n].rgbtGreen = 255;
            }
            else
            {
                image[i][n].rgbtGreen = green;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float av = (width - 1) / 2.0;
    RGBTRIPLE tm[1][1];
    for (int i = 0; i < height; i++)
    {
        //swaping
        for (int n = 0, m = width - 1; n < av; n++)
        {
            tm[0][0].rgbtBlue = image[i][n].rgbtBlue;
            tm[0][0].rgbtGreen = image[i][n].rgbtGreen;
            tm[0][0].rgbtRed = image[i][n].rgbtRed;

            image[i][n].rgbtBlue = image[i][m].rgbtBlue;
            image[i][n].rgbtGreen = image[i][m].rgbtGreen;
            image[i][n].rgbtRed = image[i][m].rgbtRed;

            image[i][m].rgbtBlue = tm[0][0].rgbtBlue;
            image[i][m].rgbtGreen = tm[0][0].rgbtGreen;
            image[i][m].rgbtRed = tm[0][0].rgbtRed;
            m--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE im[height][width];
    int sred, sblue, sgreen, sum;
    // the new value
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {

            sred = 0, sblue = 0, sgreen = 0, sum = 0;
            // bixel box
            for (int a = i - 1; a <= i + 1; a++)
            {
                for (int s = n - 1; s <= n + 1; s++)
                {
                    if ((a >= 0) && (s >= 0) && (a < height) && (s < width))
                    {
                        sred += image[a][s].rgbtRed;
                        sblue += image[a][s].rgbtBlue;
                        sgreen += image[a][s].rgbtGreen;
                        sum++;
                    }
                }
            }
            //average
            im[i][n].rgbtRed = (int) round(sred / (sum * 1.0));
            im[i][n].rgbtBlue = (int) round(sblue / (sum * 1.0));
            im[i][n].rgbtGreen = (int) round(sgreen / (sum * 1.0));
        }
    }
    // copy the value
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = im[h][w].rgbtRed;
            image[h][w].rgbtBlue = im[h][w].rgbtBlue;
            image[h][w].rgbtGreen = im[h][w].rgbtGreen;
        }
    }
    return;
}
