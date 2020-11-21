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

void preorder(Node *root)
{
    cout << "inorder traversal" << endl;
    stack<Node *>s;
    s.push(root);
    
    while(!s.empty())
    {
     Node *node = s.top();
     cout << node -> data << " ";
     s.pop();

     if(node -> right)
     {
         s.push(node -> right);
     }

      if(node -> left)
      {
         s.push(node -> left);
      }
    }
    cout << endl;
}

void inorder(Node *root)
{
    cout << "preorder traversal" << endl;
    stack<Node *>s;
    while(root != NULL || !s.empty())
    {
        if(root != NULL)
        {
            s.push(root);
            root = root -> left;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root->data << " ";
            root = root -> right;
        }
    }
    cout << endl;
}

void postorder(Node *root)
{
    cout << "Postorder Traversal" << endl;
    stack<Node *>s;
    s.push(root);
    while(!s.empty())
    {
       if(root -> right != NULL)
       {
           s.push(root -> right); 
       }
      else if(root -> left != NULL)
       {
           s.push(root -> left);
       }

       else
       {
           cout << root->data << " ";
           s.pop();
           root = s.top();
       } 
    }
    cout << root->data;
    cout << endl;
}
 void levelorder(Node *root)
 {
     cout << "Level order traversal" << endl;
     queue<Node *>q;
     cout << root -> data << " ";
     q.push(root);

     while(!q.empty())
     {
         cout << root->left-> data << " ";
         cout << root -> right -> data << " ";

        if(root -> left!=NULL)
        {
            q.push(root -> left);
        }

        if(root -> right!=NULL)
        {
            q.push(root -> right);
        }
         q.pop();
        root = q.front();
     }
 }
 
int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5);
    preorder(root);
    inorder(root); 
    //postorder(root);
    levelorder(root);
    
}