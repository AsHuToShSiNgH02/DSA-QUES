#include <iostream>
#include <vector>
using namespace std;
int rowWithMax1s(vector<vector<int> > &arr) {
	    // code here
        int n = arr.size();
        int m = arr[0].size();
	    int min = m;
	    int row = -1;
	    for(int i = 0;i<n;i++){
	        int low = 0;
	        int hi = m - 1;
	        while(low<=hi){
	            int mid = low + (hi - low)/2;
	            if(arr[i][mid]==1){
	                hi = mid - 1;
	            }else{
	                low = mid + 1;
	            }
	        }
	        if(low<min){
	            min = low;
	            row = i;
	        }
	    }
	    return row;
	}
    int main(){
        vector<vector<int>>arr = {{0,1,1,1},{1,1,1,1},{0,0,1,1},{0,0,0,0}};
        
        cout<<rowWithMax1s(arr)<<endl;

        return 0;
    }