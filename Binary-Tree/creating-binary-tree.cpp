#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int item, Node *leftNode,Node *rightNode);
void addLeftChild(Node *node,Node *child);
void addRightChild(Node *node, Node *child);
Node *createTree();
int main()
{
    Node *treeRoot = createTree();
    
    
    return 0;
}

Node *createNode(int item, Node *leftNode,Node *rightNode){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL) cout<<"Node creating error";
    else{
        new_node->data = item;
        new_node->left = leftNode;
        new_node->right = rightNode;
    }
    return new_node;
    
}

void addLeftChild(Node *node,Node *child){
    node->left = child;
}

void addRightChild(Node *node, Node *child){
    node->right = child;
}

Node *createTree(){
    Node *two = createNode(2,NULL,NULL);
    Node *seven = createNode(7,NULL,NULL);
    Node *nine  = createNode(9,NULL,NULL);
    addLeftChild(two,seven);
    addRightChild(two,nine);
    
    Node *one = createNode(1,NULL,NULL);
    Node *six  = createNode(6,NULL,NULL);
    addLeftChild(seven,one);
    addRightChild(seven,six);
    
    Node *five = createNode(5,NULL,NULL);
    Node *ten  = createNode(10,NULL,NULL);
    addLeftChild(six,five);
    addRightChild(six,ten);
    
    Node *eight  = createNode(8,NULL,NULL);
    addRightChild(nine,eight);
    
    Node *three = createNode(3,NULL,NULL);
    Node *four  = createNode(4,NULL,NULL);
    addLeftChild(eight,three);
    addRightChild(eight,four);
    
    return two;
    
}

