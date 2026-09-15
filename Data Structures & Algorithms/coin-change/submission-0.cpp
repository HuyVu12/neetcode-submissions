class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> d(10001, 99999999);
        d[0] = 0;
        for(int& ci: coins) {
            for(int i = ci; i <= amount; ++i) {
                d[i] = min(d[i - ci] + 1, d[i]);
            }
        }
        return d[amount] != 99999999 ? d[amount] : -1;
    }
};
