#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int convert_char(string input, int index);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    return convert_char(input, strlen(input) - 1);
}

int convert_char(string input, int index)
{
    // Base case: if index is -1, we've processed the entire string
    if (index == -1)
    {
        return 0;
    }

    // Convert the current character to an integer
    int digit = input[index] - '0';

    // Calculate the value of the remaining substring using recursion
    int remaining_value = convert_char(input, index - 1);

    // Combine the current digit with the value of the remaining substring
    return digit + remaining_value * 10;
}
