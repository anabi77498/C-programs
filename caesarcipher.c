#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

# To run, the command line must have two arguments ./'filename' '# of shifts'

# Implements a cipher with the rule being a defined number of shifts in the alphabet
# Input - integer
# Output - text shifted by input amount in alphabet

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, s = strlen(argv[1]); i < s; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);


    char *text = malloc(50);
    printf("Plaintext: ");
    scanf("%s", text);

    int alphaindex[26];
    for (int i = 0; i < 26; i++)
    {
        alphaindex[i] = 'a' + i;
    }

    int Alphaindex[26];
    for (int i = 0; i < 26; i++)
    {
        Alphaindex[i] = 'A' + i;
    }

    printf("Ciphertext: ");
    int s = strlen(text);
    int ciphertext[s];
    for (int i = 0; i < s; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int ctext = (text[i] - 'A' + key) % 26;
                ciphertext[i] = Alphaindex[ctext];
                printf("%c", ciphertext[i]);
            }
            else if (islower(text[i]))
            {
                int ctext = (text[i] - 'a' + key) % 26;
                ciphertext[i] = alphaindex[ctext];
                printf("%c", ciphertext[i]);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
