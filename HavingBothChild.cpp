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
 
 int BothChild(Node *root)
 {
     if(root != NULL)
     {
         int x = BothChild(root -> left);
         int y = BothChild(root -> right);

         if(root -> left && root -> right)
         {
         return x+y+1;
         }
         else
         {
             return x+y;
         }
     }
     return 0;
 }
int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 

}