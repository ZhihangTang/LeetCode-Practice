// 用邻接矩阵表示图的广度优先搜索
#include<iostream>
#include<queue>
#include<vector>

queue<char> q;
#define MVNUM 100
bool visited[MVNUM]

//邻接矩阵存储表示
typedef struct AMGraph
{
    char vexs[MVNUM];
    int arcs[MVNUM][MVNUM];
    int vexnum,arcnum;
}AMGraph;

//找到顶点v的对应下标
int LocateVex(AMGraph &G,char v)
{
    int i;
    for(i=0;i<G.vexnum;i++){
        if(G.vexs[i]==v)
            return i;
    }
}

//采用邻接矩阵表示法，创建无向图G
int CreateUDG_1(AMGraph& G){
    int i,j,k;
    char v1,v2;
    scanf("%d%d",&G.vexnum,&G.arcnum);
    getchar();
    for(int i=0;i<vexnum;++i){
        scanf("%c",&G.vexs[i]);
    }
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;++j){
            G.arcs[i][j]=0;

        }
    }
    for(k=0;k<G.arcnum;++k){
        getchar();
        scanf("%c%c",&v1,&v2);
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=G.arcs[j][i]=1;
    }
    return 1;
}

//采用邻接矩阵表示图的广度优先遍历
void BFS_AM(AMGraph &G,char v0){
 //从v0开始访问图
    int u,i,v,w;
    v=LocateVex(G,v0);//找到v0对应的下标
    printf("%c",v0);
    visited[v]=1;
    q.push(v0);
    while(!q.empty()){
        u=q.front();
        v=LocateVex(G,u);
        q.pop();
        for(int i=0;i<G.vexnum;++i){
            if(G.arcs[v][i]&&!visited[i]){
                printf("%c",w);
                q.push(w);
                visited[i]=1;
            }
        }
    }
}

/*找到顶点对应的下标*/
int LocateVex(ALGraph &G, char v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (v == G.vertices[i].data)
			return i;
}
/*邻接表存储表示*/
typedef struct ArcNode	        //边结点
{
	int adjvex;		//该边所指向的顶点的位置
	ArcNode *nextarc;	//指向下一条边的指针
	int info;		//和边相关的信息，如权值
}ArcNode;

typedef struct VexNode		//表头结点
{
	char data;
	ArcNode *firstarc;	//指向第一条依附该顶点的边的指针
}VexNode,AdjList[MVNum];	//AbjList表示一个表头结点表

typedef struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

/*采用邻接表表示法，创建无向图G*/
int CreateUDG_2(ALGraph &G)
{
	int i, j, k;
	char v1, v2;
	scanf("%d%d", &G.vexnum, &G.arcnum);	        //输入总顶点数，总边数
	getchar();
	for (i = 0; i < G.vexnum; i++)			//输入各顶点，构造表头结点表
	{
		scanf("%c", &G.vertices[i].data);	//输入顶点值
		G.vertices[i].firstarc = NULL;		//初始化每个表头结点的指针域为NULL
	}
	for (k = 0; k < G.arcnum; k++)			//输入各边，构造邻接表
	{
		getchar();
		scanf("%c%c", &v1, &v2);			//输入一条边依附的两个顶点
		i = LocateVex(G, v1);				//找到顶点i的下标
		j = LocateVex(G, v2);				//找到顶点j的下标
		ArcNode *p1 = new ArcNode;			//创建一个边结点*p1
		p1->adjvex = j;						//其邻接点域为j
		p1->nextarc = G.vertices[i].firstarc; G.vertices[i].firstarc = p1; // 将新结点*p插入到顶点v1的边表头部
		ArcNode *p2 = new ArcNode;			//生成另一个对称的新的表结点*p2
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p1;
	}
	return 1;
}

/*采用邻接表表示图的广度优先遍历*/
void BFS_AL(ALGraph &G, char v0)
{
	int u,w,v;
	ArcNode *p;
	printf("%c ", v0);		                                        //打印顶点v0
	v = LocateVex(G, v0);	                                                //找到v0对应的下标
	visited[v] = 1;			                                        //顶点v0已被访问
	q.push(v0);				                                //将顶点v0入队
	while (!q.empty())
	{
		u = q.front();		                                        //将顶点元素u出队，开始访问u的所有邻接点
		v = LocateVex(G, u);                                            //得到顶点u的对应下标
		q.pop();			//将顶点u出队
		for (p = G.vertices[v].firstarc; p; p = p->nextarc)		//遍历顶点u的邻接点
		{
			w = p->adjvex;
			if (!visited[w])	//顶点p未被访问
			{
				printf("%c ", G.vertices[w].data);	        //打印顶点p
				visited[w] = 1;				        //顶点p已被访问
				q.push(G.vertices[w].data);			//将顶点p入队
			}
		}
	}
}


/*广度优先搜索非连通图*/
void BFSTraverse(AMGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;							//将visited数组初始化
	for (v = 0; v < G.vexnum; v++)
		if (!visited[v]) BFS_AM(G, G.vexs[v]);	                        //对尚未访问的顶点调用BFS
}