//Q1 - Given a number n, print the following pattern without using any loop.
//a, a-5, a-10, ..., 0, 5, 10, ..., a-5, n

#include <iostream>
using namespace std;

void rec(int n,int m,bool flag){

    cout<<m<<" ";

    //base conditon
    if(flag == false && m == n) return;

    if(flag){
        if(m-5>0){
            rec(n,m-5,true);
        }
        else{
            rec(n,m-5,false);
        }
    }
    //if false
    else{
        rec(n,m+5,false);
    }
}
int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    rec(n,n,true);
}