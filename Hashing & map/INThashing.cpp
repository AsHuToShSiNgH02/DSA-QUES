// ********INTEGER-HASHING***********

//Hashing is precomputation and fetching of data
//inside main only 10⁶ size of arr is possible(in case of int)/(in case of bool arr can be of 10⁷ size)
//globaly we can declare at most 10⁷ size of arr(in case of int)/(in case of bool arr can be of 10⁸ size)
#include <iostream>
using namespace std;
// int hashh[10000000];//globaly 10^7
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //precomputation
    int hash[13] = {0};
    for(int i = 0;i<n;i++){
        hash[arr[i]] +=1;
    }

    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
        //fetching
    }

    return 0;
}