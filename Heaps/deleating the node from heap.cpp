//deleting the node from heap
#include <iostream>
using namespace std;
int const N = 1e3;

void insertMinHeap(int minHeap[],int &size, int value){
    size++;
    minHeap[size] = value;
    int curr = size;
    while(curr/2 > 0 && minHeap[curr/2] > minHeap[curr]){
        swap(minHeap[curr/2],minHeap[curr]);
        curr = curr/2;
    }
}
void deleteMinHeap(int minHeap[], int &size){
    minHeap[1] = minHeap[size];
    size--;
    int curr = 1;
    while(curr*2<=size){
        int leftChild = 2*curr;
        int rightChild = 2*curr + 1;
        int minChild = leftChild;
        if(rightChild <= size && minHeap[rightChild] < minHeap[leftChild]){
            minChild = rightChild;
        }

        if(minHeap[minChild]>=minHeap[curr]){
            return;
        }
        swap(minHeap[minChild],minHeap[curr]);
        curr = minChild;
    }
}
int main(){
    int minHeap[N] = {-1,10 ,20, 30, 40, 50};
    int size = 5;
    int value = 5;
    insertMinHeap(minHeap, size, value);
    
    for(int i = 0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;

    deleteMinHeap(minHeap, size);
    for(int i = 0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;
}