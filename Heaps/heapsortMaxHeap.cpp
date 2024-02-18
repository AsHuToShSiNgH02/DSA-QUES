//heapsort with the max heap
#include <iostream>
using namespace std;
int const N = 1e3;
void Heapify(int minHeap[], int &size,int curr){

    while(curr*2<=size){
        int leftChild = 2*curr;
        int rightChild = 2*curr + 1;
        int maxChild = leftChild;
        if(rightChild <= size && minHeap[rightChild] > minHeap[maxChild]){
            maxChild = rightChild;
        }

        if(minHeap[maxChild]<=minHeap[curr]){
            return;
        }
        swap(minHeap[maxChild],minHeap[curr]);
        curr = maxChild;
    }
}
void remove(int minHeap[],int &size){
    swap(minHeap[1],minHeap[size]);
    size--;
    Heapify(minHeap,size,1);
}
void heapSort(int minHeap[],int size){
    for(int i=size/2;i>0;i--){
        Heapify(minHeap,size,i);
    }

    while(size>0){
        remove(minHeap,size);
    }
}
int main(){
    int n = 7;
    int minHeap[N] = {-1,60,10,80,50,5,20,70};
    heapSort(minHeap,n);
    for(int i = 1;i<=n;i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;

    return 0;
}