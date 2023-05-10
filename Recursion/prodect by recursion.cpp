#include <iostream>
using namespace std;

int prod(int x ,int y){
    if(y>x) return prod(y,x);
    if(y==1 ) return x;
    if(y!=0)
    {
        return x + prod(x,y-1);
    }
    else
    {
        return 0;
    }

}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<prod(x,y);
}