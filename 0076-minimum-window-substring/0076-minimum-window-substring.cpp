class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, freq;
        int minlen = INT_MAX, idx = -1;
        for(char& c: t){
            target[c]++;
        }
        int need = target.size(), have = 0, l = 0;
        for(int r = 0; r < s.size(); r++){
            if(target.find(s[r]) != target.end()){
                freq[s[r]]++;
                if(freq[s[r]] == target[s[r]]){
                    have++;
                }
            }
            if(have == need){
                while(have == need){
                    if(target.find(s[l]) != target.end()){
                        freq[s[l]]--;
                        if(freq[s[l]] < target[s[l]]){
                            have--;
                        }
                    }
                    l++;
                }
                int i = l - 1;
                if(r - i  + 1 < minlen){
                    minlen = r - i + 1;
                    idx = i;
                }
            }
        }
        if(idx == -1) return "";
        return s.substr(idx, minlen);
    }
};