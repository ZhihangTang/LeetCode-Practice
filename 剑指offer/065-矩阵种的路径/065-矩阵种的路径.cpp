
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL){
            return false;
        }
        bool* visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        int pathLength = 0;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)){
                    delete[] visited;
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }
private:
    bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited){
        if(str[pathLength] == '\0'){
            return true;
        }
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col]){
            ++pathLength;
            visited[row*cols+col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);
            if(!hasPath){
                --pathLength;
                visited[row*cols+col] = false;
            }
        }
        return hasPath;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0) return false;
        int m=board.size(),n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        


    }

// 回溯法
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;

    }
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int k){
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[k]){
            return false;
        }
        if(k==word.size()-1) return true;
        char cur=board[i][j];
        board[i][j]='/';
        bool res=dfs(board,word,i+1,j,k+1)||
                 dfs(board,word,i,j+1,k+1)||
                 dfs(board,word,i-1,j,k+1)||
                 dfs(board,word,i,j-1,k+1);
        //撤回选择
        board[i][j]=cur;
        return res;
        
        
    }
};