#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

struct Node {
    private:
        int value;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;

    public:
        Node(int value) : value(value), next(nullptr), prev(nullptr) {}

        int get_value() {
            return this->value;
        }

        void set_value(int value) {
            this->value = value;
        }

        shared_ptr<Node> get_next() {
            return this->next;
        }

        void set_next(shared_ptr<Node> n) {
            this->next = n;
        }

        shared_ptr<Node> get_prev() {
            return this->prev;
        }

        void set_prev(shared_ptr<Node> n) {
            this->prev = n;
        }
        
};

class DoubleLL {
    private:
        shared_ptr<Node> start;
        shared_ptr<Node> end;
    
    public:
        DoubleLL() : start(nullptr), end(nullptr) {}
        
        // push_start
        void push_start(int val) {
            shared_ptr<Node> n = make_shared<Node>(val);
            
            n->set_next(start);
            n->set_prev(nullptr);

            if (start != nullptr)
                start->set_prev(n);
            
            start = n;
            
            if (is_empty())
                end = n;
        }

        // push_end
        void push_end(int val) {
            shared_ptr<Node> n = make_shared<Node>(val);

            n->set_next(nullptr);
            n->set_prev(end);
            
            if (end != nullptr)
                end->set_next(n);
            
            end = n;

            if (is_empty())
                start = n;
        }

        // pop_start
        int pop_start() {
            int value = start->get_value();

            start = start->get_next();
            start->set_prev(nullptr);

            cout << "Pop start: " << value << endl;
            return value;
        }

        // pop_end
        int pop_end() {
            int value = end->get_value();

            end = end->get_prev();
            end->set_next(nullptr);

            cout << "Pop end: " << value << endl;
            return value;
        }

        // get_start
        int get_start() {
            cout << "Start: " << start->get_value() << endl;    
            return start->get_value();
        }
        
        // get_end
        int get_end() {
            cout << "End: " << end->get_value() << endl;        
            return end->get_value();
        }

        // is_empty
        bool is_empty() {
            return start == nullptr || end == nullptr;
        }

        // display
        void display() {
            shared_ptr<Node> trav = start;
            cout << "Display: | ";
            
            while (trav != nullptr) {
                cout << trav->get_value() << " <-> ";
                trav = trav->get_next();
            } cout << "|" << endl;
        }
};

int main()
{
    DoubleLL dll;
    dll.push_start(1);
    dll.push_start(2);
    dll.push_end(7);
    dll.push_end(5);
    dll.pop_end();
    dll.pop_start();
    dll.get_start();
    dll.get_end();
    dll.display();
}
