// BFS
class Solution{
public:
	int movingCount(int m,int n,int k){
		vector<vector<int>> grid(m,vector<int>(n,0));
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				grid[i][j]=getN(i,j);
			}
		}
		vector<vector<int>> visited(m,vector<int>(n,0));
		return BFS(grid,visited,0,0,k);
	}

	int BFS(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j,int tresh){
		if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]==1||grid[i][j]>tresh){
			return 0;
		}
		int res=1;
		visited[i][j]=1;
		res+=BFS(grid,visited,i+1,j,tresh);
		res+=BFS(grid,visited,i-1,j,tresh);
		res+=BFS(grid,visited,i,j+1,tresh);
		res+=BFS(grid,visited,i,j-1,tresh);
		return res;
	}
	int getN(int i,int j){
		int res=0;
		while(i){
			res+=i%10;
			i/=10;
		}
		while(j){
			res+=j%10;
			j/=10;
		}
		return res;
	}
};
    
 // DFS
class Solution {
public:
    int res=0;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int row,col;
    int movingCount(int rows, int cols,int threshold){
    	vector<vector<int>> vis(rows,vector<int>(cols,0));
        if(threshold<0)
            return 0;
        row=rows;
        col=cols;
        vis[0][0]=1;
        dfs(0,0,vis,threshold);
        return maxx;
    }
 
    
    void dfs(int x,int y,vector<vector<int>> &vis,int k) //当前在（x,y）.
    {
        res++;
        for(int i=0;i<4;i++) //四个方向去找可以走的
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<0 || xx>=row || yy<0 || yy>=col || vis[xx][yy]==1 || xx/10+xx%10+yy/10+yy%10>k)
                continue;
            vis[xx][yy]=1;
            dfs(xx,yy,k);
        }
    }
    
};
 
 
 
 
 