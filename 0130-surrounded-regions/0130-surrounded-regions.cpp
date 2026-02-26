class Solution {
public:
    int R,C;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i == R || j < 0 || j == C || board[i][j] != 'O') return;

        board[i][j] = 'A';

        dfs(board, i+1, j);
        dfs(board, i, j+1);
        dfs(board, i-1, j);
        dfs(board, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        R = board.size(), C = board[0].size();

        for(int i=0; i<R; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][C-1] == 'O') dfs(board, i, C-1);
        }
        for(int j=0; j<C; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[R-1][j] == 'O') dfs(board, R-1, j);
        }

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }

};