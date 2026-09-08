class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int ni = nums[i];
            int x = target - ni;
            if(idx[x] != 0) {
                ans.push_back(idx[x] - 1);
                ans.push_back(i);
            }
            idx[ni] = i + 1;
        }
        return ans;
    }
};
