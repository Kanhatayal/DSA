#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int atMost(vector<int> &nums, int k){
        int i = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 1)
                k--;
            while (k < 0) {
                if (nums[i] % 2 == 1)
                    k++;
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    int number_of_nice_subarrays(vector<int> &nums, int k){
        return atMost(nums, k) - atMost(nums, k-1);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;

    int ans = obj.number_of_nice_subarrays(nums,k);
    cout << "Answer = " << ans << endl;

    return 0;
}