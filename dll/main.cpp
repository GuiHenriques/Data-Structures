#include "dll.h"

int main()
{
    DoubleLL dll;
    dll.push_start(1);
    dll.push_start(2);
    dll.push_end(3);
    dll.display();
}
