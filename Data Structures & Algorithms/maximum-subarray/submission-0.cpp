class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9+7;
        int cur = 0, min_pre = 0;
        for(int ni: nums) {
            cur += ni;
            ans = max(ans, cur - min_pre);
            min_pre = min(min_pre, cur);
        }
        return ans;
    }
};
