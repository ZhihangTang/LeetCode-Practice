// dfs、bfs递归和非递归解法

// https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                bool IsEdge=false;
                if(i==0||j==0||i==m-1||j==n-1)IsEdge=true;
                if(IsEdge && board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }

            }
        }

    }
    void dfs(vector<vector<char>>&board,int i,int j){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]=='X'|| board[i][j] == '#'){
            return;
        }
        board[i][j]='#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
};
