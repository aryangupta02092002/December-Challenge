#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string frequencySort(string s){
        unordered_map<char, int> u;
        priority_queue<pair<int, char>> mxHp;
        for(char ch : s){
            u[ch]++;
        }
        for(auto i : u){
            mxHp.push({i.second, i.first});
        }
        s = "";
        while(!mxHp.empty()){
            s += string(mxHp.top().first, mxHp.top().second);
            mxHp.pop();
        }
        return s;
    }
};

int main(){
    string s;
    getline(cin, s);
    Solution sol;
    cout<<sol.frequencySort(s)<<endl;
}