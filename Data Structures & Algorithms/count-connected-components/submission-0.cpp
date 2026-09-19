class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> a[2001];
        for(auto it: edges) {
            a[it[0]].push_back(it[1]);
            a[it[1]].push_back(it[0]);
        }
        bool isVisited[2001] = {0};
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(isVisited[i]) continue;
            stack<int> st;
            st.push(i);
            ans += 1;
            while(st.size()) {
                int u = st.top(); st.pop();
                if(isVisited[u]) continue;
                isVisited[u] = 1;
                for(int v: a[u]) {
                    if(!isVisited[v])
                        st.push(v);
                }
            }
        }
        return ans;
    }
};
