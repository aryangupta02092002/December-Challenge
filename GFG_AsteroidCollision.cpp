//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int> result;
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                result.push_back(asteroid);
            }
            else {
                while (result.size() > 0 && result.back() > 0 && result.back() < abs(asteroid)) {
                    result.pop_back();
                }
                if (result.size() == 0 || result.back() < 0) {
                    result.push_back(asteroid);
                }
                else if (result.back() == abs(asteroid)) {
                    result.pop_back();
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
