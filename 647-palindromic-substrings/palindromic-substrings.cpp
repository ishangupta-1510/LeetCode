class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        // Odd length palindromes
        for (int i = 0; i < n; i++) {
            int right = i, left = i;
            int count = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            ans += count;
        }

        // Even length palindromes
        for (int i = 0; i < n - 1; i++) {
            int right = i + 1, left = i;
            int count = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            ans += count;
        }

        return ans;
    }
};
