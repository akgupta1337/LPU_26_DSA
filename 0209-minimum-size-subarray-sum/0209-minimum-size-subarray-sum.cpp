class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, curr_sum = 0, min_len = INT_MAX;

        for(int r = 0; r < nums.size(); r++){
            curr_sum += nums[r];
            if(curr_sum >= target){
                while(curr_sum >= target){
                    curr_sum -= nums[l++];
                }
                min_len = min(min_len, r - l + 2);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};