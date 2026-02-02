class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr_sum = 0, max_average = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            curr_sum += nums[i];
            if(i >= k){
                curr_sum -= nums[i - k];
            }
            if(i >= k - 1) max_average = max(max_average, curr_sum/k);
        }
        return max_average;
    }
};