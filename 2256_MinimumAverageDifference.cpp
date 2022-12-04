#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimumAverageDifference(vector<int> &nums){
        long long total = 0, sum = 0, mn = INT_MAX;
        int ans = 0;
        for(int i : nums){
            total += i;
        }

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            long long diff = total - sum;
            long long tmp = nums.size() - i - 1;
            int t = 0;

            if(tmp == 0){
                t = sum/(i+1);
            }
            else{
                t = (abs(sum/(i+1) - (diff/tmp)));
            }

            if(mn > t){
                mn = t;
                ans = i;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int a;  cin>>a;
        nums.push_back(a);
    }
    Solution sol;
    cout<<sol.minimumAverageDifference(nums);
}