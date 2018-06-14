#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>

#define INF 999999
#define MAX_LEN 100

using namespace std;


int main__1() {
	int   N
		, M
		, sx              // 起点x
		, sy              // 起点y
		, tx              // 终点x
		, ty              // 终点y
		, dis[MAX_LEN][MAX_LEN]    // 记录到各点的距离
		, nx              //下一个到达点x
		, ny              //下一个到达点y
		, drx[4] = { 0 , 1, 0, -1 }
		, dry[4] = { -1, 0, 1, 0 }
	;
	pair<int, int> cur;
	char maze[MAX_LEN][MAX_LEN];
	queue< pair<int, int> > next;
	while (cin >> N >> M) {
		while (next.size()) next.pop();
		fill(dis[0], dis[0] + MAX_LEN * MAX_LEN, INF);

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> maze[x][y];
				if (maze[x][y] == 'S') sx = x, sy = y;
				if (maze[x][y] == 'T') tx = x, ty = y;
			}
		}
		dis[sx][sy] = 0;
		next.push(pair<int, int>(sx, sy));

		while (next.size()) {
			cur = next.front();
			next.pop();
			for (int i = 0; i < 4; i++) {
				nx = cur.first + drx[i];
				ny = cur.second + dry[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || dis[nx][ny] != INF) continue;

				if (maze[nx][ny] != '#') {
					dis[nx][ny] = min(dis[cur.first][cur.second] + 1, dis[nx][ny]);
					next.push(pair<int, int>(nx, ny));
				}
			}
		}
		if (dis[tx][ty] == INF) cout << "impossible" << endl;
		else cout << dis[tx][ty] << endl;
	}
	return 0;
}