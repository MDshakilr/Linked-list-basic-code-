#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* link;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = nullptr;
    return newNode;
}

// Function to delete the entire linked list
void deleteList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->link;
        delete current;
        current = next;
    }
}

// Function to print all the data in the linked list
void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
    cout << current->data << " ";
        current = current->link;
    }

    cout << endl;
}

int main() {
    // Create nodes using the function
    Node* head = createNode(45);
    head->link = createNode(98);
    head->link->link = createNode(3);

    // Print all the data in the linked list
    printList(head);

 // Delete the entire linked list
    deleteList(head);


    return 0;
}

