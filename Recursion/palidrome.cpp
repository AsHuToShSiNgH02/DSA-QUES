#include<bits/stdc++.h>
using namespace std;

bool palindrome(char str[], int s , int n){
    if(s>=n/2) return true;
    if(str[s] != str[n-s-1]) return false;
    palindrome(str, s+1, n);
}
int main(){
    char str[] = "abcb";
    int n = strlen(str);
    cout<<palindrome(str,0,n);
    return 0;
}