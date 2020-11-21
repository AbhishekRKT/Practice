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


//Recursion solution of Height of tree in two line

int calculateHeight(Node *root)
{
     if(root == NULL)
        return 0;
        return max(calculateHeight(root -> left), calculateHeight(root -> right)) + 1;  // above commented code can be written like this also
}

int HeightOFTree(Node *root)  // Recursion
{
    if(root == NULL)
     return 0;
    
    else
    {
         int lDepth = HeightOFTree(root -> left);
         int rDepth = HeightOFTree(root -> right);
         if(lDepth > rDepth)
         {
            return lDepth+1;
         }
         else
         {
             return rDepth+1;
         }  
    }
    

}
int heightOfTree(Node *root) // iterative
{
    if(root == NULL)
        return -1;

    queue<Node*> q;
    q.push(root);
    int height = -1;

    while(true)
    { 

        int size = q.size();
        if(size == 0)
            break;

        while(size > 0){

            Node *temp = q.front();

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);

            q.pop();   
            size--;        

        }
        height++;


    }
    return height;
}


int main(){

    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left =  new Node(4); 
    root->left->right = new Node(5); 

    cout << calculateHeight(root);
}