#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int n;
    struct node *next;
} * h, *tmp, *tmp1, *tmp2, *tmp4;

int count = 0;

void second(void)
{
    system("cls"); // For Windows
    //clrscr(); //For Mac/Linux
    printf("\n=====================================================================================================================================");
    printf("\n\t\t\t    __  ___           __      __                   __   __  __ ___ __ __  __   __  ___");
    printf("\n\t\t\t|_/|__)| | ||_/   /\\ / _  /\\ |__)|  | /\\ |     /| (__\\ |__)|__) | /  (_  /  \\ /__    /");
    printf("\n\t\t\t| \\| \\ | | || \\  /--\\\\__)/--\\| \\ |/\\|/--\\|__    |  __/ |__)|__) | \\____) \\__/ \\__)  / ");
    printf("\n=====================================================================================================================================\n");
}

void create()
{
    int data;
    tmp = (struct node *)malloc(1 * sizeof(struct node));
    tmp->prev = NULL;
    tmp->next = NULL;
    printf("\n\t\t\t\tEnter value to node : ");
    scanf("%d", &data);
    tmp->n = data;
    count++;
}

void insbeg()
{
    if (h == NULL)
    {
        create();
        h = tmp;
        tmp1 = h;
    }
    else
    {
        create();
        tmp->next = h;
        h->prev = tmp;
        h = tmp;
    }
}

void insend()
{
    if (h == NULL)
    {
        create();
        h = tmp;
        tmp1 = h;
    }
    else
    {
        create();
        tmp1->next = tmp;
        tmp->prev = tmp1;
        tmp1 = tmp;
    }
}

void inspos()
{
    int pos, i = 2;

    printf("\n\t\t\t\tSpecify position to be inserted : ");
    scanf("%d", &pos);
    tmp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n\t\t\t\tSpecified Position out of range!!");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n\t\t\t\tList is empty!! Can only insert at 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = tmp;
        tmp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            tmp2 = tmp2->next;
            i++;
        }
        create();
        tmp->prev = tmp2;
        tmp->next = tmp2->next;
        tmp2->next->prev = tmp;
        tmp2->next = tmp;
    }
}

void del()
{
    int i = 1, pos;
    printf("\n\t\t\t\tSpecify position to be deleted : ");
    scanf("%d", &pos);
    tmp2 = h;
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n\t\t\t\tSpecified Position out of range!!");
        return;
    }
    if (h == NULL)
    {
        printf("\n\t\t\t\tList is empty!!");
        return;
    }
    else
    {
        while (i < pos)
        {
            tmp2 = tmp2->next;
            i++;
        }
        if (i == 1)
        {
            if (tmp2->next == NULL)
            {
                printf("\n\t\t\t\tDeleted!!");
                free(tmp2);
                tmp2 = h = NULL;
                return;
            }
        }
        if (tmp2->next == NULL)
        {
            tmp2->prev->next = NULL;
            free(tmp2);
            printf("\n\t\t\t\tDeleted!!");
            return;
        }
        tmp2->next->prev = tmp2->prev;
        if (i != 1)
            tmp2->prev->next = tmp2->next;
        if (i == 1)
            h = tmp2->next;
        printf("\n\t\t\t\tDeleted!!");
        free(tmp2);
    }
    count--;
}

void tbeg()
{
    tmp2 = h;
    if (tmp2 == NULL)
    {
        printf("\n\t\t\t\tList is empty!!\n");
        return;
    }
    printf("\n\t\t\t\tLinked list: ");
    while (tmp2->next != NULL)
    {
        printf(" %d ", tmp2->n);
        tmp2 = tmp2->next;
    }
    printf(" %d ", tmp2->n);
}

void tend(int i)
{
    if (tmp2 != NULL)
    {
        i = tmp2->n;
        tmp2 = tmp2->next;
        tend(i);
        printf(" %d ", i);
    }
}

void main()
{
    int ch;
    h = NULL;
    tmp = tmp1 = NULL;
    second();
    printf("\n\t\t\t\t\t=============================================");
    printf("\n\t\t\t\t\t||           DOUBLY LINKED LIST            ||");
    printf("\n\t\t\t\t\t||=========================================||");
    printf("\n\t\t\t\t\t||    1) Insert at beginning               ||");
    printf("\n\t\t\t\t\t||    2) Insert at end                     ||");
    printf("\n\t\t\t\t\t||    3) Insert at a specific Position     ||");
    printf("\n\t\t\t\t\t||    4) Delete from a specific position   ||");
    printf("\n\t\t\t\t\t||    5) Display from beginning            ||");
    printf("\n\t\t\t\t\t||    6) Display Reverse                   ||");
    printf("\n\t\t\t\t\t||    0) Exit                              ||");
    printf("\n\t\t\t\t\t=============================================\n");
    while (1)
    {
        printf("\n\n\t\t\t\tEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insbeg();
            break;
        case 2:
            insend();
            break;
        case 3:
            inspos();
            break;
        case 4:
            del();
            break;
        case 5:
            tbeg();
            break;
        case 6:
            tmp2 = h;
            if (tmp2 == NULL)
                printf("\n\t\t\t\tList is empty!!");
            else
            {
                printf("\n\t\t\t\tLinked list in Reverse Order: ");
                tend(tmp2->n);
            }
            break;
        case 0:
            exit(0);
        default:
            printf("\n\t\t\t\tWrong choice menu");
        }
    }
}