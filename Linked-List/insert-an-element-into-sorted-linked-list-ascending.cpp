#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *nextAddress;
};

Node *head = NULL;

Node *createNode(int item, Node *next);
void createSortedList();
void printSortedList();
void addNewElement(int item);
int main()
{
    createSortedList();
    addNewElement(4);
    printSortedList();
    return 0;
}

Node *createNode(int item, Node *next){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = item;
    new_node->nextAddress = next;
    //cout<<new_node->value<<" ";
    return new_node;
}
void createSortedList(){
    vector<int> nums = {1,4,6,7,10,12,15,18,20,30};
    for(int i=0; i < nums.size(); i++){
        Node *created_node = createNode(nums[i],NULL);
        //cout<<created_node->value;
        if(head == NULL){
            head = created_node;
            //cout<<currentNode->value;
        }else{
            Node *currentNode = head;
            while(currentNode->nextAddress != NULL){
                currentNode = currentNode->nextAddress;
            }
            currentNode->nextAddress = created_node;
        }
    }
}

void printSortedList(){
    Node *currentNode;
    currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->value<<" ";
        currentNode = currentNode->nextAddress;
    }
}

void addNewElement(int item){
    Node *created_node = createNode(item,NULL);
    Node *currentNode =head;
    Node *previousNode = head;
    //cout<<created_node->value;
    
    if(head == NULL){
        head = created_node;
    }else{
        while(currentNode != NULL){
            if(created_node->value <= currentNode->value){
                if(currentNode == head){
                    created_node->nextAddress = currentNode;
                    currentNode = created_node;
                    head = currentNode;
                }else{
                    created_node->nextAddress = currentNode;
                    previousNode->nextAddress = created_node;
                }
                break;
            }
            //cout<<"currentNode value"<<currentNode->value<<" ";
            previousNode = currentNode;
            currentNode = currentNode->nextAddress;
        }
        //cout<<currentNode->value;
        if(currentNode == NULL){
            //cout<<"inserted into null";
            previousNode->nextAddress = created_node;
        }
    }
}

