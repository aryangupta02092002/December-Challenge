//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int m, int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

long long numOfWays(int N, int M)
{
    // write code here
    long long mod = 1e9+7, ans = 0, total = M*N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int count = 0;
            if(helper(N, M, i-2, j+1)){
                count++;
            }
            if(helper(N, M, i-2, j-1)){
                count++;
            }
            if(helper(N, M, i+2, j+1)){
                count++;
            }
            if(helper(N, M, i+2, j-1)){
                count++;
            }
            if(helper(N, M, i-1, j+2)){
                count++;
            }
            if(helper(N, M, i+1, j+2)){
                count++;
            }
            if(helper(N, M, i-1, j-2)){
                count++;
            }
            if(helper(N, M, i+1, j-2)){
                count++;
            }
            
            ans = (ans % mod + (total%mod - count%mod - 1%mod) % mod) % mod;
        }
    }
    return ans;
    
}

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}