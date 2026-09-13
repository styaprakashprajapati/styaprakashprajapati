class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // Saare characters mil gaye
        if (index == word.size()) {
            return true;
        }

        // Boundary check
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Character match nahi hua
        if (board[row][col] != word[index]) {
            return false;
        }

        // Current character save karo
        char original = board[row][col];

        // Visited mark
        board[row][col] = '#';

        // 4 directions
        bool found =
            dfs(board, word, row - 1, col, index + 1) || // up
            dfs(board, word, row + 1, col, index + 1) || // down
            dfs(board, word, row, col - 1, index + 1) || // left
            dfs(board, word, row, col + 1, index + 1);    // right

        // Backtracking
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (board[row][col] == word[0]) {

                    if (dfs(board, word, row, col, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};