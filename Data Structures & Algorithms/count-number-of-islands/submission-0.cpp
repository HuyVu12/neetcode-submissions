class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ax[4] = {-1, 1, 0, 0};
        int ay[4] = {0, 0, -1, 1};
        bool is_visited[101][101] = {0};
        stack<pair<int, int>> st;
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(is_visited[i][j] or grid[i][j] == '0') continue;
                if(grid[i][j] == '1') {
                    ans += 1;
                    st.push({i, j});
                    while(st.size()) {
                        int x = st.top().first, y = st.top().second;
                        st.pop();
                        if(is_visited[x][y] or grid[x][y] == '0') continue;
                        is_visited[x][y] = true;
                        for(int k = 0; k < 4; ++k) {
                            int cx = x + ax[k], cy = y + ay[k];
                            if(cx < 0 or cx >= n or cy < 0 or cy >= m or is_visited[cx][cy] or grid[cx][cy] == '0') continue;
                            st.push({cx, cy});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
