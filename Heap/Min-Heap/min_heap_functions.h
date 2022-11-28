#include "parent.h"
#include "left_child.h"
#include "right_child.h"
#include "valid_index.h"
#include "swap.h"
#include "min.h"
#include <bits/stdc++.h>
using namespace std;

void min_heapify(int heap[], int heap_size, int index){
    int left_child_indx,right_child_indx,smallest;
    bool validIndex;

    left_child_indx = left_child(index);
    right_child_indx = right_child(index);
    
    if(valid_index(left_child_indx,heap_size) && valid_index(right_child_indx,heap_size)){
        smallest = min(heap,left_child_indx,right_child_indx);
        smallest = min(heap,index,smallest);

        if(heap[index] != heap[smallest]){
        swap(heap[index],heap[smallest]);
        min_heapify(heap, heap_size, smallest);
       }
       else return;
    }




}

void print_min_heap(int heap[], int heap_size){
    int i;
    for(i=1; i<=heap_size; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void is_min_heap(int heap[], int heap_size){
    int i;
    bool result = true;
    for(i=heap_size; i >= 1; i--){
        int parent_indx = parent(i);
        if(heap[parent_indx] > heap[i]) {
            result = false;
            break;
        }
    }
    string comment = result ? "Its a min heap" : "Not a min heap";
    cout<<comment<<": ";
    print_min_heap(heap,heap_size);
}



