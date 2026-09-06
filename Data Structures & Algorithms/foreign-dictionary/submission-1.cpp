class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        bool char_small[256][256] = {0};
        bool is_invalid = false;
        for (int i = 0; i < n; ++i) {
            string wi = words[i];
            for(int j = i + 1; j < n; ++j) {
                string wj = words[j];
                for(int k = 0; k < wi.size(); ++k) {
                    if(k >= wj.size()) {
                        is_invalid = true;
                        break;
                    }
                    if (wi[k] == wj[k]) continue;
                    char_small[wi[k]][wj[k]] = 1;
                    if (char_small[wj[k]][wi[k]]) is_invalid = 1;
                    break; 
                }
                if(is_invalid) break;
            }
            if(is_invalid) break;
        }
        if(is_invalid) return "";
        bool is_visited[256] = {0};
        string keys = "";
        for(string si: words) {
            for(char ci: si) {
                if(is_visited[ci]) continue;
                is_visited[ci] = 1;
                keys += ci;
            }
        }
        sort(keys.begin(), keys.end());
        int cnt[256] = {0};
        for(char ki: keys) {
            for(int kj: keys) {
                if (char_small[ki][kj]) {
                    cnt[kj] += 1;
                }
            }
        }
        stack<char> st;
        string ans = "";
        for(char ki: keys) {
            if(cnt[ki] == 0) {
                st.push(ki);
            }
        }
        while(st.size()) {
            char ci = st.top();
            st.pop();
            ans += ci;
            for(char ki: keys) {
                if (char_small[ci][ki]) {
                    cnt[ki] -= 1;
                    if(cnt[ki] == 0) st.push(ki);
                }
            }
        }
        return ans;
    }
};
