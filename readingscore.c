#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

# Input: text (char)
# Output: Reading score (int) in terms of grade level

# Using the coleman liau index, this program assigns a reading score to a given text

# Coleman Liau Index:  index = 0.0588 * avg letters per 100 words - 0.296 * avg sentences per 100 words - 15.8;


int lettercount(string text);
int wordcount(string text);
int sentcount(string text);
float coleliau(int lettersf, int wordsf, int sentencesf);

int main(void)
{
    string utext = get_string("Text: ");
    int letters = lettercount(utext);
    int words = wordcount(utext);
    int sentences = sentcount(utext);
    int i = round(coleliau(letters, words, sentences));
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (i > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

int lettercount(string text)
{
    int letterc = 0;
    for (int i = 0, s = strlen(text); i < s; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterc++;
        }
    }
    return letterc;
}

int wordcount(string text)
{
    int wordc = 1;
    for (int i = 0, s = strlen(text); i < s; i++)
    {
        if (text[i] == ' ')
        {
            wordc++;
        }
    }
    return wordc;
}

int sentcount(string text)
{
    int sentc = 0;
    for (int i = 0, s = strlen(text); i < s; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentc++;
        }
    }
    return sentc;
}

float coleliau(int lettersf, int wordsf, int sentencesf)
{
    float L = (float) lettersf * ((float) 100 / (float) wordsf);
    float S = (float) sentencesf * ((float) 100 / (float) wordsf);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
