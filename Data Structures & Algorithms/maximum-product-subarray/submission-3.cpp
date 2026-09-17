class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = -11;
        long long cur = 1;
        long long pre_1 = 1;
        for(int ni: nums) {
            if(ni == 0) {
                ans = max(ans, 0LL);
                cur = 1;
                pre_1 = 1;
                continue;
            }
            cur *= ni;
            ans = max(ans, cur > 0 ? cur : cur / pre_1);
            if(cur < 0) pre_1 = pre_1 == 1 ? cur : max(cur, pre_1);
        }
        return ans;
    }
};
