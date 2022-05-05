#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// test key ZYXWVUTSRQPONMLKJIHGFEDCBA

int main(int argc, string argv[])
{
    // check for key lenght
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        bool key = false;
        // check for duplicates
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]) && tolower(argv[1][i]) != tolower(argv[1][i + 1]))
            {
                key = true;
            }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }   
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // get input from user
    string input = get_string("plaintext:"); 
    char encrypted[300];
    // Changing letters  
    for (int i = 0; i < strlen(input); i++)
    {
        if (islower(input[i]))
        {
            encrypted[i] = tolower(argv[1][input[i] - 'a']);
        }
        else if (isupper(input[i]))
        {
            encrypted[i] = toupper(argv[1][input[i] - 'A']);
        }
        else
        {
            encrypted[i] = input[i]; 
        }
    }
    // print encrypted text
    printf("ciphertext:%s\n", encrypted);
    return 0;
}