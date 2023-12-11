#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Buffer to read 512 bytes at a time
    uint8_t buffer[BLOCK_SIZE];

    // Output file pointer
    FILE *output = NULL;

    // Counter to keep track of image number
    int imageCount = 0;

    // Read blocks until the end of the file
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG is already open, close it
            if (output != NULL)
            {
                fclose(output);
            }

            // Create a new JPEG file
            char filename[8];
            sprintf(filename, "%03i.jpg", imageCount);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                fclose(input);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 2;
            }

            // Increment the image count for the next image
            imageCount++;
        }

        // Write the block to the output file
        if (output != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, output);
        }
    }

    // Close the last JPEG file
    if (output != NULL)
    {
        fclose(output);
    }

    // Close the input file
    fclose(input);

    return 0;
}
