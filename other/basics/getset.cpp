#include <iostream>
#include <memory>

struct Node
{
private:
    int value;
    std::shared_ptr<Node> next;

public:
    Node(int value) : value(value) {}

    int getValue()
    {
        return value;
    }

    void setValue(int value)
    {
        value = value;
    }

    std::shared_ptr<Node> getNext()
    {
        return this->next;
    }

    void setNext(std::shared_ptr<Node> next)
    {
        this->next = next;
    }
};

class List
{
private:
    std::shared_ptr<Node> start = nullptr;

public:
    void insert(int value)
    {
        std::shared_ptr<Node> n = std::make_shared<Node>(value);
        n.setNext() = start;
        start = n;
    }

    void display()
    {
        std::shared_ptr<Node> trav = start;

        while (trav != nullptr)
        {
            std::cout << trav.getValue() << " -> " << std::endl;
            trav = trav->next;
        }
    }
}

int
main()
{
    List lista;
    lista.insert(2);
    lista.insert(5);

    lista.display();
}