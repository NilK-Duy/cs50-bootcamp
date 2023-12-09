#include <cs50.h>
#include <stdio.h>

int get_size(void);

void print_grid(int size);

int main(void)
{
    // Get size of grid
    int n = get_size();
    // Print grid of bricks
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (2 * size + 2); j++)
        {
            if (j < (size - (i + 1)))
            {
                printf(" ");
            }
            if (j >= (size - (i + 1)) && j < size)
            {
                printf("#");
            }
            if (j >= size && j < (size + 2))
            {
                printf(" ");
            }
            if (j >= (size + 2) && j < ((size + 2) + (i + 1)))
            {
                printf("#");
            }
            if (j >= ((size + 2) + (i + 1)))
            {
                printf("");
            }
        }
        printf("\n");
    }
}
