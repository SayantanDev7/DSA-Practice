// Inserting a Node Into a Sorted Doubly Linked List

// Given a reference to the head of a doubly-linked list and an integer, , create a new DoublyLinkedListNode object having data value 
// and insert it at the proper location to maintain the sort.

#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    Node *next;
    int data;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);

    // Case 1: Empty list
    if (head == NULL) return newNode;

    // Case 2: Insert at beginning
    if (data <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }


    //curr is used to traverse the list and find the correct position for the new node
    Node* curr = head;
    // Traverse the list to find the insertion point

    //checking if the next node's data is less than the new node's data, we move to the next node. This continues until we find a node whose data is greater than or equal to the new node's data, or we reach the end of the list.
    while(curr -> next != NULL && curr -> next -> data < data){
        curr = curr -> next;
    }

    newNode -> next = curr -> next;
    if(curr -> next != NULL){
        // If curr->next is not NULL, we need to update the prev pointer of the next node to point to the new node. This ensures that the doubly linked list remains properly linked in both directions.
        curr -> next -> prev = newNode;
    }

    // Finally, we update the next pointer of the current node to point to the new node, completing the insertion process.
    curr -> next = newNode;
    newNode -> prev = curr;

    return head;
}

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << "<->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main(){
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Node *head = NULL;
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        head = sortedInsert(head, data);
    }
    // Printing the original list 
    printList(head);

    //List after inserting a new node with value 5
    head = sortedInsert(head, 5);
    printList(head);

    return 0;
}