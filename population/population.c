#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);

    // Prompt for end size
    
    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);
    
    //Years
    int years = 0;
    
    // Calculate number of years until we reach threshold
    while (x < y)
    {
        x = x + (x / 3) - (x / 4);
        years++;
    }
   
    // TODO: Print number of years
    printf("Years: %i\n", years);
}

