class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();

        for(int i=0; i<n; i++){
            // take one in middle
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                left--; right++;
            }
            string s1 = s.substr(left+1, right - left -1);
            if(s1.size() > res.size()) res = s1;

            // take two in middle
            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                left--; right++;
            }
            s1 = s.substr(left+1, right - left -1);
            if(s1.size() > res.size()) res = s1;
        }
        return res;
    }
};