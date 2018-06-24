#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main(int argc, char const *argv[])
{
  set<int> nums;
  int N, M, tmp;
  while(cin >> N >> M) {
    nums.clear();
    for(int i = 0; i < N + M; i++) {
      cin >> tmp;
      nums.insert(tmp);
    }

    set<int>::iterator it = nums.begin();
    while(it != nums.end()) {
      if(it != nums.begin()) cout << " ";
      cout << *it;
      it++;
    }
    cout << endl;
  }
  return 0;
}
