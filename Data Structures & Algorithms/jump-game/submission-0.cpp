class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        int i = -1;
        for(int ni : nums) {
            i += 1;
            if(far < i) return false;
            far = max(far, i + ni);
        }
        return far >= (nums.size() - 1);
    }
};
