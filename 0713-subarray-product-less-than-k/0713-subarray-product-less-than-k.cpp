class Solution {
public:
    int solve(vector<int>& nums, int k){
        int res = 0, prod = 1, l = 0;
        for(int r = 0; r < nums.size(); r++){
            prod *= nums[r];
            while(l < r && prod >= k){
                prod /= nums[l++];
            }
            if(prod < k) res += (r - l) + 1;
        }
        return res;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};