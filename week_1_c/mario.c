#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter the height of pyramid, from 1 to 8\n"); // Asking for the correct integer within the limit
    }
    while (height < 1 || height > 8);

    int space_holder = height - 1;
    for (int row = 1; row <= height; row++) // looping to create each rows
    {
        for (int i = space_holder; i > 0; i--)  // adding empty space for the alignment
        {
            printf(" ");
        }
        for (int col = 1; col <= row; col++) // writing the first set of '#'s
        {
            printf("#");
        }
        printf("  "); // adding space between the two sets

        for (int col2 = 1; col2 <= row; col2++) // writing the second set of '#'s
        {
            printf("#");
        }
        printf("\n"); // line breaker to seperate the rows
        space_holder -= 1;
    }
}
