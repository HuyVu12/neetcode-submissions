class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1) {
                cnt += 1;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        if (nums.size() == 0) return 0;
        return ans;
    }
};
