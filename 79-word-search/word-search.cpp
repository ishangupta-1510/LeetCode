class Solution {
public:
    bool wordsearch(vector<vector<char>>& board, string& word,int i,int j,int k,int& n,int& m){
        if(k>=word.length()){
            return true;
        }
        if(i >= n or j>=m or i<0 or j<0 or board[i][j] != word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool  found = wordsearch(board,word,i+1,j,k+1,n,m) or wordsearch(board,word,i,j+1,k+1,n,m) or wordsearch(board,word,i-1,j,k+1,n,m) or wordsearch(board,word,i,j-1,k+1,n,m);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] and wordsearch(board,word,i,j,0,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};