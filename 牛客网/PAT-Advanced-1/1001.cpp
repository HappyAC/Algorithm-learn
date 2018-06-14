/**
解法1： 邻接矩阵
N： 总station数  <= 500   【使用邻接矩阵】
1. 寻找最短路径
2. 计算携带的最少车辆数
3. 计算返回时带回的车辆数

无向图， 带权重
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream> //用户类型转换

#define INF 9999999

using namespace std;
//从顶点from 指向定点to 的权值为cost的边
struct edge {
	int from,
		to,
		cost;
};



const int		 MAX_V	= 500					  //最大station数量
				, MAX_E	= 250000;				  //最大边数

int				 V								  //顶点数
				, E								  //边数
				, ps							  //需要fix的station
				, MAX_CAPACITY					  //station的最大容量 
				, PERFECT_STOCK					  //完美容量
				, vs[MAX_V]						  //所有顶点
				, d[MAX_V]                        //从点s到各点的距离
				, take[MAX_V]					  //从s到点需要从PBMC带的Bike数量
				, tb[MAX_V];					  //从s到点会带回来的数量

edge			es[MAX_E];                        //所有的边

string			d_path[MAX_V];					  //从点s到各点的最短距离走法

//Dijkstra
int				cost[MAX_V][MAX_V];				  //cost[i][j] 表示边e=(i, j) 的权值，不存在设为INF
bool			used[MAX_V];					  //已经使用过的图


string int2string(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

//获取从s点出发，到所有点的距离  Bellman-Ford 算法
void shortest_path(int s) {
	for (int i = 0; i < V; i++) d[i] = INF;
	d[s] = 0;

	while (true) {
		bool update = false;

		for (int i = 0; i < E; i++) {
			edge e = es[i];
			if (d[i] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update	= true;
			}
		}
		if (!update) break;
	}
}

//求从起点s出发到各顶点的最短距离   Dijkstra
void dijkstra(int s) {
	fill(d,			d			+ V,			INF);					//填充
	fill(used,		used		+ V,			false);
	fill(d_path,	d_path		+ V,			"");
	fill(take,		take		+ V,			INF);
	fill(tb,		tb			+ V,			INF);

	d[s]			= 0;												//起点到起点的距离是一开始就确定的
	d_path[s]		= int2string(s);
	take[s]			= 0;
	tb[s]			= 0;

	while (true) {
		int v = -1;
		//从未使用过的顶点中选择一个距离最小的点
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}

		if (v == -1) break;													//所有的点均遍历完成
		used[v] = true;
		for (int u = 0; u < V; u++) {
			if (u == v) continue;
			int add		= max(PERFECT_STOCK - vs[u], 0)					//应该给此station添加的bike
				, left	= max(vs[u] - PERFECT_STOCK, 0);				//此车站能collect的bike

			if (d[u] > d[v] + cost[v][u]) {//选取最短路径
				d[u]		= d[v]		+ cost[v][u];						//记录该路径cost
				d_path[u]	= d_path[v] + "->" + int2string(u);				//记录路径
				if (add == 0) {
					take[u] = take[v];
				}
				else {
					take[u] = max(0, take[v] + add - tb[v]);						//记录应该带过去的bike
				}
				tb[u]		= max(0, tb[v]		+ left - add);				//记录能够带回的
			}
			else if (d[u] == (d[v] + cost[v][u])
				&& d[u] != INF
				&& take[u] > (take[v] + add - tb[v])) {						//路径相等，选带过去最少的

				d[u]		= d[v]		+ cost[v][u];						//记录该路径cost
				d_path[u]	= d_path[v] + "->" + int2string(u);				//记录路径
				if (add == 0) {
					take[u] = take[v];
				}
				else {
					take[u] = max(0, take[v] + add - tb[v]);						//记录应该带过去的bike
				}
				tb[u]		= max(0, tb[v] + left - add);					//记录能够带回的
			}
			else if (d[u] == (d[v] + cost[v][u])
				&& d[u] != INF 
				&& take[u] == (take[v] + add - tb[v])
				&& tb[u] > (tb[v] + left - add)) {//路径相等 带过去的相等 选择带回少的

				d[u]		= d[v]		+ cost[v][u];						//记录该路径cost
				d_path[u]	= d_path[v] + "->" + int2string(u);				//记录路径
				if (add == 0) {
					take[u] = take[v];
				}
				else {
					take[u] = max(0, take[v] + add - tb[v]);						//记录应该带过去的bike
				}
				tb[u]		= max(0, tb[v] + left - add);				//记录能够带回的
			}
		}
	}
}

//输入
void input() {
	cin >> V >> E;
	V = V + 1;

	for (int i = 0; i < E; i++) {
		cin >> es[i].from >> es[i].to >> es[i].cost;
	}
}

//Dijk 输入
void dijk_input() {
	int v
		, u
		, d;

	cin >> MAX_CAPACITY >> V >> ps >> E;
	V = V + 1; //PBMC 不做输入
	for (int i = 0; i < V; i++) { //二维数组的fill
		fill(cost[i], cost[i] + V * V, INF);
	}

	PERFECT_STOCK = MAX_CAPACITY / 2;

	for (int i = 1; i < V; i++) {
		cin >> vs[i];
	}
	for (int i = 0; i < E; i++) {
		cin >> v >> u >> d;
		cost[v][u] = d;
		cost[u][v] = d;
	}
}



/**
*
*
*	MAIN
*
*
*/
int main() {
	int start_V = 0;

	dijk_input();
	dijkstra(start_V);

	/*cout << "from " << start_V << " start：" << endl;
	for (int i = 0; i < V; i++) {
		cout << "to " << i << " shortest：" << d[i] << endl;
		cout << "path:" << d_path[i] << endl;
		cout << "take:" << take[i] << endl;
		cout << "take back:" << tb[i] << endl;
		cout << endl;
	}*/
	cout << take[ps] << " " << d_path[ps] << " " << tb[ps] << endl;
	system("pause");
	return 0;
}
