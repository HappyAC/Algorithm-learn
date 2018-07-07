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


long long gcd_division(long long a, long long k) {
  if(k == 0)
    return a;
  else
    return gcd_division(k,a%k);
}

long long gcd_sub(long long a, long long b) {
  while(a != b) {
    if(a > b) a -= b;
    else b -= a;
  }
  return a;
}

void solve() {
  //cout << gcd_sub(16, 1);
  //return;
  int T, N;
  long long b, res, a;
  cin >> T;
  while(T--) {
    cin >> N;
    res = a = 1;

    while(N--) {
      cin >> b;
      res = b / gcd_division(b, a) * a;
      a = res;
    }
    cout << res << endl;
  }
}

int main(int argc, char const *argv[])
{
  solve();
  return 0;
}
