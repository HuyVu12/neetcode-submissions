class Solution:
    def minWindow(self, s: str, t: str) -> str:
        d = {}
        for si in s:
            d[si] = 0
        for si in t:
            d[si] = 0
        for si in t:
            d[si] += 1
        miss_cnt = len(set(t))
        L = 0
        R = 0
        ans = ""
        for i in range(len(s)):
            si = s[i]
            d[si] -= 1
            if d[si] == 0: miss_cnt -= 1
            if miss_cnt == 0:
                ans = s[: i + 1]
                R = i
                break
        if miss_cnt != 0: return ""
        while R < len(s) and L < len(s):
            d[s[L]] += 1
            if d[s[L]] > 0:
                miss_cnt += 1
            L += 1
            while R < (len(s) - 1) and miss_cnt > 0:
                R += 1
                d[s[R]] -= 1
                if d[s[R]] == 0:
                    miss_cnt -= 1
            if miss_cnt == 0 and (R - L + 1) < len(ans):
                ans = s[L: R + 1]
        return ans
