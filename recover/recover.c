#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }
    // Open card and check if is valid
    char *input = argv[1];
    FILE *infile = fopen(input, "r");
    if (infile == NULL)
    {
        printf("Could not open %s\n", input);
        return 1;
    }
    // Variables
    BYTE buffer[512];
    char output[8];
    int counter = 0;
    FILE *inptr = NULL;
    // Read card and find images
    while (fread(&buffer, 512, 1, infile) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!(counter == 0))
            {
                fclose(inptr);
            }
            // Name output file
            sprintf(output, "%03i.jpg", counter);
            inptr = fopen(output, "w");
            counter++;
        }
        // Write images to output file
        if (!(counter == 0))
        {
            fwrite(&buffer, 512, 1, inptr);
        }
    }
    fclose(infile);
    fclose(inptr);
    
    return 0;
}