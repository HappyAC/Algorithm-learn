#include <iostream>
#include <string>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

/*
	Dijkstra 最短路
*/

#define INF 10000 

vector< vector<int> > cost; // 从a到b的距离集合
vector<int> used; // 点i是否被访问
vector<int> dist; // 到i点的距离
int V, M; // 顶点 边数
int S, T; // 起点 终点

void init(int V) {
	cost.resize(V);
	for (int i = 0; i < V; i++) {
		cost[i].assign(V, INF);
	}
	used.assign(V, false);
	dist.assign(V, INF);
}

void input() {
	init(V);
	int s, t, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &s, &t, &c);
		c = min(c, cost[s][t]);
		
		cost[s][t] = c;
		cost[t][s] = c;
		cost[i][i] = 0;
	}
	scanf("%d%d", &S, &T);
}

void Dijkstra() {
	dist[S] = 0;

	while (true) {
		int v = -1;

		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || dist[u] < dist[v]))
				v = u;
		}

		if (v == -1) break; // 所有点均访问
		used[v] = true;

		for (int i = 0; i < V; i++) {
			dist[i] = min(dist[i], dist[v] + cost[v][i]);
		}
	}
}


int main() {
	while (cin >> V >> M) {
		input();
		Dijkstra();
		
		if (dist[T] == INF)
			cout << -1 << endl;
		else
			cout << dist[T] << endl;
	}
	return 0;
}
