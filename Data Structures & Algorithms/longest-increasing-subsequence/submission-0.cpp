class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int ni: nums) {
            auto it = lower_bound(ans.begin(), ans.end(), ni);
            if(it == ans.end()) ans.push_back(ni);
            else ans[int(it - ans.begin())] = ni;
        }
        return ans.size();
    }
};
