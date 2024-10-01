#include<stdio.h>
#include<string.h>

int count_distinct_char(char* str);

int main()
{
    int n;
    printf("How many characters you want to write = ");
    scanf("%d", &n);

    char s[n];

    printf("Enter s1 = ");
    scanf("%s",s);

    int l=count_distinct_char(s);
    printf("Distinct characters in %s is %d",s,l);

    return 0;
}

int count_distinct_char(char* str) 
{

	int hash[128] = { 0 };
	int i, c = 0;

	// reading each character of str[]
	for (i = 0; i < strlen(str); ++i) 
    {
		// set the position corresponding 
		// to the ASCII value of str[i] in hash[] to 1
		hash[str[i]] = 1;
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (i = 0; i < 128; ++i) 
    {
		c += hash[i];
	}

	return c;

}
