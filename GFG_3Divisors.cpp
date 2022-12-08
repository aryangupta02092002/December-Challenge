//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        vector<int> prime = primeNo(1000000);
        for(long it : query){
            ans.push_back(helper(prime, it));
        }
        return ans;
    }
    vector<int> primeNo(int n){
        vector<int> prime(n+1, 1);
        prime[0] = 0;
        prime[1] = 0;
        
        for(int i=2; i<=n; i++){
            if(prime[i] == 1){
                for(int j=i+i; j<=n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        vector<int> list;
        for(int i=0;i<=n;i++) {
            if(prime[i] == 1) 
                list.push_back(i);
        }
        return list;
    }
    int helper(vector<int> prime, long long q) {
        int v1 = (int)sqrt(q);
        int low = 0, high = prime.size()-1;
        int ans=0;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(prime[mid] <= v1) {
                low = mid+1;
                ans = max(ans, mid+1);
            } 
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends