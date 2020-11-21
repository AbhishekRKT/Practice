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

int sumOfAllNodes(Node *root){
  
   if(root == NULL)
   return 0;
   return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right); 
}

int SumOFNodes(Node * root) // Recursion Apporach By Abdul Bari
{
    if(root != NULL)
    {
        int x = SumOFNodes(root -> left);
        int y = SumOFNodes(root -> right);
        return x+y+root->data;
    }
    return 0;
}

int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 

    cout << sumOfAllNodes(root);
}