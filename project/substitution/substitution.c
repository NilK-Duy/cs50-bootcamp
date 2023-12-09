#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alpha(string alpha);

void caesar(string alpha);

int main(int argc, string argv[])
{
    // Check if the program is executed with the correct number of command-line arguments.
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Check if the provided key is valid (contains only alphabets and each alphabet appears exactly once).
    if (!only_alpha(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Perform Caesar cipher encryption.
    caesar(argv[1]);
    return 0;
}

// Function to check if the input string contains only alphabets and each alphabet appears exactly once.
bool only_alpha(string alpha)
{
    if (strlen(alpha) != 26)
    {
        return false;
    }

    int alphaCount[26] = {0};

    for (int i = 0; i < 26; i++)
    {

        char c = tolower(alpha[i]);

        // Check if the character is an alphabet
        if (!isalpha(alpha[i]))
        {
            return false;
        }

        int index = c - 'a';

        // Check if the alphabet has already appeared
        if (alphaCount[index] > 0)
        {
            return false;
        }
        alphaCount[index]++;
    }
    return true;
}

// Function to perform the Caesar cipher encryption
void caesar(string argv1)
{
    int n = strlen(argv1);

    // Convert the key to lowercase.
    char alpha[n + 1];
    for (int i = 0; i < n; i++)
    {
        alpha[i] = tolower(argv1[i]);
    }
    alpha[n] = '\0';

    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    string text = get_string("plantext: ");

    printf("ciphertext: ");

    // Encrypt each character in the plaintext.
    for (int i = 0, k = strlen(text); i < k; i++)
    {
        if (isalpha(text[i]))
        {
            // Find the corresponding index of the alphabet in the regular order.
            for (int j = 0; j < n; j++)
            {
                int base = islower(text[i]) ? 0 : 32;
                if (text[i] + base == alphabets[j])
                {
                    // Print the encrypted character.
                    printf("%c", alpha[j] - base);
                }
            }
        }
        else
        {
            // Print non-alphabetic characters unchanged.
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
