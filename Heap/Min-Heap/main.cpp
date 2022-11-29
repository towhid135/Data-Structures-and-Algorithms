#include "build_min_heap.h"

int main(){
    int heap[] = {0,3, 8, 15, 25, 10, 18, 6, 20, 2};
    int heap_size = 9;
    //befor applying build_min_heap
    is_min_heap(heap,heap_size);

    build_min_heap(heap,heap_size);

    //after applying build_min_heap
    is_min_heap(heap,heap_size);

    return 0;
}