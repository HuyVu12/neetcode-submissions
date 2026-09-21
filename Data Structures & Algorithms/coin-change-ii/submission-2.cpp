class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int d[5001] = {0};
        d[0] = 1;
        int i;
        for(int &ci: coins) {
            for(i = ci; i <= amount; ++i) {
                d[i] += d[i - ci];
            }
        }
        return d[amount];
    }
};
