class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int, int> mp;
        for(auto& n: nums){
            mp[n]++;
        }
        for(auto& it: mp){
            int num = it.first, cnt = it.second;
            freq[cnt].push_back(num);
        }
        vector<int> res;
        for(int i=n; i>=0; i--){
            if(!freq[i].empty()){
                for(auto& it: freq[i]){
                    res.push_back(it);
                }
            }
            if(res.size() == k) break;
        }
        return res;
        
    }
};