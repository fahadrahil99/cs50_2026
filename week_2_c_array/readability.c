#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int no_letters = 0;
    int no_sentences = 0;
    float no_words = 1;
    float index_f = 0;
    float L = 0;
    float S = 0;
    int index = 0;
    float words_per_100 = 0;

    string text = get_string("Text: ");

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isalpha(text[i]) > 0)  // findig the number of letters in the text.
        {
            no_letters += 1;
        }
        else if (isblank(text[i]) > 0) // finding the number of words in the text.
        {
            no_words += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') // findig the number of sentences in the text.
        {
            no_sentences += 1;
        }
    }

    words_per_100 = no_words / 100;

    L = no_letters / words_per_100; // average letters per 100 words

    S = no_sentences / words_per_100; // average sentences per 100 words

    index_f = (0.0588 * L - 0.296 * S - 15.8); // Coleman liau formulae

    index = round(index_f);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
