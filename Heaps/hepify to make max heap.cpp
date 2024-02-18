//hepify the to make maxheap

#include <iostream>
using namespace std;
int const N = 1e3;

void Heapify(int maxHeap[], int &size,int curr){

    while(curr*2<=size){
        int leftChild = 2*curr;
        int rightChild = 2*curr + 1;
        int maxChild = leftChild;
        if(rightChild <= size && maxHeap[rightChild] > maxHeap[leftChild]){
            maxChild = rightChild;
        }

        if(maxHeap[maxChild]<=maxHeap[curr]){
            return;
        }
        swap(maxHeap[maxChild],maxHeap[curr]);
        curr = maxChild;
    }
}
int main(){
    int maxHeap[N] = {-1,60,10,50,5,20,70};
    int size = 6;

    for(int i = size/2;i>=0;i--){
        Heapify(maxHeap,size,i);
    }

    
    for(int i = 0;i<=size;i++){
        cout<<maxHeap[i]<<" ";
    }cout<<endl;

}