#include <iostream>
#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> next;

    Node(int value) : value(value), next(nullptr) {}
};

class Queue {
    private:
        std::shared_ptr<Node> back;
        std::shared_ptr<Node> front;
        int size;

    public:
        Queue() : back(nullptr), front(nullptr), size(0) {}

            
        void push(int value) {
            std::shared_ptr<
            Node> n = std::make_shared<Node>(value);
            
            if (isEmpty())
                front = n;
            
            n->next = back;
            back = n;
            size++;
        }

        void pop() {
            if (isEmpty()) {
                std::cout << "Pilha vazia" << std::endl;
                return;
            }

            std::shared_ptr<Node> trav = back;
            std::shared_ptr<Node> prev = nullptr;


            while (trav != front)
            {
                prev = trav;
                trav = trav->next;
            }
            front = prev;
            size--;
        }

        int getFront() {
            if (isEmpty())
                return 0;
            
            std::cout << "Front: " << front->value << std::endl;
            return front->value;
        }

        int getBack() {
            if (isEmpty())
                return 0;
            
            std::cout << "Back: " << back->value << std::endl;
            return back->value;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return (back == nullptr);
        }

        /* void display() {
            std::shared_ptr<Node> trav = back;

            while (trav != nullptr) {
                std::cout << trav->value << " ";
                trav = trav->next;
            }
        } */


};

int main()
{
    Queue fila;
    fila.push(5);
    fila.push(30);
    fila.push(2);
    fila.getFront();
    fila.getBack();
    fila.pop();
    fila.getFront();
}