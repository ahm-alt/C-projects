#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    // prompet height
    do
    {
        h = get_int("Height : ");
    }
    while (h <= 0 || h > 8);
    // print traingle
    for (int a = h; a > 0; a--)
    {
        // printing the space
        for (int s = 1; s <= a - 1; s++)
        {
            printf(" ");
        }
        // printing #
        for (int d = h; d >= a; d--)
        {
            printf("#");
        }
        // new line
        printf("\n");
    }
}

