#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int pt_finder(int pts[], char alps[], char letter);
int pt_calc(string word, int pts[], char alps[]);

int main(void)
{
    char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player1_response = get_string("Player 1: ");

    string player2_response = get_string("Player 2: ");

    int sum_1 = pt_calc(player1_response, points, alphabets);
    int sum_2 = pt_calc(player2_response, points, alphabets);

    if (sum_1 > sum_2)
    {
        printf("player 1 wins!\n");
    }
    else if (sum_1 < sum_2)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int pt_finder(int pts[], char alps[], char letter)
{
    // Function to map the letters to points
    char lower_letter = tolower(letter);
    int point = 0;
    for (int i = 0; i < 26; i++)
    {
        if (lower_letter == alps[i])
        {
            point = pts[i];
            break;
        }
    }
    return point;
}

int pt_calc(string word, int pts[], char alps[])
{

    // Funtion to calculate the total points of the given string
    int length = strlen(word);
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]) > 0)
        {
            sum += pt_finder(pts, alps, word[i]);
        }
    }
    return sum;
}