class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int r = 0; r < nums.size(); r++){
            freq[nums[r]]++;
            if(r > k){
                freq[nums[r - k - 1]]--;
            }
            if(freq[nums[r]] > 1) return true;
        }
        return false;
    }
};