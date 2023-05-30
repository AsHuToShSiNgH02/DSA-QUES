#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool chkAllAlphabets(string &s){
    if(s.size() < 26){
        return false;
    }
    //(transform(khas se,khan tak,khan store krna hai,kun sa operation))
    transform(s.begin(),s.end(),s.begin(),::tolower);

    set<char> alpha;
    for(auto ch:s){
        alpha.insert(ch);
    }

    return (alpha.size()==26);
}
int main(){
    string alpha;
    cin>>alpha;

    if(chkAllAlphabets(alpha)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}