#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar keyword\n");
        return 1;
    }

    int length,i,j,k,lengthj,x;

    string input = argv[1];

    length = strlen (input);

    for (i=0;i<length; i++) {
        if (!isalpha(input[i]))
        {
            printf("Usage: ./caesar keyword\n");
            return 1;
        }
    }

    string line;

    line = get_string("%s", "plaintext: ");

    lengthj = strlen (line);

    int charI;

    printf("ciphertext: ");

    for (j=0, k=0;j<lengthj; j++) {
        charI = (int)line[j];

        x = shift(input[k]);

        if (charI >= 65 && charI <= 90) {

            charI = charI + x;

            while (charI > 90) {
                charI -= 26;
            }
            k++;
            if(k == length) {
                k = 0;
            }
        }

         if (charI >= 97 && charI <= 122) {

            charI = charI + x;

            while (charI > 122) {
                charI -= 26;
            }
            k++;
            if(k == length) {
                k = 0;
            }
        }

        printf("%c", charI);
    }

    printf("\n");

}

int shift(char c)
{
    if(c > 90) {
        return c - 97;
    }

   return c - 65;
}