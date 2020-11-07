#include <stdio.h>
#include <cs50.h>

int main()
{
    float m = -1;
    int i = 0, n = 1;

    while (m < 0)
    {
        m = get_float("Change owed: ");
    }
    n = round(m * 100);
    if (n >= 25)
    {
        while (n >= 25)
        {
            n -= 25;
            i++;
        }
    }
    if (n >= 10)
    {
        while (n >= 10)
        {
            n -= 10;
            i++;
        }
    }
    if (n >= 5)
    {
        while (n >= 5)
        {
            n -= 5;
            i++;
        }
    }
    if (n < 5)
    {
        while (n > 0)
        {
            n -= 1;
            i++;
        }
    }
    printf("%i\n", i);
}
