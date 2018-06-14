#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
//title
#define MAX_LEN 10000

int fib[MAX_LEN];

int fibo(int i) {
	if (i <= 1) return i;
	if (fib[i] != 0) return fib[i];
	else return fib[i] = fibo(i - 1) + fibo(i - 2);
}

int main_fibo() {
	//code
	cout << fibo(10) << endl;
	system("pause");
	return 0;
}