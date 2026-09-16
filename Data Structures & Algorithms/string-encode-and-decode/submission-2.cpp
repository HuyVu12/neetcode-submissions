class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string si: strs) {
            ans += char(si.size() / 100);
            ans += char(si.size() % 100);
            ans += si;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int pos = 0, len = 0;
        string cur = "";
        vector<string> ans;
        while(pos < s.size()) {
            cur = "";
            len = s[pos] * 100 + s[pos + 1];
            pos += 2;

            while(len > 0) {
                cur += s[pos];
                pos += 1;
                len -= 1;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
