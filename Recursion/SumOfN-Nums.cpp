#include<bits/stdc++.h>

using namespace std;

void SumN(int n, int sum){
    if(n == 0){
        cout<<sum ; 
        return;
    } 
    SumN(n-1, sum+n);
}

int main(){
    int n;
    cin>>n;
    
    SumN(n, 0);
    return 0;
}