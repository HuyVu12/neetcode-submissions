class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pw[61][33] = {0};
        for(int i = -30; i <= 30; ++i) {
            pw[i + 30][0] = 1;
            int j = 1;
            while (j < 33) {
                pw[i + 30][j] = pw[i + 30][j-1] * i;
                j += 1;
            }
        }
        int cnt[61] = {0};
        for(int ni : nums) {
            cnt[ni + 30] += 1;
        }
        cnt[1 + 30] = min(cnt[1 + 30], 1);
        cnt[-1 + 30] = min(cnt[-1 + 30], cnt[-1 + 30] % 2 + 2);
        cnt[0 + 30] = min(cnt[0 + 30], cnt[0 + 30] % 2 + 2);
        vector<int> ans;
        for(int ni: nums) {
            int res = 1;
            for(int i = -30; i <= 30; ++i) {
                res *= pw[i + 30][cnt[i + 30] - (i == ni)];
            }
            ans.push_back(res);
        }
        return ans;
    }
};
