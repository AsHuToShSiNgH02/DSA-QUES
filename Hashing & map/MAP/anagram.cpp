/*Check whether two Strings are anagram of each other. Return true if they are else return
false.*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string a,string b){

    unordered_map<char,int>m;

    for(auto ch1:a){
        m[ch1]++; //storing the freq of char of string a in map
    }

    for(auto ch2:b){
        if(m.find(ch2)==m.end()){
            return false;
        }else{
            m[ch2]--;
        }   
    }
    
    for(auto ele:m){
        if(ele.second!=0){
            return false;
        }
    }
    return true;

}

int main(){
    string a;//triangle
    cin>>a;
    string b;//integral
    cin>>b;

    cout<<(isAnagram(a,b)? "YES":"NO")<<endl;

    return 0;
}