//hepify the to make maxheap

#include <iostream>
using namespace std;
int const N = 1e3;

void Heapify(int minHeap[], int &size,int curr){

    while(curr*2<=size){
        int leftChild = 2*curr;
        int rightChild = 2*curr + 1;
        int minChild = leftChild;
        if(rightChild <= size && minHeap[rightChild] > minHeap[leftChild]){
            minChild = rightChild;
        }

        if(minHeap[minChild]<=minHeap[curr]){
            return;
        }
        swap(minHeap[minChild],minHeap[curr]);
        curr = minChild;
    }
}
int main(){
    int minHeap[N] = {-1,60,10,50,5,20,70};
    int size = 6;

    for(int i = size/2;i>=0;i--){
        Heapify(minHeap,size,i);
    }

    
    for(int i = 0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;

}