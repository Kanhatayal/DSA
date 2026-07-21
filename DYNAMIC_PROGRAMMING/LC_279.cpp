#include<math>
#include<iostream>
#include<algorithms>

class Solution {
public:
    const int INF = 1e9;
    bool isPerfectSquare(int x){
        int root = sqrt(x);
        return root*root == x;
    }
    int solve(vector<int> &nums, int target, int idx){
        if(target == 0) return 0;
        if(target < 0 ||  idx == nums.size()) return INF;

        int take = solve(nums, target - nums[idx], idx);
        if(take != INF) take++;
        int notTake = solve(nums, target, idx+1);
        return min(take, notTake);
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> nums;
        for(int i = n; i >= 1; i--){
            if(isPerfectSquare(i)) nums.push_back(i);
        }
        int result = solve(nums, n, 0);
        return  result;
    }
};
// memoization and nothing else, after this we will go for tabulation method
class Solution1 {
public:
    const int INF = 1e9;
    // mai yaha around 10000*10000*4 bytes = size i need
    // which is roughly around = 400 MB which is not fit for integer, which roughly  gives 256 MB
    int dp[10001][101];
    bool isPerfectSquare(int x){
        int root = sqrt(x);
        return root*root == x;
    }
    int solve(vector<int> &nums, int target, int idx){
        if(target == 0) return 0;
        if(target < 0 ||  idx == nums.size()) return INF;
        if(dp[target][idx] != -1) return dp[target][idx];

        int take = solve(nums, target - nums[idx], idx);
        if(take != INF) take++;
        int notTake = solve(nums, target, idx+1);
        dp[target][idx] = min(take, notTake);
        return dp[target][idx];
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> nums;
        for(int i = n; i >= 1; i--){
            if(isPerfectSquare(i)) nums.push_back(i);
        }
        int result = solve(nums, n, 0);
        return  result;
    }
};

int main(){
    Solution1 object;
    
}