#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
获取n以内的素数的4个方法 
*/

// 法一：从2 - n，试除
// 法二：从2 - sqrt(n)，试除




// 法三：埃拉托斯特尼筛法 O(nloglogn)
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

// 根据素数定理：不大于n的素数的个数 < (n/ln(n)) * 1.17 
// 法四：欧拉筛法 O(n)
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
    // 初始化一个布尔数组，用于判断下标i是否是素数
    vector<bool> is_prime(n + 1, true);
    if (n < 2)
        return;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i); // 把素数加入到数组中
            // 这里只需要从 i * i 开始筛选即可，证明见下文
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
		printf("[%d,%d]：%d\n", start, end, sum);
	}
	
	return 0;
}
