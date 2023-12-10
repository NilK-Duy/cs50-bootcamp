#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = n;
            image[i][j].rgbtGreen = n;
            image[i][j].rgbtBlue = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE reflect = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = reflect;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0.0, sumGreen = 0.0, sumBlue = 0.0;
            int count = 0;

            // Iterate over neighboring pixels
            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    int newi = i + ni;
                    int newj = j + nj;

                    // Check if the neighboring pixel is within bounds
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        sumRed += image[newi][newj].rgbtRed;
                        sumGreen += image[newi][newj].rgbtGreen;
                        sumBlue += image[newi][newj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate average values and update temporary array
            blur[i][j].rgbtRed = round(sumRed / count);
            blur[i][j].rgbtGreen = round(sumGreen / count);
            blur[i][j].rgbtBlue = round(sumBlue / count);
        }
    }

    // Copy values from the temporary array back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blur[i][j];
        }
    }

    return;
}

// Clamp function to ensure values are within the valid range [0, 255]
int clamp(float value)
{
    return (int) fminf(255.0, fmaxf(0.0, round(value)));
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Define Sobel operators for horizontal and vertical edges
    int sobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE edges[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float redX = 0.0, greenX = 0.0, blueX = 0.0;
            float redY = 0.0, greenY = 0.0, blueY = 0.0;

            // Iterate over neighboring pixels
            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    int newi = i + ni;
                    int newj = j + nj;

                    // Check if the neighboring pixel is within bounds
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        redX += image[newi][newj].rgbtRed * sobelX[ni + 1][nj + 1];
                        greenX += image[newi][newj].rgbtGreen * sobelX[ni + 1][nj + 1];
                        blueX += image[newi][newj].rgbtBlue * sobelX[ni + 1][nj + 1];

                        redY += image[newi][newj].rgbtRed * sobelY[ni + 1][nj + 1];
                        greenY += image[newi][newj].rgbtGreen * sobelY[ni + 1][nj + 1];
                        blueY += image[newi][newj].rgbtBlue * sobelY[ni + 1][nj + 1];
                    }
                }
            }

            // Calculate average values and update temporary array
            edges[i][j].rgbtRed = clamp(sqrt(redX * redX + redY * redY));
            edges[i][j].rgbtGreen = clamp(sqrt(greenX * greenX + greenY * greenY));
            edges[i][j].rgbtBlue = clamp(sqrt(blueX * blueX + blueY * blueY));
        }
    }

    // Copy values from the temporary array back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = edges[i][j];
        }
    }

    return;
}
