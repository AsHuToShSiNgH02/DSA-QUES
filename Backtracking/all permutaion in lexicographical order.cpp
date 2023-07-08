/*print all the permutation of give string in lexicographical order*/

/**/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permutation(string &str, int i){
    //base case
    if(i==str.size()){
        cout<<str<<" ";
        return;
    }

    for(int j = i;j<str.size();j++){
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);//reverting all changes that's been done 
    }
}

void print(string str){
    sort(str.begin(),str.end());
    permutation(str,0);
}
int main(){
    string str = "bac";
    print(str);
    return 0;
}