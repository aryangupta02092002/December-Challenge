#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int countVowel(string s){
    //     int count = 0;
    //     int sz = s.size();
    //     for(int i=0; i<sz; i++){
    //         if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
    //             count++;
    //         }
    //     }
    //     return count;
    // }
    // bool halvesAreAlike(string s) {
    //     return countVowel(s.substr(0, size(s) / 2)) == countVowel(s.substr(size(s) / 2));
    // }
    
    bool halvesAreAlike(string s) 
    {
        int left = 0;
        int right = s.length()-1;
        
        int cnt_A = 0;
        int cnt_B = 0;
        
        while(left < right){
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u' || s[left]=='A' || s[left]=='E' || s[left]=='I' || s[left]=='O' || s[left]=='U'){
                cnt_A++;
            }
            
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u' || s[right]=='A' || s[right]=='E' || s[right]=='I' || s[right]=='O' || s[right]=='U'){
                cnt_B++;
            }
            
            left++;
            right--;
        }
        
        return cnt_A == cnt_B;
    }
};

int main(){
    string str;
    getline(cin, str);
    Solution s;
    cout<<s.halvesAreAlike(str)<<endl;
}