class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<int> exist;
        set<pair<int, int>> used;
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int a = nums[i], b = nums[j];
                if(a > b) swap(a, b);
                int c = -(a + b);
                if(exist.find(c) != exist.end()) {
                    int mi = min({a, b, c});
                    int ma = max({a, b, c});
                    if(used.find({mi, ma}) == used.end()) {
                        used.insert({mi, ma});
                        ans.push_back({a, b, c});
                    }
                }
            }
            exist.insert(nums[i]);
        }
        return ans;
    }
};
