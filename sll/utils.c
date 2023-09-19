// Utils
#include "sll.h"

int check_empty()
{
    if (start == NULL)
    {
        printf("empty\n");
        return 1;
    }
    else
        return 0;
}

void print_list()
{
    node *ptr = start;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        printf("%i ", ptr->value);
        // free(ptr);
        ptr = next;
    }
    printf("\n");
}

void reverse_list()
{
    node *ptr = start;
    node *prev = NULL;
    node *next = NULL;

    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    start = prev;
}
void free_list()
{
    node *ptr = start;
    node *tmp;

    while (ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}