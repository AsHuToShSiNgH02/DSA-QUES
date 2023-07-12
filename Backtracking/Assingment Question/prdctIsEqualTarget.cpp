#include <iostream>
using namespace std;

//NOTE: The |= operator is used in this code to accumulate the results of different recursive branches.
//if eithe of the recursive branches will return true the and will also become true
bool solve(int n,int trgt,int a[],int idx,int prd){
    //base condition
    if(idx==n)return prd == trgt;

    bool ans = false;
    //when we will take the element
    prd *= a[idx];
    ans |= solve(n,trgt,a,idx+1,prd);
    prd /= a[idx];
    
    //when we will not take the element and move forward
    ans |= solve(n,trgt,a,idx+1,prd);

    return ans;
}
int main(){
    int n,target;
    cin>>n>>target;
    int a[n];

    for(int i =0;i<n;i++){
        cin>>a[i];
    }

    cout<<(solve(n,target,a,0,1)?"YES" : "NO");
    return 0;
}