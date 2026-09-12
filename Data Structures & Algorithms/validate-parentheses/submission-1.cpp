class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char si: s) {
            if(si == ')') {
                if(st.size() and st.top() == '(') st.pop();
                else return false;
            }
            else if(si == ']') {
                if(st.size() and st.top() == '[') st.pop();
                else return false;
            }
            else if(si == '}') {
                if(st.size() and st.top() == '{') st.pop();
                else return false;
            }
            else {
                st.push(si);
            }
        }
        return st.empty();
    }
};
