#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check input
    if (argc == 2)
    {
        //check isdigit
        for (int i = 0, l = strlen(argv[1]); i < l; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        //error
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]) % 26;
    //plaintext
    string p = get_string("plaintext: ");
    //rotating it
    for (int n = 0, s = strlen(p); n < s; n++)
    {
        //isupper
        if (isupper(p[n]))
        {
            p[n] = (p[n] + k) % 91;
            if (p[n] < 'A')
            {
                p[n] += 65;
            }
        }
        //islower
        if (islower(p[n]))
        {
            p[n] = (p[n] + k) % 123;
            if (p[n] < 'a')
            {
                p[n] += 97;
            }
        }
    }
    //ciphertext
    printf("ciphertext: %s\n", p);
}