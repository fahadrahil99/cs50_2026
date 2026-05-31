#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num_digits;
    int first_digit;
    int first_two_digits;
    long card_number = 0;
    long duplicate;
    long duplicate_2;
    int luhns_sum = 0;

    num_digits = 0;
    card_number = get_long("Enter the card number\n");
    duplicate = card_number;
    duplicate_2 = card_number;

    while (card_number > 0) // 1. getting the length of card number
    {
        card_number = card_number / 10;
        num_digits++;
    } // end 1

    while (duplicate > 99) // 2. getting the first and first two digits
    {
        duplicate = duplicate / 10;
    }

    first_two_digits = duplicate;

    first_digit = first_two_digits / 10; // end 2

    for (int i = 1; i <= num_digits; i++) // 3. luhns algorithm implementation
    {
        int last_digit =
            duplicate_2 % 10; // getting the last digits of the card number using modulo 10

        if (i % 2 ==0) // selecting the even th position of digits from card number counting from last.
        {
            int product = last_digit * 2;
            if (product > 9) // checking if the multiplication of the digit with 2 produces 2 digits.
            {
                int last_digit_product = product % 10; // seperatiing the product wich is greater than 9.
                int first_digit_product = product / 10;
                luhns_sum = luhns_sum + last_digit_product + first_digit_product;
            }
            else
            {
                luhns_sum = luhns_sum + product;
            }
        }
        else
        {
            luhns_sum = luhns_sum + last_digit;
        }
        duplicate_2 = duplicate_2 / 10; // removing the last digit of card number to get the next
                                        // digit in next iteration.
    }// end 3.

    if (first_digit == 4 && (num_digits == 13 || num_digits == 16) && luhns_sum % 10 == 0) // 4. checking each cards conditions
    {
        printf("VISA\n");
    }
    else if (num_digits == 15 && (first_two_digits == 34 || first_two_digits == 37) && luhns_sum % 10 == 0)
    {
        printf("AMEX\n");
    }
    else if (num_digits == 16 && (first_two_digits > 50 && first_two_digits < 56) && luhns_sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");

    } // end 4
}
