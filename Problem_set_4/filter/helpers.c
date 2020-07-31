#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue +
                        image[i][j].rgbtGreen +
                        image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int r, g, b;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r = round((image[i][j].rgbtRed * 0.393) +
                      (image[i][j].rgbtGreen  * 0.769) +
                      (image[i][j].rgbtBlue * 0.189));

            g = round((image[i][j].rgbtRed * 0.349) +
                      (image[i][j].rgbtGreen * 0.686) +
                      (image[i][j].rgbtBlue * 0.168));

            b = round((image[i][j].rgbtRed * 0.272) +
                      (image[i][j].rgbtGreen * 0.534) +
                      (image[i][j].rgbtBlue * 0.131));

            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtRed = r;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp1, tmp2, tmp3;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int k = (width - j);
            tmp1 = image[i][j].rgbtRed;
            tmp2 = image[i][j].rgbtGreen;
            tmp3 = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][k - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][k - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][k - 1].rgbtBlue;

            image[i][k - 1].rgbtRed = tmp1;
            image[i][k - 1].rgbtGreen = tmp2;
            image[i][k - 1].rgbtBlue = tmp3;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Sum_B;
    int Sum_G;
    int Sum_R;
    float acum;
    // Temporary matrix
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (temp == NULL)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Sum_B = 0;
            Sum_G = 0;
            Sum_R = 0;
            acum = 0.0;
            // run matrix 3x3 <-> ( 3 * (-1, 0, 1))
            for (int x = -1; x <= 1; ++x)
            {
                for (int y = -1; y <= 1; ++y)
                {
                    if (i + x < 0 || i + x > height - 1) // to eliminate edges beyond the image above or bottom, if i=0 m=-1 then eliminate
                    {
                        continue; // like a break statement, moves to next iteration
                    }
                    if (j + y < 0 || j + x > width - 1) // to elimiate pixels beyond left and right boundary of image width
                    {
                        continue;
                    }
                    // Sum of all of each color in the 3x3 matrix
                    Sum_B += image[i + x][j + y].rgbtBlue;
                    Sum_G += image[i + x][j + y].rgbtGreen;
                    Sum_R += image[i + x][j + y].rgbtRed;
                    acum++;
                    // Store average pixels in the temp matrix
                    temp[i][j].rgbtBlue = round(Sum_B / acum);
                    temp[i][j].rgbtGreen = round(Sum_G / acum);
                    temp[i][j].rgbtRed = round(Sum_R / acum);
                }
            }
        }
    }
    // taking back to the original buffer images*
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
