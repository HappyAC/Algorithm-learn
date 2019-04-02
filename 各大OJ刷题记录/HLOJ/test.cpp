#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
            printf("%d ", i);
            // ����ֻ��Ҫ�� i * i ��ʼɸѡ���ɣ�֤��������
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
    // ��ӡ�����������
   
    return 0;
}
