#include <iostream>
#include <memory>

template <typename T>
void print(T x)
{
    std::cout << x << " ";
}

class Node
{
    private:
        int value;
        Node *next;

    public:
        Node(int value) : value(value), next(nullptr) {}

        int getValue()
        {
            return value;
        }

        void setValue(int value)
        {
            this->value = value;
        }

        Node* getNext()
        {
            return this->next;
        }

        void setNext(Node* next)
        {
            this->next = next;
        }
};

class List
{
private:
    Node *start;

public:
    List() : start(nullptr) {}

    void insert(int value) {
        Node *n = new Node(value);
        n->setNext(start);
        start = n; 
    }   


    void display() {
        Node *trav = start;

        while (trav != nullptr)
        {
            print(trav->getValue());
            trav = trav->getNext();
        }
    }
};

int main()
{
    List sll;
    for (int i = 0; i < 6; i++)
        sll.insert(i);
    sll.display();
}