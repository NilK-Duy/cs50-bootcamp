#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Define the color you want to use for replacement (red in this case)
    RGBTRIPLE replacementColor;
    replacementColor.rgbtRed = 255;
    replacementColor.rgbtGreen = 0;
    replacementColor.rgbtBlue = 0;

    // Iterate through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // If it's black, replace it with the chosen color
                image[i][j] = replacementColor;
            }
        }
    }
}
