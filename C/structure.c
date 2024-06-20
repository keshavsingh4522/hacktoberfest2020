#include<stdio.h>
#include<string.h>

struct information
{
    char name[50];
    int id;
    char proffession[50];
    char field[50];
};


int main()
{
    struct information employe;// = {"mayank", 01, "IT", "web developer"};

    strcpy(employe.name,"Mayank");
    employe.id = 01;
    strcpy(employe.proffession,"IT");
    strcpy(employe.field,"web developer");

    printf("%s\n",employe.name);
    printf("%d\n",employe.id);
    printf("%s\n",employe.proffession);
    printf("%s\n",employe.field);


    return 0;
}
