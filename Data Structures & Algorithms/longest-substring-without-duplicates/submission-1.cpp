class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        bool ok[256] = {0};
        int ans = 0;
        for(char si: s) {
            int c = si;
            while(ok[c] == 1) {
                ok[s[l]] = 0;
                l += 1;
            }
            ok[c] = 1;
            ans = max(ans, r - l + 1);
            r += 1;
        }
        return ans;
    }
};
