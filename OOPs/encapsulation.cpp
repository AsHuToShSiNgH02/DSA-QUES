/*
ENCAPSULATION : it si binding of methonds and variable into single unit (class)
*/
#include <iostream>
using namespace std;

class ABC{
    int x;

    public:
    void set (int n){
        x = n;
    }
    int get(){
        return x;
    }
};
 int main(){
    ABC obj;
    obj.set(2);//x cannot be printed diretly bcoz it is encapsulated by class ABC
    cout<<obj.get();

    return 0;
 }