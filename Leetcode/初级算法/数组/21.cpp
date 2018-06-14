#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int removeDuplicates(vector<int> &nums) {
	if (nums.size() <= 1) return (int)nums.size();

	//µü´úÆ÷±éÀú
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end() - 1; ) {
		if (*it == *(it+1)) {
			it = nums.erase(it);
		} else {
			it++;
		}
	}

	return (int)nums.size();
}

int main_21() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	cout << "result:" << removeDuplicates(nums) << endl;

	system("pause");
	return 0;
}