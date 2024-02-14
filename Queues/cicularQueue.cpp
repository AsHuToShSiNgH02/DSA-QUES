#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Queue{
    int front;
    int back;
    vector<int> v;
    int cs;
    int ts;
public:
    Queue(int n){
        v.resize(n);
        this->front = 0;
        this->back = n-1;
        this->cs = 0;
        this->ts = n;
    }
    void enqueue(int data){
        if(isFull()) return;
        this->back = (this->back + 1) % this->ts; //so that back resets to 0 after back cross n-1
        this->v[this->back]=data;
        this->cs++;
    }
    void dequeue(){
        if(isEmpty()) return;
        this->front = (this->front + 1) % this->ts; //so that front reset to 0 after front cross n-1
        this->cs--;
    }
    bool isEmpty(){
        return this->cs == 0;
    }
    bool isFull(){
        return this->cs == this->ts;
    }
    void display(){
        while (!isEmpty())
        {
            cout<<this->v[this->front]<<" ";
            dequeue();
        }
        
    }
};
int main(){
    Queue qu(3);
    qu.enqueue(5);
    qu.enqueue(6);
    qu.enqueue(7);
    qu.dequeue();
    qu.enqueue(8);

    qu.display();
    return 0;
}