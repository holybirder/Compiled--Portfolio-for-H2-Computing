#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = ((letters * 100.00) / words);
    float S = ((sentences * 100.00) / words);
    printf("L is %f\n", L);
    printf("S is %f\n", S);
    printf("unrounded index: %f\n", (0.0588 * L - 0.296 * S - 15.8));
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    printf("rounded index: %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    printf("letters is: %i\n", letters);
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {
            words++;
        }
    }
    printf("words is: %i\n", words);
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sentences++;
        }
    }
    printf("sentence is : %i\n", sentences);
    return sentences;
}