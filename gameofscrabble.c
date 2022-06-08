#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

# Implements a game of scrabble using an assigned letters to words key
# input words (char)
# output winner (char) 


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);
string compare(int a, int b);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%s\n", compare(score1, score2));

}

string compare(int a, int b)
{
    if (a > b)
    {
        return "Player 1 wins!";
    }
    else if (a < b)
    {
        return "Player 2 wins!";
    }
    else
    {
        return "Tie!";
    }
}

int compute_score(string word)
{
    int s = strlen(word);
    for (int i = 0; i < s; i++)
    {
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
        }
    }

    int WORDS[26];
    for (int i = 0; i < 26; i++)
    {
        WORDS[i] = 65 + i;
    }

    int sum = 0;
    for (int j = 0; j < s; j++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (WORDS[i] == word[j])
            {
                sum += POINTS[i];
            }
        }
    }
    return (sum);
}
