#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef struct list {
    struct node *head;
    struct node *tail;
} list;

void init(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void push_front(list *l, int value) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    
    n->value = value;
    n->next = l->head;
    n->prev = NULL;
    
    if (l->head != NULL) // nao for 1º elemento
        l->head->prev = n;
    
    l->head = n;
    
    if (l->tail == NULL) // 1º elemento
        l->tail = n;

}

void push_back(list *l, int value) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    
    n->value = value;
    n->next = NULL;
    n->prev = l->tail;
    
    if (l->tail != NULL) // nao for 1º elemento
        l->tail->next = n;
    
    l->tail = n;
    
    if (l->head == NULL) // 1º elemento
        l->head = n;
}

int pop_front(list *l) {
    node *n = l->head;
    int value = n->value;
    l->head = n->next;
    
    if (l->head != NULL) // lista nao esta vazia
        l->head->prev = NULL;
    
    if (l->tail == n) // ultimo elemento
        l->tail = NULL;
    
    free(n);
    return value;
}

int pop_back(list *l) {
    node *n = l->tail;
    int value = n->value;
    l->tail = n->prev;
    
    if (l->tail != NULL)
        l->tail->next = NULL;
    
    if (l->head == n) // ultimo elemento
        l->head = NULL;
    
    free(n);
    return value;
}

void print(list *l) {
    node *n = l->head;
    while (n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

int main() {
    list l;
    init(&l);
    push_front(&l, 1);
    push_front(&l, 2);
    push_front(&l, 3);
    push_back(&l, 5);
    
    print(&l);
    
    printf("%d\n", pop_front(&l));
    printf("%d\n", pop_back(&l));
    
    print(&l);
    
    return 0;
}