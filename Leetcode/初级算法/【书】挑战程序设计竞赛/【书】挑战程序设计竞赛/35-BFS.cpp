#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;
//title

//define
#define MAX_ROW 10
#define MAX_COL 10
#define INF 100000000  //无限大的值

//typedef
typedef pair<int, int> P;

char maze[MAX_COL][MAX_COL] = {
	{ '#', 'S', '#', '#', '#', '#', '#', '#', '.', '#' },
	{ '.', '.', '.', '.', '.', '.', '#', '.', '.', '#' },
	{ '.', '#', '.', '#', '#', '.', '#', '#', '.', '#' },
	{ '.', '#', '.', '.', '.', '.', '.', '.', '.', '.' },
	{ '#', '#', '.', '#', '#', '.', '#', '#', '#', '#' },
	{ '.', '.', '.', '.', '#', '.', '.', '.', '.', '#' },
	{ '.', '#', '#', '#', '#', '#', '#', '#', '.', '#' },
	{ '.', '.', '.', '.', '#', '.', '.', '.', '.', '.' },
	{ '.', '#', '#', '#', '#', '.', '#', '#', '#', '.' },
	{ '.', '.', '.', '.', '#', '.', '.', '.', 'G', '#' }
};

int d[MAX_ROW][MAX_COL];
int sx = 0, sy = 1; //起点坐标
int gx = 9, gy = 8; //终点坐标
int dx[4] = { 1, 0, -1,  0 };
int dy[4] = { 0, 1,  0, -1 };

int bfs_35() {
	queue<P> q;
	//将d设为无限大
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			d[i][j] = INF;
		}
	}
	q.push(P(sx, sy)); //将起点加入队列
	d[sx][sy] = 0;
	while (q.size()) {
		P p = q.front(); //取出第一个元素
		q.pop(); //第一个元素出队
		if (p.first == gx && p.second == gy) break;

		//四个方向的循环
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//如果下一个能过够访问，而且没有访问过，并且不是墙（因为也有可能是G，终点）
			if (nx >= 0 && nx < MAX_ROW && ny >= 0 && ny < MAX_COL &&
				maze[nx][ny] != '#' && d[nx][ny] == INF) {
				q.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}

int solve_35() {
	int res = bfs_35();
	cout << res << endl;
	return res;
}


/*
*
* 主函数
*
*/
int main_35() {
	//code
	solve_35();
	system("pause");
	return 0;
}