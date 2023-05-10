/*
contructor is used to initialize the variables its called automatically without any explicit call,its names is same as that of class
*/
/*
destructor is called is being  deleted
*/
#include <iostream>
using namespace std;

class rectangle{
    public:
    int l;
    int b;

    rectangle(){ //default constructor
        l = 0;
        b = 0;
    }
    rectangle(int x,int y){ //parametrized constructor
        l = x;
        b = y;
    }
    rectangle(rectangle &r){ //copy constructor
        l = r.l;
        b = r.b;
    }
    ~rectangle(){
        cout<<"destructor is called"<<endl;
    }
};
int main(){

    //rectangle r1; // calling default constructor
    //cout<<r1.l<<" - "<<r1.b<<endl;
    rectangle *r1 = new rectangle(); //oblect is created with pointer variable
    cout<<r1->l<<" - "<<r1->b<<endl;
    delete r1; //only called in case of pointer variable


    rectangle r2(3,4); //calling parametrized constructor
    cout<<r2.l<<" - "<<r2.b<<endl;

    rectangle r3 = r2;  //calling copy constructor
    cout<<r3.l<<" - "<<r3.b;

    return 0;
}