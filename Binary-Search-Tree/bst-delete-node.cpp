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
Node *BST_Search(Node *root,int value);
Node *bst_minimum(Node *root);
Node *bst_transplant(Node *root,Node *tNode,Node *node);
Node *bst_delete(Node *root,int val);

int main()
{
    Node *bstRoot = BST(), *root;
    root = bst_delete(bstRoot,10);
    inOrder(root);
    
    //cout<<"minimum: "<<result->data<<endl;
    return 0;
}
Node *bst_delete(Node *root,int val){
    /*Here val is the value to be deleted  from the tree */
    Node *delNode,*small_node;
    //it will return the node to be deleted
    delNode = BST_Search(root,val);
    //if it has one child on left or has no child
    if(delNode->left == NULL){
        root = bst_transplant(root,delNode,delNode->right);
    }else if(delNode->right == NULL){
        root = bst_transplant(root,delNode,delNode->left);
    }else{
        small_node = bst_minimum(delNode->right);
        if(small_node->parent != delNode){
            /*If we don't replace here then we'll have duplicate value.*/
            root = bst_transplant(root,small_node, small_node->right);
            addRightChild(small_node,delNode->right);
        }
        root = bst_transplant(root,delNode,small_node);
        addLeftChild(small_node,delNode->left);
    }
    free(delNode);
    return root;
}

/*Here "tNode" will be transplant with "node"*/
Node *bst_transplant(Node *root,Node *tNode,Node *node){
    if(tNode == root){
        root = node;
    }else if(tNode->parent->left == tNode){
        tNode->parent->left = node;
    }else{
        tNode->parent->right = node;
    }
    return root;
}

//return minimum node of a tree
Node *bst_minimum(Node *root){
    Node *currentNode = root;
    while(currentNode->left != NULL){
        currentNode = currentNode->left;
    }
    return currentNode;
}

Node *BST_Search(Node *root,int value){
    if(root->data == value) return root;
    else if(value < root->data) BST_Search(root->left,value);
    else BST_Search(root->right,value);
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


