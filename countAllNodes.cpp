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
// Using Recursion
int countNodes(Node *root){
    if(root == NULL)
        return 0;
    return 1 + countNodes(root -> left) + countNodes(root -> right) ;   
}

// using Recursion
int countOfNode(Node *root)
{
    int x,y;
    if(root != NULL)
    {
        x = countOfNode(root -> left);
        y =countOfNode(root -> right);
        return x+y+1; 
    }
    return 0;
}
int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 

    cout << countNodes(root);
}