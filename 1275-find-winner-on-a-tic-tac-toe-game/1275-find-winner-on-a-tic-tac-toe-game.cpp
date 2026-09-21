class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<vector<char>> board(3, vector<char>(3, ' '));

        // Moves ko board par place karo
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];

            if (i % 2 == 0) {
                board[row][col] = 'A';
            } else {
                board[row][col] = 'B';
            }
        }

        // 8 winning lines check karne ke liye
        for (int i = 0; i < 3; i++) {
            
            // Rows
            if (board[i][0] != ' ' &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2]) {
                
                string winner(1, board[i][0]);
                return winner;
            }

            // Columns
            if (board[0][i] != ' ' &&
                board[0][i] == board[1][i] &&
                board[1][i] == board[2][i]) {
                
                string winner(1, board[0][i]);
                return winner;
            }
        }

        // Main diagonal
        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {
            
            string winner(1, board[0][0]);
            return winner;
        }

        // Other diagonal
        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {
            
            string winner(1, board[0][2]);
            return winner;
        }

        // Agar board abhi full nahi hua
        if (moves.size() < 9) {
            return "Pending";
        }

        // Board full hai
        return "Draw";
    }
};