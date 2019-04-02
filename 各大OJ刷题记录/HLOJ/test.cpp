#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
            printf("%d ", i);
            // 这里只需要从 i * i 开始筛选即可，证明见下文
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
int main()
{
    int n = 50000;
    vector<int> prime;
    get_prime(prime, n);
    // 打印计算出的素数
   
    return 0;
}
