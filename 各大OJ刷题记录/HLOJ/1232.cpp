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

bool notprime[1000000]; // false => prime true => not prime
int prime[80000];

//用筛选法求素数
void getPrime() {
  //！注意从2开始
  for(int i = 2; i < 1000; i++) {
    for(int j = i*i; j <= 1000000; j += i) {
      if(!notprime[j])
        notprime[j] = true;
    }
  }
}

void solve() {
  int T, min, max;
  string res;
  cin >> T;
  while(T--) {
    res = "NO";
    cin >> min >> max;
    for(int i = min; i < max;i++) {
      if(!notprime[i] && !notprime[i + 2]) {
        res = "YES";
        break;
      }
    }
    cout << res << endl;
  }
}

int main(int argc, char const *argv[])
{
  getPrime();
  solve();
  return 0;
}
