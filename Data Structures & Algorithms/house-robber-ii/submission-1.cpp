class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        int d[101][2] = {0};
        int n = nums.size();
        d[0][1] = nums[0];
        d[1][1] = d[0][1];
        d[1][0] = nums[1];
        for(int i = 2; i < n; ++i) {
            d[i][0] = max(d[i-1][0], d[i-2][0] + nums[i]);
            if(i == n - 1) {
                d[i][1] = d[i-1][1];
            }
            else d[i][1] = max(d[i-1][1], d[i-2][1] + nums[i]);
        }
        return max(d[n-1][0], d[n-1][1]);
    }
};
