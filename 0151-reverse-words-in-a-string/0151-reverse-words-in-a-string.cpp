class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size();
        
        for(int i=n-1; i>=0; i--){
            while(i >= 0 && s[i] == ' ') i--;
            // first char found
            string temp = "";
            while(i >= 0 && s[i] != ' '){
                temp.push_back(s[i]);
                i--;
            }
            if(!temp.empty()){
                reverse(temp.begin(), temp.end());
                res += temp + " ";
            }
        }
        res.pop_back();
        return res;
    }
};