#include <cs50.h>
#include <stdio.h>

int growth(int number);

int main(void)
{
    int a = 10;
    printf("number is: %i\n", growth(a));
    printf("number 2 is: %i\n", growth(growth(a)));

}

int growth(int number)
{
    int x = number + (int)(number / 3) - (int)(number / 4);
    return x;
}
