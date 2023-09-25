#include <iostream>

struct Node {
    int key;
    int value;
    Node *next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
    private:
        static const int num_buckets = 10;

        // array of nodes
        Node *buckets[num_buckets];

        // hash functiion
        int hash(int key) {
            return key % num_buckets;
        }

    public:

        HashTable() {
            for (int i = 0; i < num_buckets; i++)
                buckets[i] = nullptr;
        }
        
        // insert
        void insert(int key, int value) {
            int index = hash(key);
            Node *n = new Node(key, value);

            if (!buckets[index]) // empty slot
                buckets[index] = n;
            
            else { // insert in start
                n->next = buckets[index];
                buckets[index] = n;
            }
        }

        // get
        int get(int key) {
            int index = hash(key);
            Node *trav = buckets[index];

            while (trav)            
            {
                if (trav->key == key)
                    return trav->value;
                trav = trav->next;
            }

            return -1;
        }

        // delete
        void remove(int key) {
            int index = hash(key);
            Node* tmp  = buckets[index];
            Node* prev = nullptr;

            while (tmp != nullptr)
            {
                if (tmp->key == key)
                {
                    if (prev)
                        prev->next = tmp->next;
                    else
                        buckets[index] = tmp->next;
                
                delete tmp;
                return;
                }

                prev = tmp;
                tmp = tmp->next;
            }
        }
};


int main()
{
    HashTable ht;

    ht.insert(1, 11);
    ht.insert(2, 22);
    ht.insert(3, 33);
    ht.insert(2, 48);

    std::cout << "Key 1: " << ht.get(1) << std::endl;
    std::cout << "Key 2: " << ht.get(2) << std::endl;

    ht.remove(2);
    std::cout << "Key 2 (rm1): " << ht.get(2) << std::endl;
    ht.remove(2);
    std::cout << "Key 2 (rm2): " << ht.get(2) << std::endl;
}