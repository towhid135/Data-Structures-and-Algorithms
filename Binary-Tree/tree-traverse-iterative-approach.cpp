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
void inOrder(Node *root);
int main()
{
    Node *treeRoot = createTree();
    
    inOrder(treeRoot);
    
    return 0;
}

void inOrder(Node *root){
    Node *stackTop;
    stack<Node *> Stack;
    Stack.push(root);
    
    while(!Stack.empty()){
        stackTop = Stack.top();
        if(stackTop->left != NULL){
            Stack.push(stackTop->left);
            stackTop->left = NULL;
        }else if(stackTop->right != NULL){
            Node *temp = stackTop;
            cout<<temp->data<<" ";
            Stack.pop();
            Stack.push(temp->right);
        }else{
            cout<<stackTop->data<<" ";
            Stack.pop();
        }
    }
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


