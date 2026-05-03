// Height of Binary Tree

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


// The height of a binary tree is the number of edges on the longest path from the root to a leaf node.
int height(Node* root) {
    if(root == NULL) return -1;

    int leftHeight = height(root->left); //recursively calculate the height of the left subtree
    int rightHeight = height(root->right); //recursively calculate the height of the right subtree

    return max(leftHeight, rightHeight) + 1; //return the maximum of left and right height plus one for the current node
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the binary tree is: " << height(root) << endl;
}