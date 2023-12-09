#include <stdio.h>

int main()
{
    int startPopulation, endPopulation;

    // Enter the initial population size
    do
    {
        printf("Enter the initial population size (at least 9): ");
        scanf("%d", &startPopulation);

        if (startPopulation < 9)
        {
            printf("Please enter a population size of at least 9.\n");
        }
    }
    while (startPopulation < 9);

    // Enter the final population size
    do
    {
        printf("Enter the final population size (must be greater than or equal to the initial population): ");
        scanf("%d", &endPopulation);

        if (endPopulation < startPopulation)
        {
            printf("Please enter a population size greater than or equal to the initial population.\n");
        }
    }
    while (endPopulation < startPopulation);

    // Calculate the number of years required to reach final scale
    int years = 0;
    int currentPopulation = startPopulation;

    while (currentPopulation < endPopulation)
    {
        int newBorn = currentPopulation / 3;
        int died = currentPopulation / 4;

        currentPopulation = currentPopulation + newBorn - died;
        years++;
    }

    // Print the number of years required to reach final scale
    printf("Years: %d\n", years);

    return 0;
}
