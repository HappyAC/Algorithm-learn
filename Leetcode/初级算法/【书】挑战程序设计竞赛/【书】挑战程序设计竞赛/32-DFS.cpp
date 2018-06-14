#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#define ROW_LEN 10
#define COL_LEN 12

using namespace std;
//Lake Counting （POJ No.2386）

char field[ROW_LEN][COL_LEN] = {
	{ 'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.' },
	{ '.', 'W', 'W', 'W', '.', '.', '.', '.', '.', 'W', 'W', 'W' },
	{ '.', '.', '.', '.', 'W', 'W', '.', '.', '.', 'W', 'W', '.' },
	{ '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.' },
	{ '.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.' },
	{ '.', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', '.', '.' },
	{ '.', 'W', '.', 'W', '.', '.', '.', '.', '.', 'W', 'W', '.' },
	{ 'W', '.', 'W', '.', 'W', '.', '.', '.', '.', '.', 'W', '.' },
	{ '.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', '.' },
	{ '.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', 'W', '.' }
};


//使用这个函数，将从一个W开始，将与之联系的所有W替换成 .
void dfs_32(int x, int y) {
	field[x][y] = '.';
	//用二重循环模拟八个方向
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int n_x = i + x, n_y = j + y;
			if (n_x < ROW_LEN && n_x >= 0 && n_y >= 0 && n_y < COL_LEN && field[n_x][n_y] == 'W') {
				//没有越界，并且是W 那就从这个开始把与之联系的W替换掉
				dfs_32(n_x, n_y);
			}
		}
	}
}

int solve_32() {
	int sum = 0;
	//寻找一个W
	for (int i = 0; i < ROW_LEN; i++) {
		for (int j = 0; j < COL_LEN; j++) {
			if (field[i][j] == 'W') {
				sum++;
				dfs_32(i, j);
			}
		}
	}
	
	return sum;
}
int main_32() {
	//code
	cout << solve_32() << endl;
	system("pause");
	return 0;
}