int min(int heap[],int index1, int index2){
    if(heap[index1] < heap[index2]) return index1;
    else return index2;
}