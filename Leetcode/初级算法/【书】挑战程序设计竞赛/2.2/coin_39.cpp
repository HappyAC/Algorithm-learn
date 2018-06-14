#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

//define

using namespace std;
//硬币问题 39

//typedef
typedef pair<int, int> P; //币值，数量

const int MAX_SIZE = 10;
P B[MAX_SIZE];

bool compare_39(P a, P b) {
	return a.first < b.first;  //根据pair的第一个值升序排列
}

int solve_39() {
	int N, A, ans = 0, sum = 0;

	//input
	cin >> N;
	for (int j = 0; j < N; j++) {
		cin >> B[j].first >> B[j].second;
	}
	cin >> A;

	sort(B, B + N, compare_39); //根据面值排序

	for (int i = N - 1; i >= 0; i--) {
		if (B[i].first == 0) continue;
		int num = min(A / B[i].first, B[i].second);
		A		-= num * B[i].first; //更新支付过的1
		sum		+= num * B[i].first;
		ans		+= num; //记录总使用硬币量
		/*if (num != 0) {
			cout << B[i].first << "=>" << num << " sum:" << sum << endl;
		}*/
		if (A == 0) return ans;
	}
	return -1;
}


/*
*
* 主函数
*
*/
int main_39() {
	//code
	cout << solve_39() << endl;

	//system("pause");
	return 0;
}