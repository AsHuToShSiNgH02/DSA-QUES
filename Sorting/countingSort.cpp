#include <bits/stdc++.h> 
using namespace std; 
 
void count_sort(int arr[], int n) 
{   
	
	int k = *max_element(arr, arr + n);  //finding the max element
	int count[k + 1] = { 0 };   //initializing count array

	for (int i = 0; i < n; i++) { //updating count array
		count[arr[i]]++; 
	} 
	for (int i = 1; i <= k; i++) { 
		count[i] = count[i] + count[i - 1]; //finding the prefix sum of count array
	} 
	int ans[n];                           
	for (int i = n - 1; i >= 0; i--) {  //finding the output array
		ans[--count[arr[i]]] = arr[i]; 
	} 
	for (int i = 0; i < n; i++) {  //coping the element of output array to original array
		arr[i] = ans[i]; 
	} 
} 

int main() 
{   
    
    
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
	// int arr[] = {5, 3, 0, 0, 3, 5, 6, 1, 7, 3, 0, 8, 1, 9, 5, 4, 2, 1, 0, 9, 0}; 
	// int n = sizeof(arr) / sizeof(arr[0]); 
	count_sort(arr, n); 

	cout << "Array after performing count sort : " << endl; 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	return 0; 
}
