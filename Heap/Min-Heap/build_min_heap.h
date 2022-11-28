#include "min_heap_functions.h"

void build_min_heap(int heap[], int heap_size){
    int i;
    for(i = heap_size/2; i >= 1; i--){
        min_heapify(heap,heap_size,i);
    }
}