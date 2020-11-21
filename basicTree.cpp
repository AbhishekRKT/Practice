#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node *left;
    Node *right;
 
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void preorder(Node *root){
    if(root){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Node *root){
    if (root == NULL)
    return;
    inorder(root -> left);
    cout << root->data;
    inorder(root ->right);
}

int main(){
    queue<Node *> q;
    int rootValue;
    cout << "Enter the value of root node" << endl;
    cin >> rootValue;
    Node *root = new Node(rootValue);
    q.push(root);
    

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        
        
            cout << "Enter the value of " << temp -> data << " left child" << endl;
            int leftValue;
            cin >> leftValue;

            if(leftValue != -1){
                Node *newNode = new Node(leftValue);
                q.push(newNode);
                temp -> left = newNode;

            }    
       
                int rightValue;
                cout << "Enter the value of " << temp -> data << " right child" << endl;
                cin >> rightValue;

                if(rightValue != -1){
                Node *newNode = new Node(rightValue);
                q.push(newNode);
                temp -> right = newNode;
            }

        
    }
    preorder(root);
    inorder(root); 

}