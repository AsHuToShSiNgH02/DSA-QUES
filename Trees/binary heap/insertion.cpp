#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;
int const N = 1e3;

void deleteMinHeap(int minHeap[] )
void insertionMinHeap(int minHeap[] ,int value,int &size){
    size++;
    minHeap[size] = value;
    int curr = size;
    while(curr/2 > 0 && minHeap[curr/2] > minHeap[curr]){
        swap(minHeap[curr/2] ,minHeap[curr]);
        curr = curr/2;
    }
}
int main(){
    int minHeap[N] = {-1, 10, 20, 30 ,40 ,50};
    int size = 5;
    int value = 5;
    insertionMinHeap(minHeap, value, size);
    for(int i = 0;i<=size;i++){
        cout<<minHeap[i]<<" ";
    }
    return 0;
}