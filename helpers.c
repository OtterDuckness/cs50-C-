#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width; j++)
       {
        int average = 0;
        average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
        image[i][j].rgbtRed = average;
        image[i][j].rgbtBlue = average;
        image[i][j].rgbtGreen = average;
       }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaR > 255)
            {
                sepiaR = 255;
            }

            int sepiaG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sepiaG > 255)
            {
                sepiaG = 255;
            }

            int sepiaB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }
            image[i][j].rgbtRed = sepiaR;
            image[i][j].rgbtGreen = sepiaG;
            image[i][j].rgbtBlue = sepiaB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++ )
    {
        for (int j = 0; j < (width/2); j++)
        {
            RGBTRIPLE temp= image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    // return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgRed = 0;
            int avgGreen = 0;
            int avgBlue = 0;
            float count = 0;

            for (int m = i - 1; m <= i + 1; m++)
            {
                for ( int n = j - 1; n <= j + 1; n++)
                {
                    if ( m >= 0 && n >= 0 && m < height && n < width)
                    {
                        avgRed += copy[m][n].rgbtRed;
                        avgGreen += copy[m][n].rgbtGreen;
                        avgBlue += copy[m][n].rgbtBlue;
                        count ++;
                    }
                }
            }
            image[i][j].rgbtRed = round(avgRed/count);
            image[i][j].rgbtGreen = round(avgGreen/count);
            image[i][j].rgbtBlue = round(avgBlue/count);
       }
    }
}
