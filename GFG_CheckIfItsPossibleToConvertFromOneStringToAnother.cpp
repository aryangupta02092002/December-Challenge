#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isItPossible(string s, string t, int M, int N) {
        // code here
        vector<pair<char, int>> v1, v2;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '#'){
                v1.push_back({s[i], i});
            }
            if(t[i] != '#'){
                v2.push_back({t[i], i});
            }
        }

        if(v1.size() != v2.size()){
            return 0;
        }

        for(int i=0; i<v1.size(); i++){
            if(v1[i].first != v2[i].first){
                return 0;
            }

            else{
                if(v1[i].first == 'A'){
                    if(v1[i].second < v2[i].second){
                        return 0;
                    }
                }
                else{
                    if(v1[i].second > v2[i].second){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution s;
        cout << s.isItPossible(S, T, M, N);
        cout << "\n";
    }
}