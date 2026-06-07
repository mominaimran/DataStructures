#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

Node *insert(Node *root, int val)
{
    Node *newNode = createNode(val);
    if (root == NULL)
    {
        cout << "parent Null(new root)" << endl;
        return newNode;
    }

    Node *x = root;
    Node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (val < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    if (val < y->data)
    {
        y->left = newNode;
    }
    else
    {
        y->right = newNode;
    }
    newNode->parent = y;
    return root;
}

bool iterativeSearch(Node *root, int key)
{
    Node *current = root;
    while (current != NULL)
    {
        if (key == current->data)
        {
            cout << "Value Found: " << current->data;
            return true;
        }
        if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    cout << "Value Not Found";
    return false;
}

bool recursiveSearch(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }
    if (key < root->data)
    {
        return recursiveSearch(root->left, key);
    }
    else
    {
        return recursiveSearch(root->right, key);
    }
}

Node *searchNode(Node *root, int key)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->data == key)
            return current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}

Node *findMin(Node *root)
{
    if (root == NULL)
    {
        cout << "underflow\n";
        return NULL;
    }

    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *findMax(Node *root)
{
    if (root == NULL)
    {
        cout << "underflow\n";
        return NULL;
    }

    Node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }

    return current;
}

Node *findSuccessor(Node *node)
{
    if (node == NULL)
        return NULL;

    if (node->right != NULL)
        return findMin(node->right);

    Node *parent = node->parent;

    while (parent != NULL && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node *findPredecessor(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    // Case 1: Right subtree exists
    if (node->left != NULL)
    {
        return findMax(node->left);
    }

    // Case 2: No right subtree
    Node *current = node;
    Node *parent = node->parent;

    while (parent != NULL && current == parent->left)
    {
        current = parent;
        parent = parent->parent;
    }

    return parent;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    // Step 1: search node
    Node *current = root;

    while (current != NULL && current->data != key)
    {
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
    {
        cout << "Node not found\n";
        return root;
    }

    // CASE 1: Leaf node
    if (current->left == NULL && current->right == NULL)
    {
        if (current->parent == NULL)
        {
            delete current;
            return NULL;
        }

        if (current->parent->left == current)
            current->parent->left = NULL;
        else
            current->parent->right = NULL;

        delete current;
        return root;
    }

    // CASE 2: One child
    else if (current->left == NULL || current->right == NULL)
    {
        Node *child = (current->left != NULL) ? current->left : current->right;

        if (current->parent == NULL)
        {
            child->parent = NULL;
            delete current;
            return child;
        }

        if (current->parent->left == current)
            current->parent->left = child;
        else
            current->parent->right = child;

        child->parent = current->parent;

        delete current;
        return root;
    }

    // CASE 3: Two children
    else
    {
        Node *successor = findMin(current->right);

        current->data = successor->data;

        // delete successor safely (it will have at most one child)
        root = deleteNode(root, successor->data);

        return root;
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;

    // Insertions
    root = insert(root, 14);
    insert(root, 12);
    insert(root, 6);
    insert(root, 16);
    insert(root, 18);

    // Traversals
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    // cout << "Preorder: ";
    // preorder(root);
    // cout << endl;

    // cout << "Postorder: ";
    // postorder(root);
    // cout << endl;

    //search
    iterativeSearch(root, 99);
    cout << recursiveSearch(root, 5);

    //find max
    Node *maxNode = findMax(root);
    if (maxNode != NULL)
    {
        cout << "Maximum Value: " << maxNode->data;
    }

    //find successor
    Node *node = searchNode(root, 12); // jis ka successor chahiye
    Node *succ = findSuccessor(node);
    if (succ != NULL)
    {
        cout << "\nSuccessor: " << succ->data;
    }
    else
    {
        cout << "\nNo Successor";
    }

    return 0;
}