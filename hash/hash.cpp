#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class HashTable {
private:
    int size;
    Node buckets[size];

    int hash(int key) {
        return key % size;
    }
    // hash_potencia
    // hash_dobra

public:
    HashTable(int size) : size(size) {
        for (int i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }
};

int main() {
    HashTable hash(10);
    return 0;
}