#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int result = INT_MIN;
    int dp[601][101][101];
    int max(int a, int b) {return a > b ? a : b;}
    pair<int, int> count(string s){
        int zeroes = 0, ones = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') zeroes++;
            else ones++;
        }
        return {zeroes, ones};
    }
    
    int solve(int idx, vector<string> &strs,int m, int n){
        if(idx >= strs.size()){
            return 0;
        } 
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        pair<int, int> p = count(strs[idx]);
        int include = 0;
        if(m - p.first >= 0 && n - p.second >= 0)
        include = 1 + solve(idx+1, strs, m - p.first, n - p.second);
        int exclude = solve(idx+1, strs, m, n);
        return dp[idx][m][n] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, strs, m, n);
    }
};