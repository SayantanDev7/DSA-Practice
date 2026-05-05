#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 1. Inorder Traversal -> Left -> Root -> Right
void Inorder(Node* root){
    if(root == NULL)
        return;
    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);

}

// 2. Preorder Traversal -> Root -> Left -> Right
void Preorder(Node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    Preorder(root -> left);
    Preorder(root -> right);

}

// 3. PostOrder Traversal -> Left -> Right -> Root
void Postorder(Node* root){
    if(root == NULL)
        return;
    Postorder(root -> left);
    Postorder(root -> right);
    cout << root -> data << " ";
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;


    return 0;
}


