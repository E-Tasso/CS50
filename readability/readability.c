#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // Get input text
    string sentence = get_string("Text: ");

    // Compute the numbers of letters/words/sentences
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++;
        }
        else if (isspace(sentence[i]))
        {
            words++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }
    
    // Number of Letters & Sentences per words
    float x = (letters * 100.0f) / words;
    float y = (sentences * 100.0f) / words;

    // Coleman-Liau formula
    float grade = round((0.0588 * x) - (0.296 * y) - 15.8);
   
    // Print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)grade);
    }

}