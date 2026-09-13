class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int id_l = 0;
        int id_r = n - 1;
        int max_v = *max_element(heights.begin(), heights.end());
        for(int i = 1; i <= max_v; ++i) {
            while(id_l < id_r and heights[id_l] < i) id_l += 1;
            while(id_l < id_r and heights[id_r] < i) id_r -= 1;
            if(id_l >= id_r) break;
            ans = max(ans, i * (id_r - id_l));
        }
        return ans;
    }
};
