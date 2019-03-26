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

//见一个人给一半 + 0.5 最后刚好没有
//倒数第一个给完之后肯定剩下1 这样最后一个就是 0.5 + 0.5 = 1
//倒数第二个给完之后剩下 x  x - x/2 - 0.5 = 1  x = 3
//倒数第三个给完之后剩下 y  y - y/2 - 0.5 = 3  y =
//... 设倒数第m个人时候剩下 left(m)
//倒数第n个给完之后剩下 m = (left(m - 1) + 0.5) *2 

int left(int n) {
  if(n == 0) return 0;
  else return (left(n - 1) + 0.5) * 2;
}

void solve() {
  int n;
  while(cin >> n) {
    cout << left(n + 1) << endl;
  }
}

int main(int argc, char const *argv[])
{
  solve();
  return 0;
}
