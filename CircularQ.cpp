#include <bits/stdc++.h>
using namespace std;

#define length 5

struct Q
{
  int front = 0;
  int rear = 0;
  int ara[length + 1];
};


void Enqueue (Q * circularQ, int value);
int Dequeu (Q * circularQ);
int
main ()
{
  Q circularQ;
  int holdDQ;
  Enqueue (&circularQ, 5);
  Enqueue (&circularQ, 10);
  Enqueue (&circularQ, 15);
  Enqueue (&circularQ, 20);
  Enqueue (&circularQ, 25);
  Enqueue (&circularQ, 30);
  // Enqueue(&circularQ,35);
  holdDQ = Dequeu(&circularQ);
  holdDQ = Dequeu(&circularQ);
  holdDQ = Dequeu(&circularQ);
  holdDQ = Dequeu(&circularQ);
  holdDQ = Dequeu(&circularQ);
  holdDQ = Dequeu(&circularQ);
  return 0;
}

void
Enqueue (Q * circularQ, int value)
{
  //cout << "rear " << circularQ->rear << endl;
  //cout << "front " << circularQ->front << endl;
  if (((circularQ->rear + 1) % (length + 1)) == circularQ->front)
    {
      cout << " queue is full! please delete some " << endl;
      return;
    }
  cout << value << " Inserted to the queue " << endl;
  circularQ->ara[circularQ->rear] = value;
  circularQ->rear = (circularQ->rear + 1) % (length + 1);
}

int
Dequeu (Q * circularQ)
{
  if (circularQ->front == circularQ->rear)
    {
      cout << "queue is empty " << endl;
      return -1;
    }
  cout << circularQ->ara[circularQ->
			 front] << " has been removed form the queue " <<
    endl;
  circularQ->front = (circularQ->front + 1) % (length + 1);
  return circularQ->ara[circularQ->front];
}
