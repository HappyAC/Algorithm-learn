#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

//define


using namespace std;
//区间调度问题 39

//typedef
typedef pair<int, int> P;

int N;
const int MAX_SIZE = 100000;
pair<int, int> time_line[MAX_SIZE];

int solve_40() {
	int n = 0, i, ans = 0;
	P p;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> time_line[i].second >> time_line[i].first; //因为对pair进行字典序排列，所以把结束时间放在first
	}
	sort(time_line, time_line + n); //升序排列

	int last_endtime = 0;
	for (i = 0; i < n; i++) {
		if (last_endtime <= time_line[i].second) {
			//如果上个任务结束时间小于等于下个任务开始时间，就接这个任务，不用关心结束时间的对比，因为已经排好序了
			ans++;
			last_endtime = time_line[i].first;
		}
	}

	return n - ans;
}



/*
*
* 主函数
*
*/
int main_40() {
	//code
	cin >> N;
	while (N--) {
		cout << solve_40() << endl;
	}
	return 0;
}