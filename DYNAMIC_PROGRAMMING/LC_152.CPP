#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
using namespace std;

class Solution{
    public:
    int maxProduct(vector<int> &nums){
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix =1;
            if(suffix == 0) suffix =1;

            prefix *= nums[i];
            suffix *= nums[i];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums = {-2,0,-1};
    int ans = obj.maxProduct(nums);

    cout<<ans<<endl;
    return 0;
}