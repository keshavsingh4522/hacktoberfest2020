#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char a[] = "hello is a", b[] = "friend of world", c[] = "";

    /*gets(a);
    gets(b);*/

    strcpy (c,strcat(a, b));
    puts(c);
    //puts(strcmp(a, b));
    puts(strcpy(a, b));
    puts(strrev(a));
    return 0;
}
