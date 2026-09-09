class Solution {
public:
    vector<int> countBits(int n) {
        vector<bool> ok(n + 1, false);
        vector<int> ans(n + 1, 0);
        ok[0] = 1;
        for(int i = 1; i <= n; ++i) {
            if(ok[i]) continue;
            int j = i;
            while (j > 0) {
                ans[i] += j % 2;
                j /= 2;
            }
            j = i;
            ok[i] = true;
            j *= 2;
            while (j <= n) {
                ans[j] = ans[i];
                ok[j] = 1;
                j *= 2;
            }
        }
        return ans;
    }
};
