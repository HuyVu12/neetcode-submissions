class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> T;
        for(string si: wordDict) {
            T.insert(si);
        }
        s= '#' + s;
        bool ok[201] = {0};
        ok[0] = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(ok[i-1]) {
                string cur = "";
                for(int j = i; j < s.size(); ++j) {
                    cur += s[j];
                    if(T.find(cur) != T.end()) ok[j] = 1;
                }
            }
        }
        return ok[s.size()-1];
    }
};
