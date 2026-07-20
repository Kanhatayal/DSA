#include<iostream>
#include<vector>
#include<limits>
#include<string>
using namespace std;

// straight 2D dp solution 
class Solution{
    public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        int dp[n];
        dp[n-1] = 1;
        int ans = INT_MIN;
        for(int i = n-2; i > -1; i--){
            int LIS = 1;
            for(int j = i+1; j < n; j++){
                if(nums[j] > nums[i]){
                    LIS = max(LIS, dp[j]+1);
                }
            }
            dp[i] = LIS;
            ans   = max(ans, dp[i]);
        }
        return ans == INT_MIN ? 1 : ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int ans = obj.lengthOfLIS(nums);
    cout<<ans<<endl;
    return 0;
}