class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<int>> bucket(3, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && ++bucket[0][board[i][j] - '1'] > 1) return false;
                if (board[j][i] != '.' && ++bucket[1][board[j][i] - '1'] > 1) return false;
                int v = j%3 + 3*(i%3);
                int h = j/3 + 3*(i/3);
                if (board[v][h] != '.' && ++bucket[2][board[v][h] - '1'] > 1) return false;
            }
            bucket = vector<vector<int>>(3, vector<int>(9, 0));
        }
    }
};
