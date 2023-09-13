#include <iostream>

int* merge_sort(int a[], int size);
int* merge(int a1[], int a2[], int size_left, int size_right);
void print_array(int a[], int size);

int main()
{
    int arr[] = {5, 7, 2, 4, 1, 6, 3, 0};

    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);

    int *result = merge_sort(arr, size);

    print_array(result, size);

    delete[] result;

    return 0;
}

int* merge_sort(int arr[], int size)
{
    if (size <= 1)
        return arr;
    
    int mid = size / 2;

    int *arr1 = merge_sort(arr, mid);
    int *arr2 = merge_sort(arr + mid, size-mid);

    return merge(arr1, arr2, mid, size-mid);
}

int *merge(int array_left[], int array_right[], int s_left, int s_right)
{   
    int *result = new int[s_left + s_right];
    
    int l = 0, r = 0, i = 0;
    
    while (l < s_left && r < s_right)
    {
        if (array_left[l] <= array_right[r])
            result[i++] = array_left[l++];
        else
            result[i++] = array_right[r++];
    }

    while (l < s_left)
        result[i++] = array_left[l++];

    while (r < s_right)
        result[i++] = array_right[r++];

    return result;
}

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}