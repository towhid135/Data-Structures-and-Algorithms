#include <bits/stdc++.h>

using namespace std;


int left(int root_indx);
int right(int root_indx);
int parent(int child_indx);
bool is_max_heap(int heap[], int heap_size);


int main()
{
    /*To store a heap in an array we need to place the root at index 1. And left child of each node will be at
    2n index and the right child  will be at 2n+1 index. Here n is the index of root.*/
    int heap_size = 10;
    bool result;
    int heap_ara[] = {0,19,7,17,3,5,12,10,1,2};
    result = is_max_heap(heap_ara, heap_size);
    
    if(result) cout<<"It is a max heap";
    else cout<<"Not a max heap";

    return 0;
}

bool is_max_heap(int heap[], int heap_size){
    int i;
    for(i=heap_size-1; i > 1; i--){
        int parent_indx = parent(i), child_indx = i;
        if( heap[parent_indx] < heap[child_indx] ) return false;
    }
    return true;
}

int left(int root_indx){
    return root_indx * 2;
}

int right(int root_indx){
    return (root_indx * 2) + 1;
}

int parent(int child_indx){
    return child_indx/2;
}
