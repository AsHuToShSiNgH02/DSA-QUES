/*
T.C. = O(n)
S.C. = O(1
)*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestOnes(string str, int K) {
        int zeroCount = 0, left = 0;
        int maxLength = 0;
        for( int right = 0 ; right < str.size() ; ++right ) {
            if( str[right] == '0' ) ++zeroCount;
            while( zeroCount > K ) {
                if( str[left] == '0' ) --zeroCount;
                ++left;             //window contraction
            }
            maxLength = max( maxLength , right - left + 1 );    //updating maximum length at every iteration
        }
        return maxLength;
}
int main()
{
	string str;
    cout<<"Enter the string : ";
    cin>>str;
    int K;
    cout<<"Enter the number of flips allowed : ";
    cin>>K;
    cout<<"Desired output is: ";
	cout<<longestOnes(str , K);
	return 0;
}