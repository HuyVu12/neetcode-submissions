class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int &ni: nums) sum += ni;
        return (n + 1) * n / 2 - sum;
    }
};
