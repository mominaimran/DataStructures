#include <iostream>
using namespace std;
// One class → one responsibility
// composition = aik class k andr dusri class ka object
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void createList(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int val;
            cout << "Enter value: ";
            cin >> val;

            Node *newNode = new Node(val);

            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newNode;
            }
        }
    }

    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList l1;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;

    l1.createList(n);
    // l1.insertAtStart(10);
    // l1.insertAtEnd(20);
    l1.display();

    return 0;
}