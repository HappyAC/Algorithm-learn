#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

#define MAX 100000


bool notprime[MAX]; // false => prime true => not prime
int prime[80000];

//用筛选法求素数
void getPrime() {
  //！注意从2开始
  for(int i = 2; i < sqrt(MAX); i++) {
    for(int j = i*i; j <= MAX; j += i) {
      if(!notprime[j])
        notprime[j] = true;
    }
  }
  int cnt = 0;
  for(int i = 2; i < MAX; i++) {
    if(!notprime[i]) {
      prime[cnt++] = i;
    }
  }
}

void solve() {
  int N, min, res1, res2;
  while(cin >> N) {
    min = MAX;
    for(int i = 0; ; i++) {
      if(prime[i] > N) break;
      for(int j = 0; ; j++) {
        if(prime[j] + prime[i] > N) break;
        if(abs(prime[j] - prime[i]) < min && prime[j] + prime[i] == N) {
          //update
          res1 = prime[i];
          res2 = prime[j];
          min  = abs(prime[j] - prime[i]);
          if(res1 > res2) swap(res1, res2);
        }
      }
    }
    cout << res1 << " " << res2 << endl;
  }
}

int main(int argc, char const *argv[])
{
  getPrime();
  solve();
  return 0;
}
