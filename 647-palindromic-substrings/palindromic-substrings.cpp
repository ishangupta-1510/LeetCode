class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
                ans++;
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; j++) {
                ans++;
            }
        }
        return ans;
    }
};
