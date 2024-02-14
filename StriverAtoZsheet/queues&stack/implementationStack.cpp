#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// Stack class.
class Stack {
    
public:
    int Top;
    int* arr;
    int size;
    Stack(int capacity) {
        // Write your code here.
        this->size = capacity;
        arr = new int[size];
        Top = -1;
    }

    void push(int num) {
        // Write your code here.
        if(isFull()) return;

        Top++;
        arr[Top] = num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;

        int val = arr[Top];
        Top--;
        return val;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;
        else return arr[Top];
    }
    
    int isEmpty() {
        // Write your code here.
        if(Top==-1) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(Top == size - 1) return 1;
        else return 0;
    }
    void display(){
        for(int i = 0;i<=Top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main(){
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();

    stack.display();
    return 0;
}