#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_alpha(string text, int key_length);
void array_generation(char array_input[], int array_size, string key_text);
void mapper(char array_input[], string plaintext, string ciphertext, int text_len);

int main(int argc, string argv[])
{
    const int ALPHA_LEN = 26;
    const int SAMPLE_LEN = 91;
    char sample_array[SAMPLE_LEN];

    if (argc > 2 || argc < 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];
    int key_len = strlen(key);
    int first_function_return = is_alpha(key, key_len); // First function.

    if (key_len < ALPHA_LEN)
    {
        printf("The key must contain 26 characters\n");
        return 1;
    }
    else if (first_function_return == 1)
    {
        printf("Key must only contain letters\n");
        return 1;
    }
    else if (first_function_return == 2)
    {
        printf("Characters cannot be repeated in the key\n");
        return 1;
    }

    array_generation(sample_array, SAMPLE_LEN, key);// Second function.

    string plain_text = get_string("plaintext: ");
    int text_len = strlen(plain_text);
    string cipher_text = plain_text;

    mapper(sample_array, plain_text, cipher_text, text_len);// Third function.

    printf("ciphertext: %s\n", cipher_text);
}

int is_alpha(string text, int key_length) // Function to check the validity of the key given.
{
    int return_value = 0;
    for (int i = 0; i < key_length; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            return_value = 1;
        }
        for (int j = 0; j < key_length; j++)
        {
            if (i != j)
            {
                if (tolower(text[i]) == tolower(text[j]))
                {
                    return_value = 2;
                }
            }
        }
    }
    return return_value;
}

void array_generation(
    char array_input[], int array_size,
    string key_text) // Function to generate an array with index mapped to the ASCII values of
{                    // the capital letters.
    for (int i = 0, dist_to_a = 65; i < array_size; i++)
    {
        if (i < dist_to_a)
        {
            array_input[i] = '\0';
        }
        array_input[i] = key_text[i - dist_to_a];
    }
}

void mapper(char array_input[], string plaintext, string ciphertext,
            int text_len) // Actual mapping of the letters happen here.
{                         // Ascii values of the letters from plaintext is used as index
    int alpha_to_int = 0; // to fetch the corresponding key from the sample array used to
    for (int i = 0; i < text_len; i++) // store the key.
    {
        if (isalpha(plaintext[i]) > 0)
        {
            if (islower(plaintext[i]) > 0)
            {
                alpha_to_int = plaintext[i] - 32;
                ciphertext[i] = tolower(array_input[alpha_to_int]);
            }
            else
            {
                alpha_to_int = plaintext[i];
                ciphertext[i] = toupper(array_input[alpha_to_int]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
}
