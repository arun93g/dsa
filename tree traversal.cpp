
#include <bits/stdc++.h>

using namespace std;

//node structure with constructor
struct Node{

  int value;
  Node* left;
  Node* right;

  Node(int Value)
  {
      value=Value;
      left=NULL;
      right=NULL;
  }

};

//inorder tree traveral
void inOrder(Node* node)
{
    if(node==NULL)
    return;

    inOrder(node->left);
    cout<<node->value<<" ";
    inOrder(node->right);
}

//preorder tree traversal
void preOrder(Node* node)
{
    if(node==NULL)
    return;

    cout<<node->value<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

//postorder tree traversal
void postOrder(Node* node)
{
    if(node==NULL)
    return;


    postOrder(node->left);
    postOrder(node->right);
    cout<<node->value<<" ";
}


int main()
{

    //tree creation
    Node *node=new Node(4);
    node->left=new Node(3);
    node->right=new Node(6);
    node->left->left=new Node(1);
    node->left->right=new Node(2);
    node->right->left=new Node(5);
    node->right->right=new Node(7);


    cout<<"InOrder Tree Traversal : ";
    inOrder(node);
    cout<<endl<<"preOrder Tree Traversal : ";
    preOrder(node);
    cout<<endl<<"postOrder Tree Traversal : ";
    postOrder(node);

    return 0;
}

