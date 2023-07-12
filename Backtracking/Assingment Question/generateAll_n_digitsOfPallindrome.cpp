#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
solve(int i,string curr){
    if(i<=(n+1)/2){
        for(char j = '0';j<='9';j++){
            curr.push_back(j);
            solve(i+1,curr);
            curr.pop_back();
        }
    }else{
        string temp = curr;
        if(n%2==1)temp.pop_back();
        reverse(temp.begin(),temp.end());
        cout<<curr + temp<<",";
    }
}
int main(){
    cin>>n;
    solve(1," ");
    return 0;
}