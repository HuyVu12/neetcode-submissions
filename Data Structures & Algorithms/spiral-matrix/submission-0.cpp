class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int ty = 0;
        int x = 0, y = 0;
        while (ans.size() < n * m) {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -136;
            if(ty == 0 or ty == 2) {
                y += ty == 0 ? 1 : -1;
                if(y >= m or y < 0 or matrix[x][y] == -136) {
                    y -= ty == 0 ? 1 : -1;
                    x += ty == 0 ? 1 : -1;
                    ty = (ty + 1) % 4;
                }
            }
            else if(ty == 1 or ty == 3) {
                x += ty == 1 ? 1 : -1;
                if(x >= n or x < 0 or matrix[x][y] == -136) {
                    x -= ty == 1 ? 1 : -1;
                    y += ty == 1 ? -1 : 1;
                    ty = (ty + 1) % 4;
                }
            }
        }
        return ans;
    }
};
