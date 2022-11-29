#include "../Min-Heap/build_min_heap.h"

int top(int heap[]){
    return heap[1];
}

void push(int heap[], int heap_size, int item){
    heap_size += 1;
    heap[heap_size] = item;
    int parent_indx = parent(heap_size), temp,child_indx = heap_size;
    while( (heap[parent_indx] >  heap[child_indx]) && parent_indx >= 1 ){
        temp = heap[parent_indx];
        heap[parent_indx] = heap[child_indx];
        heap[child_indx] = temp;

        child_indx = parent_indx;
        parent_indx = parent(child_indx);
    }
    cout<<"After push current heap: ";
    print_min_heap(heap,heap_size);
}

int pop(int heap[], int heap_size){
    int temp;
    cout<<"heap_size: "<<heap_size<<endl;
    temp = heap[1];
    heap[1] = heap[heap_size];
    heap[heap_size] = temp;

    heap_size -= 1;

    min_heapify(heap, heap_size, 1);
    cout<<"After pop current heap: ";
    print_min_heap(heap,heap_size);
    return temp;
}

void min_priority_q(){
    int heap[] = {0,3, 8, 15, 25, 10, 18, 6, 20, 2};
    int heap_size = 9, val;
    build_min_heap(heap,heap_size);

     int pressedNumber,topValue,popedValue,valueToPush;
    while(1){
        //cout<<"heap size: "<<heap_size<<endl;
        cout<<"Press 1, 2, & 3 inorder to perform top, push & pop respectively: ";
        cin>>pressedNumber;
        
        if(pressedNumber == 1) {
            topValue = top(heap);
            cout<<"Top value is: "<<topValue<<endl;
        }
        else if(pressedNumber == 2){
            cout<<"Enter value to push: ";
            cin>>valueToPush;
            push(heap,heap_size,valueToPush);
            heap_size += 1;
        }
        else if(pressedNumber == 3){
            popedValue = pop(heap,heap_size);
            heap_size -= 1;
        }
        else break;
    }
}