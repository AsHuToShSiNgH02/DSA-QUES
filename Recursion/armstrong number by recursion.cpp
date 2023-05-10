#include <iostream>
using namespace std;

int pow(int n, int d){
    if(d == 0) return 1;
    if(d % 2==0){
        int result = pow(n,d/2);
        return result * result;
    }else{
        int result = pow(n,(d-1)/2);
        return n * result * result;
    }
}
int armstrong(int n,int d){
    if(n==0) return 0;
    return pow(n%10,d) + armstrong(n/10,d);
}
int main(){
    int n;
    cin>>n;
    
    int d = 0;
    int temp = n;
    while(temp>0){
        temp/=10;
        d++;
    }
    int result = armstrong(n,d);
    if(n == result){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}