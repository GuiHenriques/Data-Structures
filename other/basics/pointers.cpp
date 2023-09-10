#include <iostream>
#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> next;

    Node(int value) : value(value), next(nullptr) {}
};

class List {
private:
    std::shared_ptr<Node> start;

public:

    List() : start(nullptr) {}

    void insert(int value) {
        std::shared_ptr<Node> n = std::make_shared<Node>(value);
        n->next = start;
        start = n;
    }

    void display() {
        std::shared_ptr<Node> trav = start;

        while (trav != nullptr)
        {
            std::cout << trav->value << " -> ";
            trav = trav->next;
        }

        std::cout << "null" << std::endl;
    }
};

int main()
{
    List lista;
    lista.insert(2);
    lista.insert(5);
    lista.insert(6);

    lista.display();
}