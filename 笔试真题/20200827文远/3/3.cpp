
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


//int main(){
//	int n, q;
//	cin >> n >> q;
//	vector<vector<int>> graph(n, vector<int>(n, 0));
//	for (int i = 0; i < n - 1; ++i) {
//		int u, v, d;
//		cin >> u >> v >> d;
//		graph[u][v] = d;
//	}
//	vector<vector<int>> bat(n, vector<int>(n, 0));
//	for (int i = 0; i < q; ++i) {
//		int s, e, c;
//		cin >> s >> e >> c;
//		bat[s][e] = c;
//	}
//	
//
//}

//
//  main.cpp
//  testC++05
//
//  Created by fei dou on 12-8-7.
//  Copyright (c) 2012年 vrlab. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define INT_MAX 100000000
int map[][5] = {                     //定义有向图
	{0, 10, INT_MAX, INT_MAX, 5},
	{INT_MAX, 0, 1, INT_MAX, 2},
	{INT_MAX, INT_MAX, 0, 4, INT_MAX},
	{7, INT_MAX, 6, 0, INT_MAX},
	{INT_MAX, 3, 9, 2, 0}
};

void Dijkstra(
	const int numOfVertex,    /*节点数目*/
	const int startVertex,    /*源节点*/
	//const int endVertex,
	vector<vector<int>> map,  /*有向图邻接矩阵*/
	vector<int> &distance,            /*各个节点到达源节点的距离*/
	vector<int> &prevVertex           /*各个节点的前一个节点*/
)
{
	vector<bool> isInS;                 //是否已经在S集合中
	isInS.reserve(0);
	isInS.assign(numOfVertex, false);   //初始化，所有的节点都不在S集合中

	/*初始化distance和prevVertex数组*/
	for (int i = 0; i < numOfVertex; ++i)
	{
		distance[i] = map[startVertex][i];
		if (map[startVertex][i] < INT_MAX)
			prevVertex[i] = startVertex;
		else
			prevVertex[i] = -1;       //表示还不知道前一个节点是什么
	}
	prevVertex[startVertex] = -1;

	/*开始使用贪心思想循环处理不在S集合中的每一个节点*/
	isInS[startVertex] = true;          //开始节点放入S集合中


	int u = startVertex;

	for (int i = 1; i < numOfVertex; i++)      //这里循环从1开始是因为开始节点已经存放在S中了，还有numOfVertex-1个节点要处理
	{

		/*选择distance最小的一个节点*/
		int nextVertex = u;
		int tempDistance = INT_MAX;
		for (int j = 0; j < numOfVertex; ++j)
		{
			if ((isInS[j] == false) && (distance[j] < tempDistance))//寻找不在S集合中的distance最小的节点
			{
				nextVertex = j;
				tempDistance = distance[j];
			}
		}
		isInS[nextVertex] = true;//放入S集合中
		u = nextVertex;//下一次寻找的开始节点


		/*更新distance*/
		for (int j = 0; j < numOfVertex; j++)
		{
			if (isInS[j] == false && map[u][j] < INT_MAX)
			{
				int temp = distance[u] + map[u][j];
				if (temp < distance[j])
				{
					distance[j] = temp;
					prevVertex[j] = u;
				}
			}
		}
	}

}


int main(int argc, const char* argv[])
{
	

	int n, q;
	cin >> n >> q;
	vector<int> distance(n,0);
	vector<int> preVertex(n,0);
	vector<vector<int>> map(n, vector<int>(n, INT_MAX));
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		map[u-1][v-1] = d;
		map[i][i] = 0;
	}
	vector<pair<vector<int>,int>> traces;
	vector<vector<int>> bat;
	for (int i = 0; i < q; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		bat.push_back({ s,e,c });
	}
	for (int i = 0; i < q; ++i)
	{
		Dijkstra(n, bat[i][0] - 1, map, distance, preVertex);
		int j = bat[i][1]-1;
		int index = j;
		stack<int > trace;
		pair<vector<int>, int> t;
		while (preVertex[index] != -1) {
			trace.push(preVertex[index]);
			t.first.insert(t.first.begin(), preVertex[index]);
			index = preVertex[index];
		}


	
		cout << distance[j]/bat[i][2]+1 << endl;
		
	}

		

	
	return 0;
}