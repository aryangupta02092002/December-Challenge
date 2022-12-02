#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool closeStrings(string s, string t){
        if(s.size() != t.size()){
            return 0;
        }
        vector<int> freq1(26, 0), freq2(26, 0), chr1(26, 0), chr2(26, 0);
        for(auto i : s){
            freq1[i-'a']++;
            chr1[i-'a'] = 1;
        }
        for(auto i : t){
            freq2[i-'a']++;
            chr2[i-'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && chr1 == chr2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        Solution s;
        cout << s.closeStrings(S, T);
        cout << "\n";
    }
}