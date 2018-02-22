#include <stdio.h>
#include <stdlib.h>

struct node {
    char *string;
    struct node *next;
};

int main(void) {
    struct node *root = malloc(sizeof(struct node));
    (*root).string = "A";
    printf("%s\n", root->string);

    struct node root2;
    root2.string = "B";
    root2.next = root;
    printf("%s\n", root2.string);
    free(root);

    // int m;
    // int* a;
    // int* b = malloc(sizeof(int));
    // a = &m;
    // a = b;
    // m = 10;
    // *b = m + 2;
    // free(b);
    // *a = 11;
    // printf("a is %d\n", *a);

    return 0;
}





