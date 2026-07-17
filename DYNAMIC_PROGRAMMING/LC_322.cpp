#include <iostream>
#include <vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

// brute force recursive solution 
// space complexit includes recursion stack and vectors that i have taken in this soluiton 
class Solution1{
    public:
    vector<int> ans;
    vector<vector<int>> result;
    void solve(vector<int> &nums, int idx, int amount){
        // base case 
        if(amount == 0){
            result.push_back(ans);
            return;
        }
        if(amount < 0) return;
        for(int i = idx; i < nums.size(); i++){
            ans.push_back(nums[i]);
            solve(nums, i, amount  - nums[i]);
            ans.pop_back();
        }
        return;
    }
    int coinChange(vector<int> &nums, int amount){
        sort(nums.begin(), nums.end());
        solve(nums, 0, amount);
        int min_coins = INT_MAX;
        for(auto &i : result){
            min_coins = min(min_coins, (int)i.size());
        }
        return min_coins == INT_MAX ? -1 : min_coins;
    }
};
// no need of 2d result vector for my initial solution 
class Solution2{
    public:
    vector<int> ans;
    int min_coins = INT_MAX;
    void solve(vector<int> &nums, int idx, int amount){
        // base case 
        if(amount == 0){
            min_coins = min(min_coins, (int)ans.size());
            return;
        }
        if(amount < 0) return;
        for(int i = idx; i < nums.size(); i++){
            ans.push_back(nums[i]);
            solve(nums, i, amount  - nums[i]);
            ans.pop_back();
        }
        return;
    }
    int coinChange(vector<int> &nums, int amount){
        sort(nums.begin(), nums.end());
        solve(nums, 0, amount);
        return min_coins == INT_MAX ? -1 : min_coins;
    }
};
// 1D dp for coin change 
// cell shows how much coin we need to reach till that particular amount 
class Solution3{
    public:
    int amount_dp[10001];
    int solve(vector<int> &nums, int amount){
        // base case 
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int ans = INT_MAX;
        if(amount_dp[amount] != -1) return amount_dp[amount];

        for(auto coin: nums){
            int temp = solve(nums, amount - coin);

            if(temp != INT_MAX) ans = min(ans, temp+1);
        }
        amount_dp[amount] = ans;
        return ans;

    }
    int coinChange(vector<int> &nums, int amount){
        sort(nums.begin(), nums.end());
        memset(amount_dp, -1, sizeof(amount_dp));
        int ans = solve(nums, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};


int main(){
    Solution3 obj;
    vector<int> nums = {1,2,5};
    int amount = 11;

    int minimum_number_of_coins = obj.coinChange(nums, amount);

    cout<<minimum_number_of_coins<<endl;
    return 0;
}

