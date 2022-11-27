#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *nextAddress;
};

Node *head = NULL;

void Push(int item);
void printStack();
int Pop();
int main(){
    Push(5);
    Push(10);
    Push(15);
    Push(20);
    Pop();
    printStack();
    
    return 0;
}

Node *create_node(int item, Node *next){
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) {
        cout<<"Memory allocation error"<<endl;
        return NULL;
    }
    new_node->data = item;
    if(next != NULL) new_node->nextAddress = next;
    else new_node->nextAddress = NULL;
    
    return new_node;
    
}

void Push(int item){
    Node *stackNode = create_node(item, head);
    head = stackNode;
    // cout<<stackNode<<" ";
    // cout<< &addressOfHead;
    
}

int Pop(){
    Node *deletedNode = head;
    int deletedData = deletedNode->data;
    head = head->nextAddress;
    free(deletedNode);
    return deletedData;
}

void printStack(){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->nextAddress;
    }
}

