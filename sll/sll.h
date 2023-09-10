#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

extern node *start;
extern node *last;

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

#endif