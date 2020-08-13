class Solution {
private:
    bool existHelper(
        vector<vector<bool>> &visited,
        vector<vector<char>> &board,
        string &word,
        int current,
        int row,
        int column
    ) {
        if (current == word.size()) {
            return true;
        }
        if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size() || visited[row][column]) {
            return false;
        }
        visited[row][column] = true;
        bool isExist = (board[row][column] == word[current])
            && (existHelper(visited, board, word, current + 1, row, column - 1) 
                || existHelper(visited, board, word, current + 1, row, column + 1)
                || existHelper(visited, board, word, current + 1, row - 1, column)
                || existHelper(visited, board, word, current + 1, row + 1, column)
                );
        visited[row][column] = false;
        return isExist;
    }
    
public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visited(
            board.size(),
            vector<bool>(board[0].size())
        );
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (existHelper(visited, board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
