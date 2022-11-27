#include <bits/stdc++.h>

using namespace std;

int left(int root_indx);
int right(int root_indx);
int parent(int child_indx);
bool is_max_heap(int heap[], int heap_size);
void max_heapify(int heap[], int heap_size, int index);
void build_max_heap(int heap[], int heap_size);
void print_heap(int heap[], int heap_size);
int top(int heap[],int heap_size);
int pop(int heap[], int heap_size);
void push(int heap[],int heap_size, int new_val);
void max_priority_q(int heap[], int heap_size);

int main()
{
    int heap[] = {0,12,7,1,3,10,17,19,2,5},heap_size = 9;
    bool isMaxHeap = is_max_heap(heap,heap_size);
    string isMaxHeap_ = isMaxHeap == 0 ? "false" : "true";
    cout<<"Before applying build_max_heap: is_max_heap: "<<isMaxHeap_<<endl;
    cout<<"Before applying build_max_heap: ";
    print_heap(heap,heap_size);
    
    
    //max_heapify(heap,heap_size,1);
    build_max_heap(heap,heap_size);
    isMaxHeap = is_max_heap(heap,heap_size);
    isMaxHeap_ = isMaxHeap == 0 ? "false" : "true";
    cout<<"After applying build_max_heap: is_max_heap: "<<isMaxHeap_<<endl;
    cout<<"after applying build_max_heap: ";
    print_heap(heap,heap_size);
    
    //max_priority_q
    max_priority_q(heap, heap_size);
    
    return 0;
}

void max_priority_q(int heap[], int heap_size){
    int pressedNumber,topValue,popedValue,valueToPuhs;
    while(1){
        cout<<"Press 1, 2, & 3 inorder to perform top, push & pop respectively: ";
        cin>>pressedNumber;
        
        if(pressedNumber == 1) {
            topValue = top(heap,heap_size);
            cout<<"Top value is: "<<topValue<<endl;
        }
        else if(pressedNumber == 2){
            cout<<"Enter value to push: ";
            cin>>valueToPuhs;
            push(heap,heap_size,valueToPuhs);
            heap_size += 1;
            print_heap(heap,heap_size);
            
        }
        else if(pressedNumber == 3){
            pop(heap,heap_size);
            heap_size--;
            print_heap(heap,heap_size);
        }
        else break;
    }
}

int top(int heap[],int heap_size){
    if(heap_size >= 1) return heap[1];
    else return -1;
}

int pop(int heap[], int heap_size){
    int temp,max_val;
    if(heap_size > 1){
        max_val = heap[1];
        
        temp = max_val;
        heap[1] = heap[heap_size];
        heap[heap_size] = temp;
        
        heap_size -= 1;
        
        max_heapify(heap,heap_size,1);
        return max_val;
        
    }else{
        if(heap_size == 1) {
            return heap[1];
        }else -1;
    }
}


void push(int heap[],int heap_size, int new_val){
    heap_size += 1;
    heap[heap_size] = new_val;
    int child_indx = heap_size, temp;
    int parent_indx = parent(child_indx);
    while(parent_indx >= 1 && heap[parent_indx] < heap[child_indx] ){
        temp = heap[parent_indx];
        heap[parent_indx] = heap[child_indx];
        heap[child_indx] = temp;
        
        child_indx = parent_indx;
        parent_indx = parent(child_indx);
    }
}


void print_heap(int heap[], int heap_size){
    int i;
    for(i=1; i<=heap_size; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void build_max_heap(int heap[], int heap_size){
    /*We apply max_heapify in such cases where we know that both sub-tree of a node is already max heap.
    In a max heap we have n/2 (n=total nodes) leaf nodes. Since, leaf nodes are already heap we have start max_heapify from
    n/2 index and keep going to the left.*/
    int i;
    for (i=heap_size/2; i >= 1; i--){
        max_heapify(heap,heap_size,i);
    }
}

void max_heapify(int heap[], int heap_size, int index){
    int large, Left = left(index), Right = right(index), temp;
    
    if(Left <= heap_size && heap[Left] > heap[index]){
        large = Left;
    }else{
        large = index;
    }
    
    if(Right <= heap_size && heap[Right] > heap[large]){
        large = Right;
    }
    
    /*This is the base case, because if the root node is largest then we should return */
    if(large == index){
        return;
    }
    
    temp = heap[index];
    heap[index] = heap[large];
    heap[large] = temp;
    
    max_heapify(heap, heap_size, large);
    
}

//checks weather a heap is max heap or not
bool is_max_heap(int heap[], int heap_size){
    int i;
    for(i=heap_size; i > 1; i--){
        int parent_indx = parent(i), child_indx = i;
        if( heap[parent_indx] < heap[child_indx] ) return false;
    }
    return true;
}

//returns index of the left child of a node
int left(int root_indx){
    return root_indx * 2;
}

//returns index of the right child of a node
int right(int root_indx){
    return (root_indx * 2) + 1;
}

//returns index of the parent of a child node
int parent(int child_indx){
    return child_indx/2;
}



