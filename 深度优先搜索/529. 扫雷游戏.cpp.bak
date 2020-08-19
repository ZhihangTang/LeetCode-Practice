

让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
 

示例 1：

输入: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解题思路：点开click向量代表的点，如果该点是空白（E），那么点开该点，并统计该点周围的雷数，雷数为0，该点改为B，并递归点开周围合法的各点；否则该点改为雷数，return；如果该点是雷（M），那么该点改为X，然后return。

class Solution{
public:
    int countM(vector<vector<char>>& board,int xx,int yy){//统计点周围地雷个数
        int count=0;
        int i,j;
        for(i=xx-1;i<=xx+1;++i){
            for(j=yy-1;j<=yy+1;++j){
                if((i==xx&&j==yy)||i<0||j<0||i>=board.size()||j>=board[0].size())
                    continue;
                else{
                    if(board[i][j]=='M')
                        count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        int i,j;
        if(board[x][y]=='E'){       
            if(countM(board,x,y)==0){ //该点是E，则统计周围地雷个数，如果地雷个数为0，则设置为B
                board[x][y]='B';
            }
            else{
                board[x][y]=countM(board,x,y)+'0';//否则该点设为地雷数量
                return;
            }
            for(i=x-1;i<=x+1;++i){         //对该点周围的8个点，进行遍历展开
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

        else if(board[x][y]=='M'){           //如果该点是地雷，标记为X
                board[x][y]='X';
        }   
        
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board,click[0],click[1]);
        return board;
    }
};
