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

class Pilha
{
    private:
        std::shared_ptr<Node> topo;
    
    public:
        Pilha() : topo(nullptr) {}

        void empilhar(int value) {
            std::shared_ptr<Node> n = std::make_shared<Node>(value);
            n->setNext(topo);
            topo = n;
        }

        int desempilhar() {
            if (pilha_vazia()) {
                std::cout << "Pilha vazia." << std::endl;
                throw std::runtime_error("Pilha vazia.");
            }

            int value = topo->getValue();
            topo = topo->getNext();
            return value;
            
        }

        int getTopo() {
            if (pilha_vazia())
            {
                std::cout << "Pilha vazia." << std::endl;
                throw std::runtime_error("Pilha vazia.");
            }

            return topo->getValue();
        }

        bool pilha_vazia() {
            return (topo == nullptr);
        }

        void display() {
            std::shared_ptr<Node> trav = topo;

            while (trav != nullptr) {
                std::cout << trav->getValue() << " -> ";
                trav = trav->getNext();
            } std::cout << "nullptr" << std::endl;

        }
};

int main()
{
    Pilha pila;
    pila.empilhar(10);
    pila.empilhar(20);
    pila.empilhar(30);
    pila.display();
    
    pila.desempilhar();
    pila.desempilhar();
    pila.display();
}