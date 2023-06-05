#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int>directory;

    directory["namam"] = 745949;
    directory["pawan"] = 230472;
    directory["braj"] = 203497;

    for(auto element: directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"PhoneNo -"<<element.second<<endl;
    }cout<<endl; 

    directory["braj"] = 674865;//value updated

    for(auto element: directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"PhoneNo -"<<element.second<<endl;
    }cout<<endl; 

    return 0;
}