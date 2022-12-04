//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        vector<int> vow(26, 0), cons(26, 0);
        int v = 0, c = 0;
        
        for(auto ch : S){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vow[ch-'a']++;
                v++;
            }
            else{
                cons[ch-'a']++;
                c++;
            }
        }
        int i=0, k=0;
        if(abs(v - c) > 1) return "-1";
        bool fl = v >= c ? true : false;
        
        S = "";
        bool vv = false, cc = false;
        while(!vv && !cc) {
            
            if(fl) {
                while(i < 26 && vow[i] == 0) {
                    i++;
                }
                if(i >= 26) vv = true;
                else{
                    S += char(97 + i);
                    vow[i]--;
                } 
            }
            else {
                while(k < 26 && cons[k] == 0) {
                    k++;
                }
                if(k >= 26) cc = true;
                else {
                    S += char(97 + k);
                    cons[k]--;
                }
            }
            fl = !fl;
        }
        
        return S;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends