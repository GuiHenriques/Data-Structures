#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node* start = NULL;
node* last = NULL;

void create(int);
void insert_start(int);
void insert_last(int);
void insert_position(int, int);
void insert_after(int, int);
void insert_before(int, int);

int access_first();
int access_last();
int access_position(int);
int find_value(int); // busca

void remove_first();
void remove_last();
void remove_postion(int);
void remove_value(int);

void free_list();
int check_empty();
void print_list();

int main(void)
{   
    create(2);
    insert_last(3);
    
    free_list();
    
    return 0;
}

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

// Insertions
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

// Access
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

// Remotions
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