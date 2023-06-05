/*Given an array of strings. You can move any number of characters from one string to any 
other string anynumber of times. You just have to make all of them equal.
Print “Yes” if you can make every string in the array equal by using any number 
of operations otherwise print
“No”.*/

/*LOGIC:
if the frequency of each char in array , is multiple of array size then only all strings can
become eqaul by moving chars from one str to another
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool canMakeEqual(vector<string> &s){

    unordered_map<char,int> m;

    for(auto str:s){
        for(auto ch:str){
            m[ch]++;
        }
    }
    int n = s.size();
    for(auto el:m){
        if(el.second%n!=0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;

    vector<string>v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }

    cout<<(canMakeEqual(v)? "YES" : "NO")<<endl;
}