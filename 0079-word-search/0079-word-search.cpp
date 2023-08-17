class Solution {
public:
    bool wordsearch(vector<vector<char>>& board, const string& word, int i, int j, int k, int n, int m) {
        if (k >= word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k]) {
            return false;
        }
        char temp = board[i][j]; // Store the current character
        board[i][j] = '#'; // Mark the cell as visited
        bool found = wordsearch(board, word, i + 1, j, k + 1, n, m) ||
                     wordsearch(board, word, i, j + 1, k + 1, n, m) ||
                     wordsearch(board, word, i - 1, j, k + 1, n, m) ||
                     wordsearch(board, word, i, j - 1, k + 1, n, m);
        board[i][j] = temp; // Restore the cell to its original state
        return found;
    }
    
    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && wordsearch(board, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }
        return false;
    }
};
