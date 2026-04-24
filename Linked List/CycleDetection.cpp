// A linked list is said to contain a cycle if any node is visited more than once while traversing the list. 
// Given a pointer to the head of a linked list, determine if it contains a cycle. If it does, return true. Otherwise, return false.
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* createLL(Node* head,int data){
    Node* newNode = new Node(data);
    if(head == NULL)
        return newNode;
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    cout << "Linked List: ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool cycledetection(Node* head){
    if(head == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next; // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
        
        if(slow == fast){ // If both pointers meet, there is a cycle
            return true;
        }
    }

    return false; // If fast pointer reaches the end, there is no cycle
    
}


int main(){
    int n;
    
    cout << "Enter the length of the linked list: ";
    cin >> n;
    
    Node* head = NULL;
    cout << "Enter the values to be inserted in Lined List: ";
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        head = createLL(head,data);
    }
    printLL(head);

    bool hasCycle = cycledetection(head);
    if(hasCycle){
        cout << "The linked list contains a cycle." << endl;
    }else{
        cout << "The linked list does not contain a cycle." << endl;
    }
}