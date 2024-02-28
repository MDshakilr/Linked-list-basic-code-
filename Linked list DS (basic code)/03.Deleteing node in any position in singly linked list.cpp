#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
Node* insert(Node* head, int value)
{
    Node* newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node from any position
Node* deleteNode(Node* head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty. Deletion not possible.\n";
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;

    // Traverse to the node at the specified position
    for (int i = 0; i < position && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // Check if the position is valid
    if (temp == nullptr)
    {
        cout << "Invalid position. Deletion not possible.\n";
        return head;
    }

    // Adjust pointers to skip the node to be deleted
    if (prev == nullptr)
    {
        // If deleting the head
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    // Delete the node
    delete temp;
    cout << "Node at position " << position << " deleted successfully.\n";

    return head;
}

// Function to print the linked list
void print(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;

    // Inserting elements into the linked list
    head = insert(head, 45);
    head = insert(head, 98);
    head = insert(head, 3);
    head = insert(head, 4);

    // Displaying the original linked list
    cout << "Original Linked List: ";
    print(head);

    // Deleting node at position 2
    head = deleteNode(head, 2);

    // Displaying the linked list after deletion
    cout << "Linked List after deletion: ";
    print(head);

    return 0;
}
