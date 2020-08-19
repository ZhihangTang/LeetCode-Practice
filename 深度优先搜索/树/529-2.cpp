
class Solution{
public:
    int countM(vector<vector<char>>& board,int xx,int yy){
        int count=0;
        int i,j;
        for(i=xx-1;i<=xx+1;++i){
            for(j=yy-1;j<=yy+1;++j){
                if((i==xx&&j==yy)||i<0||j<0||i>=board.size()||j>=board[0].size()){
                    continue;
                }
                else{
                    if(board[i][j]=='M'){
                        count++;
                    }
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        int i,j;
        if(board[x][y]=='E'){
            if(countM(board,x,y)==0){
                board[x][y]='B';
            }
            else{
                board[x][y]=countM(board,x,y)+'0';
                return;
            }
            for(i=x-1;i<=x+1;++i){
                for(j=y-1;j<=y+1;++j){
                    if((i==x&&j==y)||i<0||j<0||i>=board.size()||j>=board[0].size()){
                    continue;
                }
                else{
                    dfs(board,i,j);
                    }
                }
            }
        }

        else if(board[x][y]=='M'){
                board[x][y]='X';
        }   
        
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board,click[0],click[1]);
        return board;
    }
};