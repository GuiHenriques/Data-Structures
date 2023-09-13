// Selection sort
#include <stdio.h>
#define SIZE 8

void selection(int a[], int size);
void print_array(int a[], int size);

int main(void)
{
    int a[SIZE] = {5, 2, 7, 4, 1, 6, 3, 0};

    print_array(a, SIZE);
    selection(a, SIZE);
}

void selection(int a[], int size)
{
    int lower, tmp;

    for (int i = 0; i < size - 1; i++)
    {
        lower = i;

        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[lower])
                lower = j;
        }

        if (lower != i)
        {
            tmp = a[i];
            a[i] = a[lower];
            a[lower] = tmp;
        }
        
        // Print current array
        for (int i = 0; i < size; i++)
                printf("%i ", a[i]);
        printf("\n");
    }
}

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", a[i]);
    printf("\n");
}