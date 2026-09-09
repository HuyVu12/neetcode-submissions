class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (char si: s) {
            if (si >= 'A' and si <= 'Z') {
                s1 += char(si - 'A' + 'a');
            }
            if ((si >= 'a' and si <= 'z') or (si >= '0' and si <= '9')) {
                s1 += si;
            }
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
