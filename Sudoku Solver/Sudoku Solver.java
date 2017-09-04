class Solution {
    public void solveSudoku(char[][] board) {
        solveHelper(board, 0);
    }

    public boolean solveHelper(char[][] board, int n) {
        if (n == 81) {
            return true;
        }
        int row = n / 9, col = n % 9;
        if (board[row][col] == '.') {
            for (char i = '1'; i <= '9'; i++) {
                board[row][col] = i;
                if (isValid(board, row, col)) {
                    if (solveHelper(board, n + 1)) return true;
                }
            }
            board[row][col] = '.';
            return false;
        }
        return solveHelper(board, n + 1);
    }

    public boolean isValid(char[][] board, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == board[row][col] && i != col) {
                return false;
            }
            if (board[i][col] == board[row][col] && i != row) {
                return false;
            }
        }
        int rowBegin = (row / 3) * 3, colBegin = (col / 3) * 3;
        for (int i = rowBegin; i < rowBegin + 3; i++) {
            for (int j = colBegin; j < colBegin + 3; j++) {
                if (board[i][j] == board[row][col] && (i != row || j != col)) {
                    return false;
                }
            }
        }
        return true;
    }
}