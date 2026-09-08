class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[2001] = {0};
        vector<int> keys;
        for(int ni: nums) {
            if(cnt[ni + 1000] == 0) keys.push_back(ni);
            cnt[ni + 1000] += 1;
        }
        sort(keys.begin(), keys.end(), [&](int a1, int a2){
            return (cnt[a1 + 1000] > cnt[a2 + 1000]);
        });
        vector<int> ans;
        for(int i = 0; i < k; ++i) ans.push_back(keys[i]);
        return ans;
    }
};
