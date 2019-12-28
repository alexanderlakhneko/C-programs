#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long long card_num = 0LL;

    while (card_num < 1LL || card_num > 9999999999999999LL)
    {
        card_num = get_long_long("Please give me your credit card number: ");

    }

    long long temp_num = card_num;

    int count = 0;

    while (temp_num > 0LL)
    {
        temp_num = temp_num / 10LL;
        count++;
    }

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    temp_num = card_num;

    while (temp_num > 100LL)
    {
        temp_num = temp_num / 10LL;
    }

    int company_id = temp_num;
    string result;

    if (company_id > 50 && company_id < 56 && count == 16)
    {
        result = "MASTERCARD\n";
    }
    else if ((company_id == 34 || company_id == 37) && (count == 15))
    {
        result = "AMEX\n";
    }
    else if ((company_id / 10 == 4) && (count == 13 || count == 16 || count == 19))
    {
        result = "VISA\n";
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    int sum = 0;

    temp_num = card_num;

    for (int i = 1; i <= count; i++)
    {
        int digit = temp_num % 10LL;

        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        temp_num /= 10LL;
    }


    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    printf("%s", result);
    return 0;
}