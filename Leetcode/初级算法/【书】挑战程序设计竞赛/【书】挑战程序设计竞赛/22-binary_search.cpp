#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
//title

template <class T>

int binary_search(T& x, int target) {
	int left = 0, right = sizeof(x) / sizeof(x[0]);
	cout << right << endl;

	while (right - left >= 1) {
		int i = (right + left) / 2;
		if (x[i] == target) {
			return i;
		}

		if (x[i] < target) {
			left = i + 1;
		} else {
			right = i; //不用减一是因为索引从0开始
		}
	}
	return -1;
}

int main_binary_search() {
	int arr[] = {1, 3, 4, 5, 6, 7, 8};
	//code
	int index = binary_search(arr, 1);
	if (index < 0) {
		cout << "not found!" << endl;
	}
	else {
		cout << arr[index] << endl;
	}
	system("pause");
	return 0;
}