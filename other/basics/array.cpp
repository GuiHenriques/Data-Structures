#include <iostream>

class DynamicArray{
private:
    int *array; // pointer to array first element
    int index = 0;
    int max;

public:
    DynamicArray(int size) {
        array = new int[size];
        max = size;
    }

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int value) {
        if (index == max)
            return;
        array[index] = value;
        index++;
    }

    void display() {
        for (int i = 0; i < index; i++)
            std::cout << array[i] << " ";
    
        std::cout << std::endl;
    }
};

int main()
{
    DynamicArray myArray(4);
    myArray.insert(1);
    myArray.insert(3);
    myArray.insert(7);
    myArray.display();
}