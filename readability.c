#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int letters(string input);
int words(string input);
int sentences(string input);
float formula(int x, int y, int z);

int main(void)
{
    string text = get_string("Text: ");
    int grade = round(formula(letters(text), words(text), sentences(text)));
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int letters(string input)
{
    int letternumber = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if isalpha(input[i])
        {
            letternumber++;
        }
    }
    //printf("letternumber is %i \n", letternumber);
    return letternumber;
}


int words(string input)
{
    int wordnumber = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if isblank(input[i])
        {
            wordnumber++;
        }
    }
    wordnumber++;
    //printf("wordnumber is %i \n", wordnumber);
    return wordnumber;
}

int sentences(string input)
{
    int sentencenumber = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentencenumber ++;
        }
    }
    //printf("sentencenumber is %i \n", sentencenumber);
    return sentencenumber;
}
float formula(int x, int y, int z)
{
    float index = 0.0588 * x / y * 100 - 0.296 * z / y * 100 - 15.8;
    return index;
}
