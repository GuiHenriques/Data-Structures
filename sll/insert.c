// Insert
#include "sll.h"

// Create new list
void create(int val)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    n->value = val;
    n->next = NULL;
    start = n;
    last = n;
}

void insert_start(int val)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    n->value = val;
    n->next = NULL;

    n->next = start;
    start = n;
}

void insert_last(int val)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    n->value = val;
    n->next = NULL;

    last->next = n;
    last = n;
}

void insert_position(int pos, int val)
{
    if (pos == 0)
    {
        insert_start(val);
        return;
    }

    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    node *ptr = start;
    // start index: 1
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
        // index error
        if (ptr == NULL)
            return;
    }

    n->value = val;
    n->next = ptr->next;
    ptr->next = n;

    if (ptr == last)
        last = n;
}

void insert_after(int pos, int val)
{
    node *ptr = start;
    while (ptr->value != pos)
    {
        ptr = ptr->next;
        // position not found
        if (ptr == NULL)
            return;
    }

    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    n->value = val;
    n->next = ptr->next;
    ptr->next = n;

    if (n->next == NULL)
        last = n;
}

void insert_before(int pos, int val)
{
    node *ptr = start;
    if (ptr->value == pos)
    {
        insert_start(val);
        return;
    }

    while (ptr->next->value != pos)
    {
        ptr = ptr->next;
        if (ptr == NULL)
            return;
    }

    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    n->value = val;
    n->next = ptr->next;
    ptr->next = n;
}