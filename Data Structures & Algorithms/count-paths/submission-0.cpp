class Solution {
public:
    int uniquePaths(int m, int n) {
        int d[101][101] = {0};
        d[1][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j)
                d[i][j] += d[i-1][j] + d[i][j-1];
        }
        return d[m][n];
    }
};
