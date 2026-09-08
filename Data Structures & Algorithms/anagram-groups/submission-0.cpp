class Solution {
    const int MOD = (int)(1e9 + 7);
    const int base = (int)(256);
public:
    int hash_s(string s) {
        int cnt[26] = {0};
        for(char si: s) {
            cnt[si - 'a'] += 1;
        }
        int cur = 0;
        for(int i = 0; i < 26; ++i) {
            cur = (1LL * cur * 256 + cnt[i]) % MOD;
        }
        return cur;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int, int> idx;
        for(string si: strs) {
            int code = hash_s(si);
            if(idx[code] == 0) {
                vector<string> res;
                ans.push_back(res);
                idx[code] = ans.size();
            }
            ans[idx[code]-1].push_back(si);
        }
        return ans;
    }
};
