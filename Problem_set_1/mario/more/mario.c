#include <stdio.h>

int main(void)
{
    int n = 0;
    while (n < 1 || n > 8)
    {
        n = 5;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
