#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
��ȡn���ڵ�������4������ 
*/

// ��һ����2 - n���Գ�
// ��������2 - sqrt(n)���Գ�




// ������������˹����ɸ�� O(nloglogn)
void get_prime1(vector<int> &prime, vector<bool> &isPrime, int n) {
	isPrime.assign(n+10000, true);
	int max_num = (n / log(n)) * 1.17 + 1; 
	// prime.resize(max_num);
	isPrime[0] = false, isPrime[1] = false;
	
	if (n < 2) return;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
//			printf("%d\n", i);
			prime.push_back(i);
			for (int j = i*i; j <= n; j+=i) {
				isPrime[j] = false;
			}
		}
			
	}
}

// ������������������n�������ĸ��� < (n/ln(n)) * 1.17 
// ���ģ�ŷ��ɸ�� O(n)
void get_prime2(vector<int> &prime, vector<bool> &isPrime, int n) {
	isPrime.assign(n+1, true);
	int max_num = (n / log(n)) * 1.17 + 1; 
	// prime.resize(max_num);
	isPrime[0] = false, isPrime[1] = false;
	int index = 0;
	if (n<2) return;
	
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
//			printf("%d\n", i);
		}
		for (int j = 0; j < isPrime.size() && i * isPrime[j] <= n; j++) {
			isPrime[i*prime[j]] = false;
			
			if (i % prime[j] == 0) break;
		}
	}
}

void get_prime(vector<int> &prime, int n)
{
    // ��ʼ��һ���������飬�����ж��±�i�Ƿ�������
    vector<bool> is_prime(n + 1, true);
    if (n < 2)
        return;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i); // ���������뵽������
            // ����ֻ��Ҫ�� i * i ��ʼɸѡ���ɣ�֤��������
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
 

int main () {
	vector<bool> isPrime;
	vector<int> prime;
	int max = 5000000;
	get_prime1(prime, isPrime, max);
	// get_prime(prime, max);
	if (prime[max - 1]) cout << "1" << endl;
	else cout << "0" << endl;
	int N;
	cin >> N;
	int start, end, sum;
	for (int i = 0; i < N; i++) {
		sum = 0;
		cin >> start >> end;
		for (int j = start; j <= end; j++) {
			if (isPrime[j]) sum++;
		}
		printf("[%d,%d]��%d\n", start, end, sum);
	}
	
	return 0;
}
