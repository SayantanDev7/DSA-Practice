// Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. In level-order traversal, 
// nodes are visited level by level from left to right. 
// Complete the function  levelOrder and print the values in a single line separated by a space.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}
