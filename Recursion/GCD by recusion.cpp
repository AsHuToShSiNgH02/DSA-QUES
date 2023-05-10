#include <iostream>
using namespace std;

int gcd(int a ,int b){
    if(b>a) return gcd(b,a);//swapping b and a if b>a
    if(b==0)return a;//base condition || when b will be zero then the value of 'a' will be gcd(a,b)
    return gcd(b,a%b); //returning till b becomes zero.

}
int main(){
    int a = 40;
    int b = 48;
    cout<<gcd(a,b);
}