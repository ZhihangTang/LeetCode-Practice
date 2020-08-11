// 542. 01 矩阵
// 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

// 两个相邻元素间的距离为 1 。

// 示例 1:
// 输入:

// 0 0 0
// 0 1 0
// 0 0 0
// 输出:

// 0 0 0
// 0 1 0
// 0 0 0

// 示例 2:
// 输入:

// 0 0 0
// 0 1 0
// 1 1 1
// 输出:

// 0 0 0
// 0 1 0
// 1 2 1

// 注意:

// 给定矩阵的元素个数不超过 10000。
// 给定矩阵中至少有一个元素是 0。
// 矩阵中的元素只在四个方向上相邻: 上、下、左、右。


// -------------------------深度优先搜索---------------------------------
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return matrix;
    	vector<vector<int>> res;
    	for(int i=0;i<matrix.size();++i){
    		for(int j=0;j<matrix[i].size();++j)
    			if(matrix[i][j]!=0){
    				dfs(matrix,i,j,res);
    			}
    	}
    }
    void dfs(vector<vector<int>>& matrix,int i,int j,int depth,vector<vector<int>>& res){
    	if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size()||matrix[i][j]==0){
    		return ;
    	}
    	if(depth>=res[i][j]) return;
        int x=i,y=j;
        m[x][y]=depth;
    	dfs(matrix,i+1,j,depth+1,res);
    	dfs(matrix,i-1,j,depth+1,res);
    	dfs(matrix,i,j+1,depth+1,res);
    	dfs(matrix,i,j-1,depth+1,res);

    }
};



class Solution {
    int [][]dirs={{-1,0},{1,0},{0,-1},{0,1}};
    
    int m;
    int n;
    public int[][] updateMatrix(int[][] matrix) {
        m=matrix.length;
        if(m==0)
            return matrix;
        n=matrix[0].length;
        
        /* 将周围没有0，且值为1的位置 设置为一个极大值*/
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1&&!hasNeighbors0(matrix,i,j)){
                    matrix[i][j]=Integer.MAX_VALUE;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    dfs(matrix,i,j);
                }
            }
        }
        return matrix;
    }
    /* 判断周围四个方向是否有0 */
     boolean hasNeighbors0(int [][]matrix,int x,int y){ 
         
         for(int []dir:dirs){
             int new_x=x+dir[0];
             int new_y=y+dir[1];
             if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&matrix[new_x][new_y]==0)              return true;
         }
         return false;
     }

    void dfs(int [][]matrix,int x,int y){
        for(int []dir:dirs){
            int new_x=x+dir[0];
            int new_y=y+dir[1];
            if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&matrix[new_x][new_y]>matrix[x][y]+1){
                matrix[new_x][new_y]=matrix[x][y]+1;
                dfs(matrix,new_x,new_y);
            }
            
        }
    }
}



// ---------------------------dp--------------------------------------

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0)
                    dist[i][j]=0;
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i>=1){
                    dist[i][j]=min(dist[i][j],dist[i-1][j]+1);
                }
                if(j>=1){
                    dist[i][j]=min(dist[i][j],dist[i][j-1]+1);
                }
            }
        }
        for(int i=m-1;i>=0;--i){
            for(int j=n;j>=0;--j){
                if(i+1<m){
                    dist[i][j]=min(dist[i][j],dist[i+1][j]+1);
                }
                if(j+1<n){
                    dist[i][j]=min(dist[i][j],dist[i][j+1]+1);
                }
            }
        }
        return dist;

    }
}


// ----------------------------广度优先搜索-----------------------------------
// 1、遍历所有点，数值为零压入队列，进行广度优先搜索，非零点被赋值为最大值。
// 2、零点的广度优先搜索：以每个零点为根节点进行广度优先搜索，如果新节点值比旧节点值大，
// 则matrix[nrow][ncol]=matrix[row][col]+1，并压入新节点的下标。
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    matrix[i][j]=INT_MAX;
                }
            }
        }
        while(!q.empty())
        {
            auto value = q.front();
            q.pop();
            int row = value.first;
            int col = value.second;
            int movex[] = {0,0,-1,1};
            int movey[] = {1,-1,0,0};
            for(int i=0;i<4;i++)
            {
                int nrow = row + movex[i];
                int ncol = col + movey[i];
                if(nrow>=0&&nrow<r&&ncol>=0&&ncol<c&&matrix[nrow][ncol]>matrix[row][col])
                {
                    matrix[nrow][ncol]=matrix[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return matrix;
    }
};
