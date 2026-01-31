class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        
        for(int i=0; i<s.size(); i++){
            int left = i, right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--; right++;
                cnt++;
            }
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--; right++;
                cnt++;
            }
        }
        
        return cnt;
    }
};