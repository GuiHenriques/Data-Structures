// Buble Sort
#include <stdio.h>
#define SIZE 10

void print_array(int a[], int size);
void bubble(int a[], int size);

int main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    print_array(a, SIZE);
    bubble(a, SIZE);
    print_array(a, SIZE);
}

void bubble(int a[], int size)
{
    int tmp, swaps;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 2 - i; j++)
        {
            swaps = 0;
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                swaps++;
            }

            if (swaps == 0)
                return;
        }
    }
}
void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i - ", a[i]);
    printf("\n");
}