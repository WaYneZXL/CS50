#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *dorm;
}
student;

int cmp(const void *a, const void *b);

int main(void)
{
    student heads[] =
    {
        {"Stelios", "Branford"},
        {"Maria", "Cabot"},
        {"Anushree", "Ezra Stiles"},
        {"Brian", "Winthrop"}
    };
    printf("Before:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s from %s\n", heads[i].name, heads[i].dorm);
    }
    qsort(heads, 4, sizeof(student), cmp);
    printf("After:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s from %s\n", heads[i].name, heads[i].dorm);
    }
}

int cmp(const void *a, const void *b)
{
    // initiate two structs s1 and s2
    const student *s1 = a;
    const student *s2 = b;

    // initiate two strings / char within each structure
    char *str1 = s1->name;
    char *str2 = s2->name;

    // compare two strings
    if (strcmp(str1, str2)<0)
    {
        return -1;
    }
    else if (strcmp(str1, str2)>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
