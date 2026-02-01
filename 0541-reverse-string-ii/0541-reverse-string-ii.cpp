class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int l = 0; l < n; l += 2*k){
            int r = min(l + k, n);
            reverse(begin(s) + l, begin(s) + r);
        }
        return s;
    }
};