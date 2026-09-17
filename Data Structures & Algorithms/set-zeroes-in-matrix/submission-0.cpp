class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> is_r(n, 0), is_c(m, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == 0) {
                    is_r[i] = 1;
                    is_c[j] = 1;
                }
            }
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                matrix[i][j] = is_r[i] || is_c[j] ? 0 : matrix[i][j];
    }
};
