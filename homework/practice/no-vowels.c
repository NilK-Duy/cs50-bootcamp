// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

void replace(string name);

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc == 1)
    {
        printf("Usage: %s word\n", argv[0]);
    }
    else
    {
        // Call the replace function with the command-line argument
        replace(argv[1]);
    }
}

// Function to replace characters in a given string according to specified rules
void replace(string name)
{
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == 'a')
        {
            printf("%i", 6);
        }
        else if (name[i] == 'e')
        {
            printf("%i", 3);
        }
        else if (name[i] == 'i')
        {
            printf("%i", 1);
        }
        else if (name[i] == 'o')
        {
            printf("%i", 0);
        }
        else
        {
            // Print the original character if no replacement is needed
            printf("%c", name[i]);
        }
    }
    // Print a newline after completing the replacements
    printf("\n");
}
