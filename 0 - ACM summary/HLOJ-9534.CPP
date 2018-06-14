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


int main_1() {
	int   N
		, M
		, sx              // 璧风偣x
		, sy              // 璧风偣y
		, tx              // 缁堢偣x
		, ty              // 缁堢偣y
		, dis[MAX_LEN][MAX_LEN]    // 璁板綍鍒板悇鐐圭殑璺濈
		, nx              //涓嬩竴涓埌杈剧偣x
		, ny              //涓嬩竴涓埌杈剧偣y
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