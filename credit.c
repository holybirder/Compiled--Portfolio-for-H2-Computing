//credit: using Luhn's Algorithm as a "checksum" to detect fraudulent credit card numbers without searching in the database
//assignment instructions: https://cs50.harvard.edu/x/2022/psets/1/credit/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int checkdigit (long int num);

int main(void)
{
    long int num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    int lastdigit = (num / 10) % 10 ;

    int digit = checkdigit(num);
    printf("Number of digits: %i\n", digit);

    if (digit != 13 && digit != 15 && digit != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        //continue
        //checksum -- find multipliedsum
        int digitsneeded = 0;
        if (num % 2 == 0)
        {
            digitsneeded = num / 2;
        }
        else
        {
            digitsneeded = (num-1) / 2;
        }

        int power = 1;
        int j = 0;
        while (digitsneeded > 0)
        {
            double multiplied = ((num / (pow(10, power)) % 10 ) *2

            power = power + 2;
            digitsneeded--;
            printf("digitsx2: %i", multiplied);
            // add the digits of each multiplied up
        }
       // printf the sum of digits of each multiplied up -- to check
    }
}

int checkdigit (long int num)
{
    // TODO -- count the digits

    long int dividednum = num;
    int digitcounter = 0;
    for (long int i = dividednum; dividednum > 0; dividednum = dividednum/10)
    {
        digitcounter ++;
    }

    return digitcounter;
}
