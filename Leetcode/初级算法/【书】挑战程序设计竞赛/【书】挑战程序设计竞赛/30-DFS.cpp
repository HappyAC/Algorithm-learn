#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

//define
#define MAX_LEN 4

using namespace std;
//���ֺ�����-30ҳ

/***
	* �ӵ�һ������ʼ������ж���һ�����ӻ򲻼ӵ�����Ƿ�����
	*/

int nums[MAX_LEN] = {1, 2, 4, 7};
int sum = 0, i = 0, k = 13;
//���赱ǰ�ǵ�i����ӣ�Ŀǰ��Ϊsum
bool dfs(int i, int sum) {
	if (i == MAX_LEN) return sum == k;
	//�������һ����ȵĻ���������
	if (dfs(i + 1, sum + nums[i])) return true;
	//�����һ��������ȵĻ���������
	if (dfs(i + 1, sum)) return true;

	return false;
}


int main_30() {
	//code
	cout << dfs(0, 0) << endl;
	system("pause");
	return 0;
}