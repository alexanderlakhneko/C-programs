#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int length,i,j,lengthj;

    string input = argv[1];
    int x = atoi(input);

    length = strlen (input);

    for (i=0;i<length; i++) {
        if (!isdigit(input[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string line;

    line = get_string("%s", "plaintext: ");

    lengthj = strlen (line);

    int charI;

    printf("ciphertext: ");

    for (j=0;j<lengthj; j++) {
        charI = (int)line[j];

        if (charI >= 65 && charI <= 90) {

            charI = charI + x;

            while (charI > 90) {
                charI -= 26;
            }
        }

         if (charI >= 97 && charI <= 122) {

            charI = charI + x;

            while (charI > 122) {
                charI -= 26;
            }
        }

        printf("%c", charI);
    }

    printf("\n");

}
