// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void merge_sort(avg_temp arr[], int left, int right);
void merge(avg_temp arr[], int left, int middle, int right);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    merge_sort(temps, 0, NUM_CITIES - 1);

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
// Implement the Merge Sort algorithm
void merge_sort(avg_temp arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Sort the left half and right half of the array
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        // Merge sorted arrays
        merge(arr, left, middle, right);
    }
}

// Function to combine two subarrays of arr[]
void merge(avg_temp arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    avg_temp left_arr[n1], right_arr[n2];

    // Copy data into temporary arrays left_arr[] and right_arr[]
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[middle + 1 + j];

    // Merge temporary arrays into main array arr[left...right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (left_arr[i].temp >= right_arr[j].temp)
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remainder of left_arr[], if any
    while (i < n1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remainder of right_arr[], if any
    while (j < n2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}
