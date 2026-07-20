#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution{
    public:
    int wordBreak(string s, vector<string> &wordDict){
        
    }
};
int main(){
    Solution obj;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    bool ans = obj.solve(s, wordDict);
    cout<<ans<<endl;

    return 0;
}