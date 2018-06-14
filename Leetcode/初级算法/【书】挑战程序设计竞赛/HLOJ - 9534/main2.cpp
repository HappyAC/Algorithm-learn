// write your code here cpp
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


int main() {
	int   N = 10
		, M = 10
		, sx = 0              // 起点x
		, sy = 1              // 起点y
		, tx = 9              // 终点x
		, ty = 8              // 终点y
		, dis[MAX_LEN][MAX_LEN]    // 记录到各点的距离
		, nx              //下一个到达点x
		, ny              //下一个到达点y
		, x = 0
		, y = 0
		, drx[4] = { 0 , 1, 0, -1 }
		, dry[4] = { -1, 0, 1, 0 }
	;
	pair<int, int>		cur;
	char maze[MAX_LEN][MAX_LEN];
	queue< pair<int, int> > next;
	char tmp;
	while (cin >> tmp) {
		if (y != 10) {
			x++;
			if (x == 10) {
				x = 0;
				y++;
			}
			maze[x][y] = tmp;
			if(y != 10)
				continue;
		}
		else x = 0, y = 0;
		while (next.size()) next.pop();
		fill(dis[0], dis[0] + MAX_LEN * MAX_LEN, INF);
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
					next.push(pair<int, int>(nx, ny));
					dis[nx][ny] = min(dis[cur.first][cur.second] + 1, dis[nx][ny]);
				}
			}
		}
		if (dis[tx][ty] == INF) cout << "impossible" << endl;
		else cout << dis[tx][ty] << endl;
	}
	return 0;
}