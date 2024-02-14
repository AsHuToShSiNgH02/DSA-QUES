#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int,int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Stack {
	// Define the data members.

   public:
   queue<int> q;

    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q.empty())return 1;
        return 0;
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        int s = q.size()-1;
        //shift the first inserted element to last so that it can follow LIFO DS
        while(s){
            q.push(q.front());
            q.pop();
            s--;
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q.empty())return -1;
        else{
            int val = q.front();
            q.pop();
            return val;
        }
        
    }

    int top() {
        // Implement the top() function.
        if(q.empty())return -1;

        return q.front();
    }
};

int main(){
    
    return 0;
}