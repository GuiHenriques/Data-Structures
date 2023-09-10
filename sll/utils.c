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