class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for(char si: s) {
            cnt[si - 'a'] += 1;
        }
        for(char si: t) {
            cnt[si - 'a'] -= 1;
        }
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] != 0) return false;
        }
        return true;
    }
};
