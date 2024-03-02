#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007
using namespace std;
template<typename T>
using vec = vector<T>;

double  minCells(int n , int k){
    if(k != ((4*n)-2)){
        return ceil(k/2);
    }else{
        return n*2;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    double val = minCells(n, k);
    cout<<val<<endl;
}