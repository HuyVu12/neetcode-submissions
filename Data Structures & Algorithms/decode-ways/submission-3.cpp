class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int d[101] = {0};
        d[0] = 1;
        if((s[0] - '0') * 10 + s[1] -'0' <= 26) {
            d[1] = 1;
        }
        if(s[1] != '0') {
            d[1] += d[0];
        }
        for(int i = 2; i < s.size(); ++i) {
            if(s[i] != '0') {
                d[i] += d[i-1];
            }
            if((s[i-1] - '0') *10 + s[i] - '0' <= 26 and s[i-1] != '0') {
                d[i] += d[i-2];
            }
        }
        return d[s.size()-1];
    }
};
