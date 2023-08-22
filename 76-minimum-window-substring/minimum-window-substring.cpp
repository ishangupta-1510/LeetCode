class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }
        int start = 0, st = 0, e = 0;
        vector<int> freq1(128, 0);
        int requiredChars = t.length(), minWindowSize = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (freq[s[i]]) {
                if (freq1[s[i]] < freq[s[i]]) {
                    requiredChars--;
                }
                freq1[s[i]]++;

                while (requiredChars == 0) {
                    if (i - start + 1 < minWindowSize) {
                        minWindowSize = i - start + 1;
                        st = start;
                        e = i;
                    }

                    if (freq[s[start]]) {
                        freq1[s[start]]--;
                        if (freq1[s[start]] < freq[s[start]]) {
                            requiredChars++;
                        }
                    }
                    start++;
                }
            }
        }

        if (minWindowSize == INT_MAX) {
            return "";
        }

        return s.substr(st, minWindowSize);
    }
};
