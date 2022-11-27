#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *createNode(int item);
void addLeftChild(Node *parent, Node *child);
void addRightChild(Node *parent, Node *child);
Node *addNewNode(Node *root, Node *node);
Node *BST(void);
void inOrder(Node *root);
bool BST_Search(Node *root, int item);
int main()
{
    
    Node *BSTRoot;
    bool found;
    BSTRoot = BST();
    found = BST_Search(BSTRoot, 7);
    if(found) cout<<"search value found"<<endl;
    else cout<<"search value not found"<<endl;
    inOrder(BSTRoot);
    return 0;
}

bool BST_Search(Node *root, int item){
    bool result;
    if(root == NULL) return false;
    else if(root->data == item) return true;
    else if(item < root->data) result = BST_Search(root->left, item);
    else if(item > root->data) result = BST_Search(root->right, item);
    
    return result;
    
}

void inOrder(Node *root){
    if(root->left != NULL) inOrder(root->left);
    cout<<root->data<<" ";
    if(root->right != NULL) inOrder(root->right);
}

Node *createNode(int item){
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    if(new_node == NULL) {
        cout<<"Node creation error"<<endl;
        exit(1);
    }
    
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    
    return new_node;
}

void addLeftChild(Node *parent, Node *child){
    parent->left = child;
    //if child is "null" then we will get error for accessing "parent" if we don't check it before
    if(child != NULL) child->parent = parent;
    
}

void addRightChild(Node *parent, Node *child){
    parent->right = child;
     //if child is "null" then we will get error for accessing "parent" if we don't check it before
    if(child != NULL) child->parent = parent;
}

Node *addNewNode(Node *root, Node *node){
    Node *parentNode;
    Node *currentNode = root;
    
    if(root == NULL) {
         root = node;
         return root;
    }
    else{
        /*When reach to the child node we will get "NULL" to the currentNode->left or 
        currentNode->right, but we need to insert to the last node thats why we are 
        inserting the "currntNode" value into the parentNode before its change.
        */
        while(currentNode != NULL){
            parentNode = currentNode;
            
            if(node->data < currentNode->data) currentNode = currentNode->left;
            else currentNode = currentNode->right;
            
        }
        
        /*A new node in a BST always insets into a leaf node. after finishing while loop,
        here we will get the address of the leaf node in "parentNode". Then we need to compare
        the node->data with parentNode->data and insert it into proper place*/
        if(node->data < parentNode->data) addLeftChild(parentNode,node);
        else addRightChild(parentNode, node);
        return root;
    }
}

Node *BST(void){
    Node *root = createNode(10);
    Node *child;
    
    int childItem [] = {5, 17, 3, 7, 12, 19, 1, 4};
    
    for(int i=0; i<8; i++){
        child = createNode(childItem[i]);
        root = addNewNode(root,child);
    }
    
    return root;
    
}

