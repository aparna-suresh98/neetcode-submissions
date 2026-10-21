class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        int R = board.size();
        int C = board[0].size();

        if(i < 0 || j<0 || i>=R || j>=C) return;
        if(board[i][j] == 'S') return;
        if(board[i][j] != 'O') return;
        board[i][j] = 'S';

        if(i+1 < R && board[i+1][j] == 'O') dfs(i+1,j,board);
        if(i-1 >= 0 && board[i-1][j] == 'O') dfs(i-1,j,board);
        if(j+1 < C && board[i][j+1] == 'O') dfs(i,j+1,board);
        if(j-1 >= 0 && board[i][j-1] == 'O') dfs(i,j-1,board);

    }
    void solve(vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();

        for(int i=0;i<R;i++){
            dfs(i,0,board);
            dfs(i,C-1,board);
        }

        for(int i=0;i<C;i++){
            dfs(0,i,board);
            dfs(R-1,i,board);
        }

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};
