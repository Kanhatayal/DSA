#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// here is the most elegant recursive solution 
class Solution{
    public:
    int solve(int idx, int n, int minProfit, vector<int> &group, vector<int> &profit, int number_of_people, int total_profit){
        if(number_of_people > n) return 0;
        
        if(idx == group.size()){
            return total_profit >= minProfit;
        }
        // yeh yaha ni memoization wale solution better samajh aaega, 
        // hum integer jo space lete hai nD arrays mai uska max size can be 256MB
        //  but my memoization is taking around 400MB
        //  so i was thinking what can i do so i came up with this along with chatgpt;
        int newProfit = min(total_profit + profit[idx], minProfit);
        int take = solve(idx + 1, n, minProfit, group, profit, number_of_people + group[idx], newProfit);
        int notTake = solve(idx+1, n, minProfit, group, profit, number_of_people, total_profit);

        return take + notTake;

    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit){
        int ans = solve(0, n, minProfit, group, profit, 0, 0);
        return ans;
    }
};

// memoization standard technique

    class Solution1 {
    public:
        const int MOD = 1e9 + 7;
        int dp[101][101][101];
        int solve(int idx, int n, int minProfit, vector<int>& group, vector<int>& profit, int number_of_people, int total_profit){
            if(number_of_people > n) return 0; 
            if(idx == group.size()) 
                return (number_of_people <= n && total_profit >= minProfit);
            if(dp[idx][number_of_people][total_profit] != -1) return dp[idx][number_of_people][total_profit];

            int newProfit = min(total_profit + profit[idx], minProfit);
            int take = solve(idx + 1, n, minProfit, group, profit, number_of_people + group[idx], newProfit);
            int notTake = solve(idx+1, n, minProfit, group, profit, number_of_people, total_profit);

            return dp[idx][number_of_people][total_profit]  = (take + notTake) % MOD;
        }
        int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            memset(dp, -1, sizeof(dp));
            int ans = solve(0, n, minProfit, group, profit, 0, 0);
            return ans;
        }
    };
int main(){
    Solution1 obj;
    int n = 10;
    int minProfit = 5;
    vector<int> group = {2,3,5};
    vector<int> profit = {6,7,8};

    int ans = obj.profitableSchemes(n, minProfit, group, profit);

    cout<<ans<<endl;

    return 0;
}