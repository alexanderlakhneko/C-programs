#include <cs50.h>
#include <stdio.h>

int get_my(string prompt);

int main(void)
{
    int n = get_my("Height: ");
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}

// Prompt user for positive integer
int get_my(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}