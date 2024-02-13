#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int largestElement(vector<int> &arr, int n) {
    int largestElement = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>largestElement){
            largestElement = arr[i];
        }
    }
    return largestElement;
}
int main(){
    
    return 0;
}