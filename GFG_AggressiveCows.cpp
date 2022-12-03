#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPossible(vector<int> &s, int n, int cow, int dist){
        int count = 1;
        int lastCow = s[0];
        for (int i = 1; i < n; i++)
        {
            /* code */
            if(s[i]-lastCow >= dist){
                count++;
                lastCow = s[i];
            }
        }
        if(count >= cow){
            return true;
        }
        return false;
    }
};

int main(){
    int n, cow;
    cin>>n>>cow;
    vector<int> stalls;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int a;  cin>>a;
        stalls.push_back(a);
    }
    Solution sol;
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    while (low <= high)
    {
        /* code */
        int mid = (low + high) >> 1;
        if(sol.isPossible(stalls, n, cow, mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }
    cout<<high<<endl;
    
}