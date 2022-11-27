#include <bits/stdc++.h>

using namespace std;

int left(int root_indx);
int right(int root_indx);
int parent(int child_indx);
bool is_max_heap(int heap[], int heap_size);
void max_heapify(int heap[], int heap_size, int index);
void build_max_heap(int heap[], int heap_size);
void heap_sort(int heap[], int heap_size);
void print_heap(int heap[],int heap_size);

int main()
{
    int heap[] = {0,12,7,1,3,10,17,19,2,5},heap_size = 9;
    bool isMaxHeap = is_max_heap(heap,heap_size);
    cout<<"Before apply build_max_heap: is_max_heap: "<<isMaxHeap<<endl;
    
    
    //max_heapify(heap,heap_size,1);
    build_max_heap(heap,heap_size);
    isMaxHeap = is_max_heap(heap,heap_size);
    cout<<"After applying build_max_heap: is_max_heap: "<<isMaxHeap<<endl;
    cout<<"Before heap sort: ";
    print_heap(heap,heap_size);
    cout<<endl<<"After heap sort: ";
    heap_sort(heap,heap_size);
    print_heap(heap,heap_size);
    
    return 0;
}

void print_heap(int heap[],int heap_size){
    int i;
    for(i=1; i<=heap_size; i++){
        cout<<heap[i]<<" ";
    }
}

void heap_sort(int heap[], int heap_size){
    /*pre-requisite of heap sort is to build a max_heap initially */
    int temp,i;
    for(i=heap_size; i>=1; i--){
        temp = heap[1];
        heap[1] = heap[heap_size];
        heap[heap_size] = temp;
        
        heap_size--;
        max_heapify(heap,heap_size,1);
    }
    //we can also do it like this
    /*for(i=1; i<=heap_size; i++){
        temp = heap[1];
        heap[1] = heap[heap_size - (i-1)];
        heap[heap_size - (i-1)] = temp;
        
        max_heapify(heap,heap_size-i,1);
    }*/
    
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

