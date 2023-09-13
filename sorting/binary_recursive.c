// Recursive Binary Search
#include <stdio.h>
#define SIZE 7

int binary_search(int a[], int key, int start, int end);

int main(void)
{
    int array[SIZE]; // {0, 2, 4, 6, 8, 10, 12}
    for (int i = 0; i < SIZE; i++)
        array[i] = i*2;
    
    int key;
    printf("Key: ");
    scanf("%i", &key);

    int index = binary_search(array, key, 0, SIZE-1);
    
    if (index != -1)
        printf("Found at index %i\n", index);
    else
        printf("Not found");

}

int binary_search(int a[], int key, int start, int end)
{
    if (start > end)
        return -1;

    int middle = (start + end) / 2;

    if (a[middle] == key)
        return middle;
    
    else if (key > a[middle])
        return binary_search(a, key, middle+1, end);
    
    else
        return binary_search(a, key, start, middle-1);
    
}