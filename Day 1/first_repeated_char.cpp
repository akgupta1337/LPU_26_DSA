class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        vector<bool> seen(26, false);
        
        for(char& c: s){
            if(seen[c - 'a']) return string(1, c);
            seen[c - 'a'] = true;
        }
        return "-1";
    }
};

// https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1