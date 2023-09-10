// Remove
#include "sll.h"

void remove_first()
{
    if (check_empty())
        return;

    node *tmp = start;
    start = start->next;
    free(tmp);
}

void remove_last()
{
    if (check_empty())
        return;

    node *ptr = start;
    while (ptr->next != last)
        ptr = ptr->next;

    free(last);
    ptr->next = NULL;
    last = ptr;
}

void remove_postion(int pos)
{
    if (check_empty())
        return;

    if (pos == 0)
    {
        remove_first();
        return;
    }

    int cont = 0;
    node *ptr = start;
    node *prev = NULL;

    while (cont < pos && ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        cont++;
    }

    if (ptr == NULL)
    {
        printf("index error\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
}

void remove_value(int val)
{
    if (check_empty())
        return;

    node *ptr = start;
    node *prev = NULL;

    while (ptr->value != val && ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Not found\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
}