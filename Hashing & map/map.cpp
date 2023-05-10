/*the map stores all the values in sorted order of key
map<int ,int >mpp 
    key  elem
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //precomputation
    map<int ,int>mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
        
    }

    
    int q;
    cin>>q;

    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        //fething
        cout<<mpp[x]<<endl;
    }
    
}