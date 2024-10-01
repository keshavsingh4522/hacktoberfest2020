// predicts grade-level of a text
// based on Coleman-Liau index

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int main(void)

{
    //set initial count for letters,words,sentences to 0
    int letters = 0;
    int words = 1;
    int sentences = 0;

    //promot user for text
    string s = get_string("Text:\n");

    //calculate number of letters,words and sentences
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            letters++;
        }

        if (s[i] == ' ')
        {
            words++;
        }

        if ((s[i] == '.' || s[i] == '?') || s[i] == '!')
        {
            sentences++;
        }
    }

    // calculate "value" of index
    float value = ((0.0588 * 100 * ((float)letters / (float)words)) - (0.296 * 100 * ((float)sentences / (float)words)) - 15.8);

    // round-off index value to nearest integer
    int index = round(value);

    //printf grade of the text
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }

    else if (index >= 16)
    {
        printf(" Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}
