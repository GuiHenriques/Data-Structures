#include <iostream>

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    // Use a range-based for loop to iterate through the elements of the 'numbers' array
    for (int num : numbers)
    {
        std::cout << num << " "; // Print each element
    }

    std::cout << std::endl;

    return 0;
}
