# 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
# 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
# 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
# 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
# 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。


class Solution0:
    def hasPath(self,matrix,path):
        rows=len(matrix)
        cols=len(matrix[0])
        for i in range(rows):
            for j in range(cols):
                visited=[[0 for _ in range(cols)]for _ in range(len(rows))]
                if self.dfs(matrix,i,j,path,visited):
                    return True
        return False



    def dfs(self,matrix,row,col,path,visited):
        if row<0 or row>len(matrix) or col<0 or col>len(matrix[0]) or visited[row][col]:
            return False
        if path[0]==matrix[row][col]:
            if len(path)==1:
                return True
            visited.insert(1
            return self.dfs(matrix,row+1,col,path[1:],visited) or\
                   self.dfs(matrix,row,col+1,path[1:],visited) or \
                   self.dfs(matrix,row-1,col,path[1:],visited) or \
                   self.dfs(matrix,row,col-1,path[1:],visited)




# -*- coding:utf-8 -*-
def DFS(matrix, row, col, path, visited):
    if row < 0 or row >= len(matrix) or col < 0 or col >= len(matrix[0]) or (row, col) in visited:
        return False
    if path[0] == matrix[row][col]:
        if len(path) == 1:
            return True
        return DFS(matrix, row + 1, col, path[1:], visited | {(row, col)}) or \
               DFS(matrix, row - 1, col, path[1:], visited | {(row, col)}) or \
               DFS(matrix, row, col - 1, path[1:], visited | {(row, col)}) or \
               DFS(matrix, row, col + 1, path[1:], visited | {(row, col)})

class Solution:
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        array = list(matrix)
        array = [array[i * cols:(i + 1) * cols] for i in range(rows)]
        for i in range(rows):
            for j in range(cols):
                visited = set()
                if DFS(array, i, j, list(path), visited):
                    return True
        return False

print(Solution().hasPath("ABCESFCSADEE", 3, 4, "BCCED"))
print(Solution().hasPath("ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS", 5, 8, "SLHECCEIDEJFGGFIE"))
print(Solution().hasPath("AAAAAAAAAAAA", 3, 4, "AAAAAAAAAAAA"))

matrix=["ABCESFCSADEE"]

'''
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
'''