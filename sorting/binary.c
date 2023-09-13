// Binary search
#include <stdio.h>
#define SIZE 7

int binary_search(int a[], int key, int start, int end);

int main(void)
{
    int a[SIZE] = {0, 1, 2, 3, 4, 5, 7};
    int key = 5;

    int index = binary_search(a, key, 0, SIZE - 1);
    
    if (index == -1)
        printf("Not found\n");
    else
        printf("Found at index %i\n", index);
}

int binary_search(int a[], int key, int start, int end)
{
    int middle;

    // while start > end break
    while (start <= end)
    {
        // Find middle
        middle = (start + end) / 2;

        if (a[middle] == key)
            return middle;

        else if (key > a[middle])
            start = middle + 1;

        else
            end = middle - 1;
    }

    return -1;
}