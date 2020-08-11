'''
面试题 16.19. 水域大小
你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]

'''
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        for(int i=0;i<land.size();++i){
            for(int j=0;j<land[i].size();++j){
                int count=0;if(land[i][j]==0){
                    dfs(land,i,j,count);
                    if(count!=0) res.push_back(count);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    void dfs(vector<vector<int>>&land,int x,int y,int& count){
        land[x][y]=-1;
        count++;
        int dx[8] = {0,1,1,1,0,-1,-1,-1},dy[8] = {1,1,0,-1,-1,-1,0,1};//方向数组
        for(int i = 0;i < 8;i++)
        {
            int x1 = dx[i] + x;
            int y1 = dy[i] + y;
            if(x1 >= 0 && x1 < land.size() && y1 >= 0 && y1 <land[0].size() && land[x1][y1] == 0)//在方格内且是鱼塘
            dfs(land,x1,y1,count);//再次搜索
        }
    }
};
