
#include<iostream>
#include<queue>
#include<vector>

queue<char> q;
#define MVNUM 100
bool visited[MVNUM]


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
}