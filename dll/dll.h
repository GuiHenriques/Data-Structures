#include <iostream>
#include "node.h"

using std::cout;
using std::endl;
using std::make_shared;

class DoubleLL
{
private:
    shared_ptr<Node> start;
    shared_ptr<Node> end;
    shared_ptr<Node> trav;
    int size;

    // is_empty
    bool is_empty()
    {
        return start == nullptr || end == nullptr;
    }

    // get_size
    int get_size()
    {
        return size;
    }

    // forward_trav
    void forward_trav(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (trav->get_next() == nullptr)
                return;
            trav = trav->get_next();
        }
    }

    // backward_trav
    void backward_trav(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (trav->get_prev() == nullptr)
                return;
            trav = trav->get_prev();
        }
    }

    // go_to_start_trav
    void go_to_start_trav()
    {
        trav = start;
    }

    // go_to_end_trav
    void go_to_end_trav()
    {
        trav = end;
    }

public:
    DoubleLL() : start(nullptr), end(nullptr), trav(nullptr) {}

    // push_start
    void push_start(int val)
    {
        shared_ptr<Node> n = make_shared<Node>(val);

        if (!is_empty())
        {
            n->set_next(start);
            n->set_prev(nullptr);
            start->set_prev(n);
            start = n;
        }
        else
        {
            n->set_next(nullptr);
            n->set_prev(nullptr);
            start = n;
            end = n;
        }
    }

    // push_end
    void push_end(int val)
    {
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
    int pop_start()
    {
        int value = start->get_value();

        start = start->get_next();
        start->set_prev(nullptr);

        cout << "Pop start: " << value << endl;
        return value;
    }

    // pop_end
    int pop_end()
    {
        int value = end->get_value();

        end = end->get_prev();
        end->set_next(nullptr);

        cout << "Pop end: " << value << endl;
        return value;
    }

    // get_start
    int get_start()
    {
        cout << "Start: " << start->get_value() << endl;
        return start->get_value();
    }

    // get_end
    int get_end()
    {
        cout << "End: " << end->get_value() << endl;
        return end->get_value();
    }

    // display
    void display()
    {
        shared_ptr<Node> trav = start;
        cout << "Display: ";

        while (trav != nullptr)
        {
            cout << trav->get_value() << " ";
            trav = trav->get_next();
        }
        cout << endl;
    }
};