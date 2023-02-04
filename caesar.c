#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char rotate(char blankchar, int blankkey);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string inputkey = argv[1];
    int key = atoi(inputkey);

    for (int i = 0; i < strlen(inputkey); i++)
    {
        if (isdigit(inputkey[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext:  ");
    int newletter = 0;
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isalpha(plaintext[j]))
        {
            if (isupper(plaintext[j]))
            {
                newletter = ((int)plaintext[j] - 65 + key) % 26;
                printf("%c", newletter + 65);
            }

            else if (islower(plaintext[j]))
            {
                newletter = ((int)plaintext[j] - 97 + key) % 26;
                printf("%c", newletter + 97);
            }

        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}


