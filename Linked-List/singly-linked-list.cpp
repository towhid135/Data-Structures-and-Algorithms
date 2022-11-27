#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *nextAddress;
};

Node *head = NULL;

Node *create_node(int item, Node *next);
void addNewNode(int item, Node *next);
void printLinkedList();
int main(){
    addNewNode(5,NULL);
    addNewNode(10,NULL);
     addNewNode(15,NULL);
    printLinkedList();
    return 0;
}

Node *create_node(int item, Node *next){
    Node *new_node = (Node *) (malloc(sizeof(Node)));
    new_node->data = item;
    new_node->nextAddress = next;
    
    return new_node;
}

void addNewNode(int item, Node *next){
    Node *currentNode, *newNode;
    newNode = create_node(item, next);
    if(head == NULL){
        head = newNode;
    }else{
        currentNode = head;
        while(currentNode->nextAddress != NULL){
            currentNode = currentNode->nextAddress;
        }
        currentNode->nextAddress = newNode;
        
    }
}

void printLinkedList(){
    Node *currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->data<<" ";
        currentNode = currentNode->nextAddress;
    }
}

