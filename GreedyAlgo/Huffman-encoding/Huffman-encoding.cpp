#include <bits/stdc++.h>
using namespace std;

struct Node{
    char val;
    int freq;
    Node *left;
    Node *right;
   
    Node(char val, int freq){
        left = right = NULL;
        this->val = val;
        this->freq = freq;
    }
};

void preOrder(Node *root, string bit,string huffmanCode);
void printCode(string &huffmanCode);

int main(){
    vector<pair<char,int> > freq = {{'a',10},{'b',5},{'c',2},{'d',14},{'e',15}};
    string huffmanCode;
   
    struct comp{
      bool operator()(Node *l, Node *r){
         return l->freq > r->freq;
      }
    };
   
    priority_queue<Node*, vector<Node*>, comp > minHeap;
  
     for(int i=0; i<freq.size(); i++){
         minHeap.push( new Node(freq[i].first, freq[i].second) );
        
     }
    
     Node *left, *right, *tmp;
    
     while(minHeap.size()!=1){
       left = minHeap.top();
       minHeap.pop();
       right = minHeap.top();
       minHeap.pop();
      
       int freqSum = left->freq + right->freq;
       tmp = new Node('$',freqSum);
       tmp->left = left;
       tmp->right = right;
       minHeap.push(tmp);
     }
    //cout<<"top "<<minHeap.top()->val;
    preOrder(minHeap.top(),"",huffmanCode);
    // printCode(huffmanCode);
   
    return 0;
}

void preOrder(Node *root, string bit,string huffmanCode){
  if(root == NULL) return;
  huffmanCode += bit;
  if(root->val != '$') cout<<root->val<<" :"<<huffmanCode<<endl;
  preOrder(root->left,"0",huffmanCode);
  preOrder(root->right,"1",huffmanCode);
}

void printCode(string &huffmanCode){
  for(auto &ch : huffmanCode){
    cout<<ch;
  }
}
