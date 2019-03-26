#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <vector>

#define MAX 35000

using namespace std;

vector<int> seq;

void init() {
  vector<int> line;

  for(int i = 2; i < MAX; i++) {
    line.push_back(i);
  }
  int n, cnt = 0;
  vector<int>::iterator it, tmp;
  while(it < line.end()) {
    cnt++;
    it = line.begin();
    n = *it;
    //cout << n << ":" << endl;
    seq.push_back(n);
    n--;
    tmp = it + n;
    it = line.erase(it); //返回删除元素的后一个元素
    while(tmp < line.end()) {
      //cout << *tmp << " ";
      tmp = line.erase(tmp);
      tmp += n;
    }
  }
  //cout << "TOTAL: " << cnt << endl;
}

int main() {
  int n;
  init();
  while(cin >> n) {
    if(n == 0) break;
    cout << seq[n - 1] << endl;
  }
  return 0;
}