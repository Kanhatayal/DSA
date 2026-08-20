class Solution {
public:
    int getNext(vector<int> &nums, int i){
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
    bool checkCircular(vector<int> &nums, vector<int> &visited, int start){
        bool forward = nums[start] > 0;
        int slow = start, fast = start;
        do {
            slow = getNext(nums, slow);
            if((nums[slow] > 0) != forward) return false;

            fast = getNext(nums, fast);
            if((nums[fast] > 0) != forward) return false;
            fast = getNext(nums, fast);
            if((nums[fast] > 0) != forward) return false;
        }while(slow != fast);


        return slow != getNext(nums, slow);
    }
    bool circularArrayLoop(vector<int>& nums) {
       int n  = nums.size();
       vector<int> visited(n, 0);
       for(int i = 0; i < n; i++){
        if(nums[i] == 0) continue;
        if(checkCircular(nums, visited, i)) return true;
       }
       return false;
    }
};