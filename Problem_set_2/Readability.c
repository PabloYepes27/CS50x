#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Implement a program that encrypts messages using Caesar’s cipher
 * Return: encrypt message
**/

int main(int argc, string argv[])
{
    int i = 0, len, key = 0;
    string s;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    else
    {
        while (argv[1][i] != '\0')
        {
            if ((argv[1][i] >= '0') && (argv[1][i] <= '9'))
            {
                key *= 10;
                key += (argv[1][i] - 48);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }
            i++;
        }
        s = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (i = 0; s[i]; i++)
        {
            if (isupper(s[i]))
            {
                // Get modulo number and add to appropriate case
                printf("%c", 'A' + (s[i] - 'A' + key) % 26);
            }
            else if (islower(s[i]))
            {
                printf("%c", 'a' + (s[i] - 'a' + key) % 26);
            }
            else
            {
                // return unchanged
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return (0);
}
