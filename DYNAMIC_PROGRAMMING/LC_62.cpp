#include<iostream>
#include<cstring>
using namespace std;

// recursive solution, this will give TLE for higher values, now we have to  optimize it.
class Solution{
    public:
    int ans = 0;
    void solve(int i, int j, int m, int n){
        // base cases
        if((i == m-1) && (j == n-1)){
            ans +=1;
            return;
        }
        if((i == m) || (j == n)) return;
        solve(i+1, j, m, n);
        solve(i, j+1, m, n);
        return;
    }
    int UniquePaths(int m, int n){
        solve(0,0,m,n);
        return ans;
    }
};

// optimizing using memoization, every cell will that from that particular index how many paths are possible.
class Solution1{
    public:
    int ans = 0;
    int dp[101][101];
    int solve(int i, int j, int m, int n){
        // base cases
        if((i == m-1) && (j == n-1))
            return 1;
        if((i == m) || (j == n)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
        return dp[i][j];
    }
    int UniquePaths(int m, int n){
        memset(dp, -1, sizeof(dp));
        ans = solve(0,0,m,n);
        return ans;
    }
};

int main(){
    Solution1 obj;
    int result = obj.UniquePaths(3,7);
    cout<<result<<endl;

    return 0;
}