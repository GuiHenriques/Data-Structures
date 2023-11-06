#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

    void insertRecursive(Node *&root, int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }

        else if (value < root->data)
        {
            insertRecursive(root->left, value);
        }

        else
        {
            insertRecursive(root->right, value);
        }
    }

    bool searchRecursive(Node *root, int value)
    {
        if (root == nullptr)
        {
            std::cout << value << " Not found" << std::endl;
            return false;
        }

        std::cout << root->data << std::endl;

        if (root->data == value)
        {
            std::cout << value << " Found" << std::endl;
            return true;
        }

        else if (value < root->data)
            return searchRecursive(root->left, value);

        else
            return searchRecursive(root->right, value);
    }

    void removeRecursive(Node *&root, int value)
    {
        if (root == nullptr)
            return;

        else if (value < root->data)
            removeRecursive(root->left, value);

        else if (value > root->data)
            removeRecursive(root->right, value);

        // value == root->data
        else
        {
            // Node with 1 child
            if (root->left == nullptr)
            {
                Node *tmp = root->right;
                delete root;
                root = tmp;
                return;
            }
            else if (root->right == nullptr)
            {
                Node *tmp = root->left;
                delete root;
                root = tmp;
                return;
            }

            // Node with 2 child
            else
            {
                Node *tmp = minValueNode(root->right);
                root->data = tmp->data;
                removeRecursive(root->right, tmp->data);
            }
        }
    }

    int sizeRecursive(Node *node)
    {
        if (node == nullptr)
            return 0;

        return sizeRecursive(node->left) + 1 + sizeRecursive(node->right);
    }

    int heightRecursive(Node *node)
    {
        if (node == nullptr)
            return -1; 
        else
        {
            int leftHeight = heightRecursive(node->left);
            int rightHeight = heightRecursive(node->right);

            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;
        }
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void displayInOrderRecursive(Node *root)
    {
        if (root == nullptr)
            return;

        displayInOrderRecursive(root->left);
        std::cout << root->data << " ";
        displayInOrderRecursive(root->right);
    }

    void displayPreOrderRecursive(Node *root)
    {
        if (root == nullptr)
            return;

        std::cout << root->data << " ";
        displayPreOrderRecursive(root->left);
        displayPreOrderRecursive(root->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value)
    {
        insertRecursive(root, value);
    }

    void remove(int value)
    {
        return removeRecursive(root, value);
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

    // size
    int size()
    {
        int size = sizeRecursive(root);
        std::cout << "Size: " << size << std::endl;
        return size;
    }

    // height
    int height()
    {
        int height = heightRecursive(root);
        std::cout << "Height: " << height << std::endl;
        return height;
    }

    // min
    int min()
    {
        if (root == nullptr)
        {
            return -1;
        }

        Node *current = root;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        std::cout << "Min: " << current->data << std::endl;
        return current->data;
    }

    // max
    int max()
    {
        if (root == nullptr)
            return -1;

        Node *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        std::cout << "Max: " << current->data << std::endl;
        return current->data;
    }

    // display
    void displayInOrder()
    {
        std::cout << "In Order: ";
        displayInOrderRecursive(root);
        std::cout << std::endl;
    }

    void displayPreOrder()
    {
        std::cout << "Pre Order: ";
        displayPreOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.insert(11);
    tree.height();
    tree.displayInOrder();
}