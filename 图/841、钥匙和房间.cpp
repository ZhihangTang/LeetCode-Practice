
841. 钥匙和房间
有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        visit.insert(0);
        q.push(0);
        bfs(rooms);
        if(visit.size()==n){
            return true;
        }
        else return false;
    }
    void dfs(vector<vector<int>> rooms,int v){
        visit.insert(v);
        for(int i=0;i<rooms[v].size();++i){
            if(visit.find(rooms[v][i])==visit.end()){
                dfs(rooms,rooms[v][i]);
            }
        }
    }
    void bfs(vector<vector<int>> rooms){
        while(!q.empty()){
            int cnt=q.size();
            for(int i=0;i<cnt;++i){
                int cur=q.front();
                q.pop();
                for(int j=0;j<rooms[cur].size();++j){
                    if(visit.find(rooms[cur][j])==visit.end()){
                        visit.insert(rooms[cur][j]);
                        q.push(rooms[cur][j]);
                    }
                }
            }
        }

    }
private:
    set<int> visit;
    queue<int> q;
};