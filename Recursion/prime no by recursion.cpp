#include<iostream>
using namespace std;

string primeNo(int n,int m){
    if(m==2) return;
    if(n%m!=0)
    primeNo(n,m-1);
    else return "NO";
    
}
int main(){
    int n;
    cin>>n;
    cout<<primeNo(n,2);
}