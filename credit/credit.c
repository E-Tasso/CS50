#include <cs50.h>
#include <stdio.h>

int main(void)

{

    int digits, checksum, i, j;

    // Prompt for Card Number

    long card;
    do

    {
        card = get_long("Number: ");
    }

    while (card < 0);

    long cc = card;
    long ccd = card;
    
    // Card Digits

    for (digits = 0; ccd > 0; digits++)
    {
        ccd /= 10;
    }
    
    // Luhns loop
    
    checksum = 0;
    
    for (i = 0; cc > 0; i++, cc /= 10)
    {
        if (i % 2 == 0)
        {
            checksum += (cc % 10);
        }
        else
        {
            j = (cc % 10) * 2;
            if (j >= 10)
            {
                j = (j / 10) + (j % 10);
            }
            checksum += j;
        }
    }
    checksum = checksum % 10;

    // Card Check
    
    if ((checksum == 0) && (digits == 13 || digits == 15 || digits == 16))
    {
        // Visa
        if ((card >= 4e15 && card < 5e15) || (card >= 4e12 && card < 5e12))
        {
            printf("VISA\n");
        }
        // AMEX
        else if ((card >= 34e13 && card < 35e13) || (card >= 37e13 && card < 38e13))
        {
            printf("AMEX\n");
        }
        // MASTER
        else if (card >= 51e14 && card < 56e14)
        {
            printf("MASTERCARD\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}