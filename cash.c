#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_my(string prompt);

int main(void)
{
    int f = get_my("Change owed: ");
    printf("%i\n", f);
}

// Prompt user for positive integer
int get_my(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n < 0.009);
    n = round(n * 100);
    int res_25;
    int res_10;
    int res_5;
    int res_1;
    res_25 = n / 25;
    res_10 = (n - (25 * res_25)) / 10;
    res_5 = (n - (25 * res_25) - (10 * res_10)) / 5;
    res_1 = (n - (25 * res_25) - (10 * res_10) - (5 * res_5));
    return res_25 + res_10 + res_5 + res_1;
}
