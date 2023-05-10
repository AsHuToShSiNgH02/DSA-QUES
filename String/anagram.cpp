/* words which are of same length and freq of each letters in both the words are same are known as anagram
T.C. = O(n)
S.C. = O(26)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s1,string s2){
    vector<int> freq(26,0);

    if(s1.length()!=s2.length()){ //checking the length both string
        return false;
    }
    
    for(int i = 0;i<s1.length();i++){
        freq[s1[i] - 'a']++;  //adding the freq of each letter
        freq[s2[i] - 'a']--;  // subtrating the freq of each letter
    }
    for(int i = 0;i<26;i++){
        if(freq[i]!=0){      //if words are anagram the after add and sub freq will null array
            return false;
        }
    }

    return true;
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;

    if(isAnagram(s1,s2)){
        cout<<s1<<" and "<<s2<<" are anagram.";
    }else{
        cout<<s1<<" and "<<s2<<" are not anagram.";
    }

    return 0;
}