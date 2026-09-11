class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> d(nums.size(), 0);
        if(nums.size() <= 2) {
            return *max_element(nums.begin(), nums.end());    
        }
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            d[i] = max(d[i-1], d[i-2] + nums[i]);
        }
        return *d.rbegin();
    }
};
