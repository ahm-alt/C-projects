#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    //get text
    string text = get_string("Text: ");
    //call function
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);
    // letter & sentenses per 100 words
    int L = l * 100 / w;
    int S = s * 100 / w;
    //index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //print grade
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
        printf("Grade %i\n", (int)  round(index));
    }
}

//count letter
int count_letters(string text)
{
    int l = 0;
    for (int i = 0, s = strlen(text); i <= s; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            l++;
        }
    }
    return l;
}

// count words
int count_words(string text)
{
    int w = 0;
    for (int i = 0, s = strlen(text); i <= s; i++)
    {
        if (text[i] == ' ' || text[i] == '\0')
        {
            w++;
            if (text[i + 1] == ' ')
            {
                w--;
            }
        }
    }
    return w;
}

//count sentenses
int count_sentences(string text)
{
    int sen = 0;
    for (int i = 0, s = strlen(text); i <= s; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sen++;
        }
    }
    return sen;
}
