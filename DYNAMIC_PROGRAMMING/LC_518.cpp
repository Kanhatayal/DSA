#include<iostream>
#include<vector>
using namespace std;

// for recursive solution, solution will be same as coin change, just return result vector size, but that will not work or i should say it will give memory limit exceeded.
// so thats why i am directly going for memoization
class Solution{
    public:
    int dp[301][5001];
    int solve(vector<int> &nums, int amount, int idx){
        if(amount == 0) return 1;
        if(amount < 0 || idx == nums.size()) return 0;

        int take = solve(nums, amount - nums[idx], idx);
        int notTake = solve(nums, amount, idx+1);

        return dp[idx][amount] = take + notTake;
    }
    int change(vector<int> &nums, int amount){
        memset(dp, -1, sizeof(dp));
        int result = solve(nums, amount, 0);
        return result;
    }
};

void main(){
    Solution o;
    vector<int> coins = {1,2,5};
    int amount = 5;

    int total_coins_combination = o.change(coins, amount);
    cout<<ans<<endl;
    return; 
}