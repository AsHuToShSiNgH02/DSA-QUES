#include<bits/stdc++.h>
using namespace std;

// int *reverseArray(int arr[], int s, int e){
//     if(s >= e) return arr;
//     swap(arr[s], arr[e]);
//     reverseArray(arr, s+1, e-1);
// }
int *reverseArray(int arr[], int s, int n){
    if(s >= n/2) return arr;
    swap(arr[s],arr[n-s-1]);
    reverseArray(arr, s+1, n);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, 0, n);
    for(int i =0;i <n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}