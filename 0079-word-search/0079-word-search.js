/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

function helper(board, word, i,j,l){
    if(l >= word.length){
        return true;
    }
    if(i>=board.length || j>=board[0].length || i<0 || j<0 || board[i][j] != word[l]){
        return false;
    }
    const temp = board[i][j];
    board[i][j] = "#";
    let found = helper(board,word,i+1,j,l+1) || helper(board, word, i, j+1, l+1) || helper(board,word,i-1,j,l+1) || helper(board, word, i, j-1, l+1);
    board[i][j] = temp;
    return found;
}
var exist = function(board, word) {
    for(let i=0;i<board.length;i++){
        for(let j=0;j<board[0].length;j++){
            if (helper(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
};