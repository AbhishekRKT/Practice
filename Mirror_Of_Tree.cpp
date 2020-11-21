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
 
void MirrorTree(Node *root)
{
 
    if (root == NULL)
    return ;
    swap(root -> left, root -> right);
    MirrorTree(root -> left);
    MirrorTree(root -> right);
 
}
void preorder(Node *root){
    if(root){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
void printTree(Node *root){
    if(root == NULL) return;
    cout << root -> data << " : ";
    if(root -> left)
        cout << "L " << root -> left -> data << " ";
    if(root -> right)
        cout << "R " << root -> right -> data << " ";
    cout << endl;    
    printTree(root -> left);        
    printTree(root -> right);        
}
int main(){
 
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 
    preorder(root);
 
	printTree(root);
    cout << endl;
 
    MirrorTree(root);
    cout << "Traversal after mirroring of tree" << endl;
    preorder(root);
    printTree(root);
}