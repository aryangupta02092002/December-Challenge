#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void rearrange(long long *arr, int n) 
    { 
    	// Your code here
    	vector<long long> v;
    	long long mx = n-1;
    	long long mn = 0;
    	
    	for(int i=0; i<n; i++){
    	    if(i%2 == 0){
    	        v.push_back(arr[mx--]);
    	    }
    	    else{
    	        v.push_back(arr[mn++]);
    	    }
    	}
    	
    	for(int i=0; i<n; i++){
    	    arr[i] = v[i];
    	}
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        long long arr[n];
    
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        ob.rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
}