#include "sll.h"

node *start = NULL;
node *last = NULL;

int main(void)
{   
    create(2);
    insert_last(3);
    insert_start(1);
    insert_before(2, 7);
    print_list();

    remove_last();
    insert_last(5);
    print_list();

    reverse_list();
    print_list();

    free_list();
    return 0;
}
