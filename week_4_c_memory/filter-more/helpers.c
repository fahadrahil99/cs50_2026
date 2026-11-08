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
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            BYTE avgrgbt = round((blue + green + red) / 3.0);

            image[i][j].rgbtBlue = avgrgbt;
            image[i][j].rgbtGreen = avgrgbt;
            image[i][j].rgbtRed = avgrgbt;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE buffer_array[width];

        int last_index = width - 1;

        for (int j = last_index; j >= 0; j--)
        {
            buffer_array[last_index - j] = image[i][j];
        }
        for (int k = 0; k < width; k++)
        {
            image[i][k] = buffer_array[k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    for (int m = 0; m < height; m++)
    {
        for (int f = 0; f < width; f++)
        {
            image_copy[m][f] = image[m][f];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = 0;
            int green = 0;
            int red = 0;
            float n = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (l < 0 || l > width - 1 || k < 0 || k > height - 1)
                    {
                        continue;
                    }

                    blue += image_copy[k][l].rgbtBlue;
                    green += image_copy[k][l].rgbtGreen;
                    red += image_copy[k][l].rgbtRed;
                    n += 1;
                }
            }

            image[i][j].rgbtBlue = round(blue / n);
            image[i][j].rgbtGreen = round(green / n);
            image[i][j].rgbtRed = round(red / n);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int g_x[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int g_y[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    RGBTRIPLE image_copy[height][width];

    for (int m = 0; m < height; m++)
    {
        for (int f = 0; f < width; f++)
        {
            image_copy[m][f] = image[m][f];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x_blue = 0;
            int x_green = 0;
            int x_red = 0;
            int y_blue = 0;
            int y_green = 0;
            int y_red = 0;
            int n = 0;
            int max_value = 255;
            float blue = 0;
            float green = 0;
            float red = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (l < 0 || l > width - 1 || k < 0 || k > height - 1)
                    {
                        n += 1;
                        continue;
                    }
                    x_blue += (image_copy[k][l].rgbtBlue * g_x[n]);
                    x_green += (image_copy[k][l].rgbtGreen * g_x[n]);
                    x_red += (image_copy[k][l].rgbtRed * g_x[n]);
                    y_blue += (image_copy[k][l].rgbtBlue * g_y[n]);
                    y_green += (image_copy[k][l].rgbtGreen * g_y[n]);
                    y_red += (image_copy[k][l].rgbtRed * g_y[n]);

                    n += 1;
                }
            }

            blue = sqrt(pow(x_blue, 2) + pow(y_blue, 2));
            green = sqrt(pow(x_green, 2) + pow(y_green, 2));
            red = sqrt(pow(x_red, 2) + pow(y_red, 2));

            if (blue > max_value)
            {
                blue = max_value;
            }
            if (green > max_value)
            {
                green = max_value;
            }
            if (red > max_value)
            {
                red = max_value;
            }

            image[i][j].rgbtBlue = round(blue);
            image[i][j].rgbtGreen = round(green);
            image[i][j].rgbtRed = round(red);
        }
    }
    return;
}
