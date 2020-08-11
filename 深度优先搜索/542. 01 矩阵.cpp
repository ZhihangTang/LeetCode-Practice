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



这道题和前几天的打卡题 「1162.地图分析」 一毛一样！那道题是可以理解为需要找到每个 0 最近的 1，而今天这道题是找每个 1 最近的 0。

这里斗胆模仿一下前额叶 dalao 的文风就是 「吃🐳！秒懂多源 BFS 看上面这 1 篇就够了！还送 D 版 pdf！👏」

一、广度优先搜索
思路：
对于 「Tree 的 BFS」 （典型的「单源 BFS」） 大家都已经轻车熟路了：

首先把 root 节点入队，再一层一层无脑遍历就行了。
对于 「图 的 BFS」 （「多源 BFS」） 做法其实也是一样滴～，与 「Tree 的 BFS」的区别注意以下两条就 ok 辣～

Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；
Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过哦！并且为了防止某个节点多次入队，需要在其入队之前就将其设置成已访问！【 看见很多人说自己的 BFS 超时了，坑就在这里哈哈哈
做法：
根据上述思路，本题怎么做就很简单了：

首先把每个源点 0 入队，然后从各个 0 同时开始一圈一圈的向 1 扩散（每个 1 都是被离它最近的 0 扩散到的 ），扩散的时候可以设置 int[][] dist 来记录距离（即扩散的层次）并同时标志是否访问过。对于本题是可以直接修改原数组 int[][] matrix 来记录距离和标志是否访问的，这里要注意先把 matrix 数组中 1 的位置设置成 -1 （设成Integer.MAX_VALUE啦，m * n啦，10000啦都行，只要是个无效的距离值来标志这个位置的 1 没有被访问过就行辣~）
复杂度分析：

每个点入队出队一次，所以时间复杂度：O(n * m)O(n∗m)
虽然我们是直接原地修改的原输入数组来存储结果，但最差的情况下即全都是 0 时，需要把 m * n 个 0 都入队，因此空间复杂度是 O(n * m)
cpp

class Solution
{
public:
     int updateMatrix(vector<vector<int>> matrix){
        queue<vector<int>> q;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
                else{
                    matrix[i][j]=-1;
                }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            vector<int> point=q.front();
            q.pop();
            int x=point[0],y=point[1];
            for(int i=0;i<4;++i){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&yy>=0&&xx<m&&yy<n&&matrix[xx][yy]==-1){
                    matrix[xx][yy]=matrix[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
        return matrix;
     }
    
};
另一种 BFS 思路：
本题还有一种 BFS 的做法，就是先找出在 00 边上的所有的 11，然后把这些 11 放到队列里，后续BFS的时候就只关心 11 的值。
直接看注释叭～～

java

class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        // 首先将 0 边上的 1 入队
        int[] dx = new int[] {-1, 1, 0, 0};
        int[] dy = new int[] {0, 0, -1, 1};
        Queue<int[]> queue = new LinkedList<>();
        int m = matrix.length, n = matrix[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < m && y >= 0 && y < n 
                                && matrix[x][y] == 1 && res[x][y] == 0) {
                            // 这是在 0 边上的1。需要加上 res[x][y] == 0 的判断防止重复入队
                            res[x][y] = 1;
                            queue.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }

        while (!queue.isEmpty()) {
            int[] point = queue.poll();
            int x = point[0], y = point[1];
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n 
                        && matrix[newX][newY] == 1 && res[newX][newY] == 0) {
                    res[newX][newY] = res[x][y] + 1;
                    queue.offer(new int[] {newX, newY});
                }
            }
        }

        return res;
    }
}
二、动态规划
对于任一点 (i, j)(i,j)，距离 00 的距离为：

f(i, j) = \begin{cases} 1 + min(f(i-1, j), f(i, j-1), f(i+1, j), f(i, j+1)) & \text{if matrix[i][j] == 1} \\ 0 & \text{if matrix[i][j] == 0} \end{cases}
f(i,j)={ 
1+min(f(i−1,j),f(i,j−1),f(i+1,j),f(i,j+1))
0
​   
  
if matrix[i][j] == 1
if matrix[i][j] == 0
​   
 

因此我们用 dp[i][j]dp[i][j] 来表示该位置距离最近的 00 的距离。
我们发现 dp[i][j]dp[i][j] 是由其上下左右四个状态来决定，无法从一个方向开始递推！

于是我们尝试将问题分解：

距离 (i, j)(i,j) 最近的 00 的位置，是在其 「左上，右上，左下，右下」4个方向之一；
因此我们分别从四个角开始递推，就分别得到了位于「左上方、右上方、左下方、右下方」距离 (i, j)(i,j) 的最近的 00 的距离，取 minmin 即可；
通过上两步思路，我们可以很容易的写出 44 个双重 forfor 循环，动态规划的解法写到这一步其实已经完全 OKOK 了；
如果第三步还不满足的话，从四个角开始的 44 次递推，其实还可以优化成从任一组对角开始的 22 次递推，比如只写从左上角、右下角开始递推就行了，为啥这样可以呢？且听我不负责任的草率论证 = = #
首先从左上角开始递推 dp[i][j]dp[i][j] 是由其 「左方」和 「左上方」的最优子状态决定的；
然后从右下角开始递推 dp[i][j]dp[i][j] 是由其 「右方」和 「右下方」的最优子状态决定的；
看起来第一次递推的时候，把「右上方」的最优子状态给漏掉了，其实不是的，因为第二次递推的时候「右方」的状态在第一次递推时已经包含了「右上方」的最优子状态了；
看起来第二次递推的时候，把「左下方」的最优子状态给漏掉了，其实不是的，因为第二次递推的时候「右下方」的状态在第一次递推时已经包含了「左下方」的最优子状态了。
java

class Solution {
  public int[][] updateMatrix(int[][] matrix) {
    int m = matrix.length, n = matrix[0].length;
    int[][] dp = new int[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = matrix[i][j] == 0 ? 0 : 10000;
      }
    }

    // 从左上角开始
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i - 1 >= 0) {
          dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
        }
        if (j - 1 >= 0) {
          dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
        }
      }
    }
    // 从右下角开始
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i + 1 < m) {
          dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + 1);
        }
        if (j + 1 < n) {
          dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + 1);
        }
      }
    }
    return dp;
  }
}
下一篇：套路大解密：搞懂题目考察什么，剩下的任务就是套模板！

作者：sweetiee
链接：https://leetcode-cn.com/problems/01-matrix/solution/2chong-bfs-xiang-jie-dp-bi-xu-miao-dong-by-sweetie/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


