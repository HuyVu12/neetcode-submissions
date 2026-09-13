class Solution {
public:
    int calc(const vector<int> &cnt) {
        int sum = 0, max_v = 0;
        for(int ci: cnt) {
            sum += ci; max_v = max(max_v, ci);
        }
        return sum - max_v;
    }
    int characterReplacement(string s, int k) {
        int l = 0, r = -1, ans = 0;
        vector<int> cnt(26, 0);
        for(char si: s) {
            r += 1;
            cnt[si - 'A'] += 1;
            while(calc(cnt) > k) {
                cnt[s[l] - 'A'] -= 1; 
                l += 1;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
