#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

//define
#define MAX_LEN 4

using namespace std;
//部分和问题-30页

/***
	* 从第一个数开始，逐次判断下一个数加或不加的情况是否满足
	*/

int nums[MAX_LEN] = {1, 2, 4, 7};
int sum = 0, i = 0, k = 13;
//假设当前是第i次相加，目前和为sum
bool dfs(int i, int sum) {
	if (i == MAX_LEN) return sum == k;
	//如果加上一个相等的话，返回真
	if (dfs(i + 1, sum + nums[i])) return true;
	//如果下一个不加相等的话，返回真
	if (dfs(i + 1, sum)) return true;

	return false;
}


int main_30() {
	//code
	cout << dfs(0, 0) << endl;
	system("pause");
	return 0;
}