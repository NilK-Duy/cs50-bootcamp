#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

void binary(int number);


int main(void)
{
    string bulbs = get_string("Your message is: ");

    for (int i = 0, n = strlen(bulbs); i < n; i++)
    {
        binary(bulbs[i]);
    }
}

// Function to convert decimal to binary
void binary(int number)
{
    int binary[BITS_IN_BYTE];

    for (int i = BITS_IN_BYTE - 1; i >= 0; i--) {
        binary[i] = number % 2;
        number /= 2;
    }

    for (int i = 0; i < BITS_IN_BYTE; i++) {
        print_bulb(binary[i]);
    }

    printf("\n");
}

// Function to print the emoji representation of the bulb
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
