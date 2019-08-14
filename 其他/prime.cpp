#include<iostream>
#include<cmath>

using namespace std;

/*
��ȡn���ڵ�������4������ 
*/

// ��һ����2 - n���Գ�
// ��������2 - sqrt(n)���Գ�


vector<bool> isPrime;
vector<int> prime;

// ������������˹����ɸ�� O(nloglogn)
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

// ������������������n�������ĸ��� < (n/ln(n)) * 1.17 
// ���ģ�ŷ��ɸ�� O(n)
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
