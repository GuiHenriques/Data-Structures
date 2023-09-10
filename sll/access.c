// Access
#include "sll.h"

int access_first()
{
    if (check_empty())
        return 0;
    return start->value;
}

int access_last()
{
    if (check_empty())
        return 0;

    return last->value;
}

int access_position(int pos)
{
    node *ptr = start;
    
    for (int i = 0; i < pos; i++)
    {
        if (ptr->next == NULL)
        {
            printf("index error\n");
            return 0;
        }
        ptr = ptr->next;
    }
    
    return ptr->value;
}

int find_value(int val) // busca
{
    insert_last(val);
    
    node *ptr = start;

    while (ptr->value != val)
    {
        ptr = ptr->next;
    }
    
    if (ptr->next == NULL)
    {
        printf("not found\n");
        return 0;
    }

    printf("found\n");
    return 1;
}