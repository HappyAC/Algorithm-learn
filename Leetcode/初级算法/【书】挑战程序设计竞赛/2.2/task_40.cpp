#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

//define


using namespace std;
//����������� 39

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
		cin >> time_line[i].second >> time_line[i].first; //��Ϊ��pair�����ֵ������У����԰ѽ���ʱ�����first
	}
	sort(time_line, time_line + n); //��������

	int last_endtime = 0;
	for (i = 0; i < n; i++) {
		if (last_endtime <= time_line[i].second) {
			//����ϸ��������ʱ��С�ڵ����¸�����ʼʱ�䣬�ͽ�������񣬲��ù��Ľ���ʱ��ĶԱȣ���Ϊ�Ѿ��ź�����
			ans++;
			last_endtime = time_line[i].first;
		}
	}

	return n - ans;
}



/*
*
* ������
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