#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left= right = NULL;
    }
};

void allLeafNode(Node *root){
   if(root == NULL)
   return;
   if(root -> left == NULL and root -> right == NULL)
        cout << root -> data << " ";
    allLeafNode(root -> left);
    allLeafNode(root -> right);    
    
}


int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 

    allLeafNode(root);
}