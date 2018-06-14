#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;
//Rotate array

/*
����K����ת
��ǰn-k�ķ�ת
��������ת
*/
void solve_0(vector<int>& nums, int k) {
	int size = nums.size();
	k = k % size; //k����size �൱��ǰsize��������Ч
	if (size <= 1) return;
	reverse(nums.begin(), nums.begin() + size - k); //��תǰ���
	reverse(nums.begin() + size - k, nums.end()); //��ת�����
	reverse(nums.begin(), nums.end());  //ȫ����ת
}

/*
��һ��һ���Ľ���ǰ�������������棬��ɾ����ǰ���
*/
void solve_2(vector<int>& nums, int k) {
	if (nums.size() <= 1) return;
	k %= nums.size();
	k = nums.size() - k; //��ǰsize - k��������

	while (k--) {
		nums.push_back(nums[0]);
		nums.erase(nums.begin());
	}
}

int main() {

	//code
	vector<int>::iterator it;
	system("pause");
	return 0;
}