#include <iostream>
#include <memory>

class Node {
    private:
        int value;
        std::shared_ptr<Node> next;
    
    public:
        Node(int value) : value(value) {}

        int getValue() {
            return this->value;
        }

        void setValue(int value) {
            this->value = value;
        }

        std::shared_ptr<Node> getNext() {
            return next;
        }

        void setNext(std::shared_ptr<Node> n) {
            this->next = n;
        }

};

class Stack
{
    private:
        std::shared_ptr<Node> topo;
    
    public:
        Stack() : topo(nullptr) {}

        void push(int value) {
            std::shared_ptr<Node> n = std::make_shared<Node>(value);
            n->setNext(topo);
            topo = n;
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Pilha vazia." << std::endl;
                throw std::runtime_error("Pilha vazia.");
            }

            int value = topo->getValue();
            topo = topo->getNext();
            return value;
            
        }

        int top() {
            if (isEmpty())
            {
                std::cout << "Pilha vazia." << std::endl;
                throw std::runtime_error("Pilha vazia.");
            }
            int val = topo->getValue();
            std::cout << val << std::endl;
            return val;
        }

        bool isEmpty() {
            return (topo == nullptr);
        }

        /* void display() {
            std::shared_ptr<Node> trav = topo;

            while (trav != nullptr) {
                std::cout << trav->getValue() << " -> ";
                trav = trav->getNext();
            } std::cout << "nullptr" << std::endl;
        } */
};

int main()
{
    Stack pila;

    int topo;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    topo = pila.top();
    // pila.display();
    
    pila.pop();
    pila.pop();
    topo = pila.top();
    // pila.display();
}