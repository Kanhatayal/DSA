#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;
    int dp[31][3001];
    int solve(int idx, vector<int>& stones, int target){
        if(idx >= stones.size()) return target;

        if(dp[idx][target] != -1) return dp[idx][target];

        int plus = solve(idx+1, stones, target + stones[idx]);
        int minus = solve(idx+1, stones, abs(target - stones[idx]));

        dp[idx][target] = min(plus, minus);
        return dp[idx][target];
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return solve(0, stones, 0);
    }
};