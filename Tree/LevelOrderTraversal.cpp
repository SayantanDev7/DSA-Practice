// Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. In level-order traversal, 
// nodes are visited level by level from left to right. 
// Complete the function  levelOrder and print the values in a single line separated by a space.

#include<iostream>
#include<vector>
#include<queue>

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

//For level order traversal we will use queue data structure
//store the root in the queue and then keep on popping the front element and pushing its left and right child in the queue until the queue is empty
vector<int> levelOrder(Node* node){
    vector<int> ans; //to store the level order traversal
    if(node == NULL) return ans; //if the tree is empty return empty vector

    queue<Node*> q; //queue to store the nodes

    q.push(node); //push the root node in the queue
    while(!q.empty()){
        Node* temp = q.front(); //get the front element of the queue
        q.pop(); //pop the front element

        ans.push_back(temp->data); //store the data of the current node in the answer vector

        if(temp->left) q.push(temp->left); //if left child exists push it in the queue
        if(temp->right) q.push(temp->right); //if right child exists push it in the queue
    }
}

//let make a dummy tree to test our code
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = levelOrder(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}
