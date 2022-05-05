#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for Height
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);

    // Loop 1
    int space = x - 1;
    for (int y = 1; y <= x; y++)
    {
        for (int z = 1; z <= space; z++)
        {
            printf(" ");
        }
        space--;
        for (int i = 1; i <= y; i++)
        {
            printf("#");
        }
        printf("  ");
        
        //Loop 2
        for (int j = 1; j <= y; j++)
        {
            if (j == y)
            {
                for (int h = 1; h <= j; h++)
                {            
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}
   