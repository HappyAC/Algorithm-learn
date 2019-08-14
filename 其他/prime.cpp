#include<iostream>
#include<cmath>

using namespace std;

/*
获取n以内的素数的4个方法 
*/

// 法一：从2 - n，试除
// 法二：从2 - sqrt(n)，试除


vector<bool> isPrime;
vector<int> prime;

// 法三：埃拉托斯特尼筛法 O(nloglogn)
void get_prime1(vector<int> &prime, vector<bool> &isPrime, int n) {
	isPrime.assign(n + 1, true);
	int max_num = (n / log(n)) * 1.17 + 1;

	if (n < 2) return;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= n && i < sqrt(n); j += i) {
				isPrime[j] = false;
			}
		}

	}
}

// 根据素数定理：不大于n的素数的个数 < (n/ln(n)) * 1.17 
// 法四：欧拉筛法 O(n)
void get_prime2(vector<int> &prime, vector<bool> &isPrime, int n) {
	isPrime.assign(n + 1, true);
	int max_num = (n / log(n)) * 1.17 + 1;
	if (n < 2) return;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < isPrime.size() && i * prime[j] <= n; j++) {
			isPrime[i*prime[j]] = false;

			if (i % prime[j] == 0) break;
		}
	}
}
 

int main () {
	
	
	return 0;
}
