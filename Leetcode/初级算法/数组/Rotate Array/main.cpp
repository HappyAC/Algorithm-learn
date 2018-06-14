#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;
//Rotate array

/*
将后K个翻转
将前n-k的翻转
将整个翻转
*/
void solve_0(vector<int>& nums, int k) {
	int size = nums.size();
	k = k % size; //k超过size 相当于前size整数次无效
	if (size <= 1) return;
	reverse(nums.begin(), nums.begin() + size - k); //翻转前面的
	reverse(nums.begin() + size - k, nums.end()); //翻转后面的
	reverse(nums.begin(), nums.end());  //全部翻转
}

/*
将一个一个的将最前面的数放在最后面，再删除最前面的
*/
void solve_2(vector<int>& nums, int k) {
	if (nums.size() <= 1) return;
	k %= nums.size();
	k = nums.size() - k; //对前size - k个数操作

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