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
#define INF 100000000  //���޴��ֵ

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
int sx = 0, sy = 1; //�������
int gx = 9, gy = 8; //�յ�����
int dx[4] = { 1, 0, -1,  0 };
int dy[4] = { 0, 1,  0, -1 };

int bfs_35() {
	queue<P> q;
	//��d��Ϊ���޴�
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			d[i][j] = INF;
		}
	}
	q.push(P(sx, sy)); //�����������
	d[sx][sy] = 0;
	while (q.size()) {
		P p = q.front(); //ȡ����һ��Ԫ��
		q.pop(); //��һ��Ԫ�س���
		if (p.first == gx && p.second == gy) break;

		//�ĸ������ѭ��
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//�����һ���ܹ������ʣ�����û�з��ʹ������Ҳ���ǽ����ΪҲ�п�����G���յ㣩
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
* ������
*
*/
int main_35() {
	//code
	solve_35();
	system("pause");
	return 0;
}