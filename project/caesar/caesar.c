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
            return 0;
        }
        else
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
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
    int k = integer % 26;

    string text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // Encrypt lowercase letters using Caesar cipher.
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            char x = (text[i] - 'a' + k) % 26 + 'a';
            printf("%c", x);
        }

        // Encrypt uppercase letters using Caesar cipher.
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            char x = (text[i] - 'A' + k) % 26 + 'A';
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
