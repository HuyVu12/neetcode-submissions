class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> a[2001];
        for(auto it : edges) {
            a[it[0]].push_back(it[1]);
            a[it[1]].push_back(it[0]);
        }
        stack<int> st;
        bool ok[2001] = {0};
        st.push(0);
        while(st.size()) {
            int u = st.top(); st.pop();
            if(ok[u]) continue;
            ok[u] = 1;
            for(int &v: a[u]) {
                if(ok[v]) continue;
                st.push(v);
            }
        }
        for(int i = 1; i < n; ++i) if(!ok[i]) return false;
        return true;
    }
};
