#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

//define

using namespace std;
//Ӳ������ 39

//typedef
typedef pair<int, int> P; //��ֵ������

const int MAX_SIZE = 10;
P B[MAX_SIZE];

bool compare_39(P a, P b) {
	return a.first < b.first;  //����pair�ĵ�һ��ֵ��������
}

int solve_39() {
	int N, A, ans = 0, sum = 0;

	//input
	cin >> N;
	for (int j = 0; j < N; j++) {
		cin >> B[j].first >> B[j].second;
	}
	cin >> A;

	sort(B, B + N, compare_39); //������ֵ����

	for (int i = N - 1; i >= 0; i--) {
		if (B[i].first == 0) continue;
		int num = min(A / B[i].first, B[i].second);
		A		-= num * B[i].first; //����֧������1
		sum		+= num * B[i].first;
		ans		+= num; //��¼��ʹ��Ӳ����
		/*if (num != 0) {
			cout << B[i].first << "=>" << num << " sum:" << sum << endl;
		}*/
		if (A == 0) return ans;
	}
	return -1;
}


/*
*
* ������
*
*/
int main_39() {
	//code
	cout << solve_39() << endl;

	//system("pause");
	return 0;
}