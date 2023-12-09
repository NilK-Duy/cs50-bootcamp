#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string number);

void caesar(int integer);

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided.
    if (argc == 2)
    {
        if (only_digits(argv[1]))
        {
            // Convert the key to an integer.
            int n = atoi(argv[1]);
            caesar(n);
        }
        else
        {
            printf("Usage: %s key\n", argv[0]);
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
    }
}

// Function to check if a string contains only digits.
bool only_digits(string number)
{
    for (int i = 0, n = strlen(number); i < n; i++)
    {
        if (!isdigit(number[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to perform Caesar cipher encryption.
void caesar(int integer)
{
    string text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // Encrypt alpha letters using Caesar cipher.
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            char x = (text[i] - base + integer) % 26 + base;
            printf("%c", x);
        }

        // Non-alphabetic characters unchanged.
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
