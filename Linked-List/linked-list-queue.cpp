#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *nextAddress;
};

Node *head = NULL;
Node *tail = NULL;

Node *createNode (int item, Node * next);
void Enqueue(int value);
void printQ(void);
int Dequeue (void);
int main ()
{
  Node *n;
  int holdValue;
  //n = createNode(5,NULL);
  Enqueue(5);
  Enqueue(10);
  Enqueue(15);
  Enqueue(20);
  Enqueue(25);
  printQ();
  holdValue = Dequeue();
  holdValue = Dequeue();
  holdValue = Dequeue();
  holdValue = Dequeue();
  printQ();
  
  return 0;
}

Node *createNode (int item, Node *next)
{
  Node *new_node = (Node *) malloc (sizeof (Node));
  if(new_node == NULL) cout<<"Can't allocate memory"<<endl;
  new_node->data = item;
  new_node->nextAddress = next;
  
  //cout<<"inside create node "<<new_node->data;

  return new_node;
}

void Enqueue (int value)
{
  Node *new_q_node = createNode (value, NULL);
  if(head == NULL && tail == NULL){
      head = new_q_node;
      tail = new_q_node;
  }else{
      tail->nextAddress = new_q_node;
      tail = new_q_node;
  }
}

int Dequeue (void){
    if(head == NULL && tail == NULL){
        cout<<"Queue is empty";
        return -1;
    }else{
    Node *deleteNode = head;
    int deletedValue = deleteNode->data;
    if(head == tail){
        head = tail = NULL;
    }else{
        head = deleteNode->nextAddress;
        free(deleteNode);
    }
    return deletedValue;
    
    }
}

void printQ(void)
{
  Node *nodeAddressHolder = head;
  while (nodeAddressHolder)
    {
      cout<<nodeAddressHolder->data << " ";
      nodeAddressHolder = nodeAddressHolder->nextAddress;
    } 
    cout<<endl;
}

