#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    int index_file = 0;

    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open Memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }

    // BYTE is defined in stdint.h representing an 8-bit unsigned integer
    BYTE buf[512];
    // New file JPEG
    FILE *outfile;
    // flag to know when a JPEG is founded
    bool found_jpg = false;

    // read each character of the file open before
    while (fread(buf, 512, 1, file))
    {
        // Look for the beginning of a JPEG
        if (buf[0] == 0xff && buf[1] == 0xd8 &&
            buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            if (!found_jpg)
            {
                found_jpg = true;
            }
            else
            {
                fclose(outfile);
            }

            // Open a new JPEG File
            char file_name[8];
            sprintf(file_name, "%03i.jpg", index_file++);
            outfile = fopen(file_name, "w");
            if (outfile == NULL)
            {
                return 1;
            }

            // Write a 512 byetes until a new JPEG is found
            fwrite(buf, 512, 1, outfile);
        }
        else if (found_jpg)
        {
            // keep writing the new file JPEG
            fwrite(buf, 512, 1, outfile);
        }
    }
    // Stop at end of File
    fclose(outfile);
    fclose(file);
}
