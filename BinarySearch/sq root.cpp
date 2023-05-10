/*
T.C. = O(log(n))
S.C. = O(1)
*/
#include <iostream>
using namespace std;

int sqrot(int n){
    int low = 1,hi = n;
    int ans = -1;
    while(low<=hi){
        int mid = low + (hi - low)/2;
        if(mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<sqrot(n);
}