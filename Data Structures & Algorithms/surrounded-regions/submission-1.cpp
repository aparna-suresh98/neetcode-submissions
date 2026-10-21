class Solution {
public:
    void dfs(int i,int j,int R,int C,vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i>=R || j>=C || grid[i][j] != 'O') return;
        grid[i][j] = 'S';
        dfs(i+1,j,R,C,grid);
        dfs(i-1,j,R,C,grid);
        dfs(i,j+1,R,C,grid);
        dfs(i,j-1,R,C,grid);
    }
    void solve(vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();

        for(int i=0;i<R;i++){
            dfs(i,0,R,C,board);
            dfs(i,C-1,R,C,board);
        }

        for(int i=0;i<C;i++){
            dfs(0,i,R,C,board);
            dfs(R-1,i,R,C,board);
        }

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
