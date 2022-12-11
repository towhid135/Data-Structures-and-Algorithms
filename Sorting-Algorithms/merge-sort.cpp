#include <bits/stdc++.h>
using namespace std;

int *copy_ara(int main_ara[], int left, int right);
void print_ara(int ara[],int left,int right);
void merge_two_sorted_ara(int main_ara[],int left, int right, int mid);
void merge_sort(int main_ara[],int left, int right);


int main(){
    int main_ara[5] = {5,3,10,2,1},left=0,right=4;
    // merge_two_sorted_ara(main_ara,0,1,0);
    merge_sort(main_ara,left,right);
    print_ara(main_ara,left,right);
    return 0;
}

int *copy_ara(int main_ara[], int left, int right){
    int i, *copy_ara;

    //allocating space for the (right+1) size array
    copy_ara = (int *)malloc(sizeof(int) * (right+1));
    for(i=0; i<=right; i++){
        copy_ara[i] = main_ara[i];
    }
    return copy_ara;
}

void merge_two_sorted_ara(int main_ara[],int left, int right, int mid){
    int *left_ara,*right_ara,left_array_top_pointer = left,right_array_top_pointer = mid+1;
    int main_ara_index = left, left_ara_size = mid+1, right_ara_size = right+1,i,j;
    /*
    If we don't create copy of left and right array then we will loose the
    values inside left and right array. Because, during merging we are replacing the
    values in the main array, since left and right array are referance of main array then
    we will lose the values while replacing the values to the main array
    */
    left_ara = copy_ara(main_ara,left,mid);
    right_ara = copy_ara(main_ara,mid+1,right);
    // cout<<"left ara: ";
    // print_ara(left_ara,left,mid);
    // cout<<"right ara: ";
    // print_ara(right_ara,mid+1,right);
    
    

    while(left_array_top_pointer < left_ara_size && right_array_top_pointer < right_ara_size){
        if(left_ara[left_array_top_pointer] < right_ara[right_array_top_pointer]){
            main_ara[main_ara_index] = left_ara[left_array_top_pointer];
            left_array_top_pointer++;
        }else{
            main_ara[main_ara_index] = right_ara[right_array_top_pointer];
            right_array_top_pointer++;
        }
        
        
        main_ara_index++;
    }

    for(i=left_array_top_pointer; i < left_ara_size; i++){
        main_ara[main_ara_index] = left_ara[i];
        main_ara_index++;
    }

    
    for(j=right_array_top_pointer; j < right_ara_size; j++){
        main_ara[main_ara_index] = right_ara[j];
        main_ara_index++;
    }

}

void merge_sort(int main_ara[],int left, int right){
    if(left == right) return;
    int mid = (left+right) / 2;
    merge_sort(main_ara,left,mid);
    merge_sort(main_ara,mid+1,right);
    merge_two_sorted_ara(main_ara,left,right,mid);
}

void print_ara(int ara[],int left,int right){
    int i;
    for(i=left; i<=right; i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
}

