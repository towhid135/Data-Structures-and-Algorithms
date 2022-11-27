#include <bits/stdc++.h>

using namespace std;

int left(int root_indx);
int right(int root_indx);
int parent(int child_indx);
bool is_max_heap(int heap[], int heap_size);
void max_heapify(int heap[], int heap_size, int index);

int main()
{
    int heap[] = {0,3,6,5,1,4},heap_size = 5;
    bool isMaxHeap = is_max_heap(heap,heap_size);
    cout<<"Before apply max_heapify: is_max_heap: "<<isMaxHeap<<endl;
    
    
    max_heapify(heap,heap_size,1);
    isMaxHeap = is_max_heap(heap,heap_size);
    cout<<"After applying max_heapify: is_max_heap: "<<isMaxHeap<<endl;
    
    return 0;
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