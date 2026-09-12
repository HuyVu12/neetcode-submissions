class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int d[1002][1002] = {0};
        text1 = '#' + text1;
        text2 = '#' + text2;
        for(int i = 1; i < text1.size(); ++i) {
            for(int j = 1; j < text2.size(); ++j) {
                if(text1[i] == text2[j]) d[i][j] = d[i-1][j-1] + 1;
                else d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
        return d[text1.size()-1][text2.size()-1];
    }
};
