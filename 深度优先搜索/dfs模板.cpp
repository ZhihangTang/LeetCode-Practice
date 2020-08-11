//深度优先搜索dfs
class Solution {
    public void dfs(vector<vector<char>> source,int x,int y){//遍历的对象一般为树节点，图节点，二维数组等，这里以二维数组为例
        if (终止条件 || 目标节点已访问) {return;}//符合终止条件或已访问过该节点，退出
        source[x][y] = '0';//对已访问的节点进行标记，可以直接在原节点上修改，也可以使用一个visited数组进行标记
        ......//此处为对目标节点的操作，如赋值，读取数等

        dfs(source,x+1,y);//递归搜索下一次遍历节点
        dfs(source,x-1,y);
        ......
    }

    public int result(vector<vector<char>> source){//若需要返回结果，在一个新的类中实现
        int res = 0;
        ......//初始化
        for (int i = 0;i < source.length;i++){
            for (int j = 0;j < source[0].length;j++){
                if (符合dfs开始节点条件) {
                    res++;//对需要返回的结果进行赋值，累加等操作
                    dfs(source,i,j);//开始dfs
                }
            }
        }
        return res;
    }
}


class Solution {
    void dfs(char[][] grid, int r, int c) {
        int nr = grid.length;
        int nc = grid[0].length;

        if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int nr = grid.length;
        int nc = grid[0].length;
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
}
