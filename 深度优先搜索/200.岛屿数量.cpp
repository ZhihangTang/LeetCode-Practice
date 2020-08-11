200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 
示例 1:

输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1
示例 2:

输入:
[
['1','1','0','0','0'],
['1','1','0','0','0'],
['0','0','1','0','0'],
['0','0','0','1','1']
]
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.size()==0) return 0;
    	int m=grid.size(),n=grid[0].size();
    	int res=0;
    	for(int i=0;i<m;++i){
    		for(int j=0;j<n;++j){
    			if(grid[i][j]==1){
    				res++;
    				dfs(grid,i,j);
    			}
    		}
    	}
    	return res;


    }
    void dfs(vector<vector<char>> &grid,int x,int y){
    	if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]=='0'){
    		return;
    	}
    	grid[x][y]='0';
    	dfs(grid,x+1,y);
    	dfs(grid,x-1,y);
    	dfs(grid,x,y+1);
    	dfs(grid,x,y-1);

    }
};