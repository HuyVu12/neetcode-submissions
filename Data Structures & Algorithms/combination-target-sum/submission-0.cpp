class Solution {
public:
    void trau(const vector<int>& nums, const int &target, int pos, int cur_val, vector<int> &cur_list, vector<vector<int>> &ans) {
        if(cur_val == target) {
            ans.push_back(cur_list);
            return;
        }
        if(cur_val > target) return;
        if(pos >= nums.size()) return;
        cur_val += nums[pos];
        cur_list.push_back(nums[pos]);
        trau(nums, target, pos, cur_val, cur_list, ans);
        cur_val -= nums[pos];
        cur_list.pop_back();
        trau(nums, target, pos + 1, cur_val, cur_list, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur_list;
        trau(nums, target, 0, 0, cur_list, ans);
        return ans;
    }
};
