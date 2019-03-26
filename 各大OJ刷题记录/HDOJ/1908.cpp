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


int main(int argc, char const *argv[])
{
  int cmd = 0, K, P;
  map<int, int> list;
  while(cin >> cmd) {
    if(cmd == 0) break;
    else if (cmd == 1) {
      //创建账号 后面输入名字 / 优先级
      cin >> K >> P;
      list.insert(pair<int, int>(P, K));
    }
    else if(cmd == 2) {
      //返回账户中优先级最高的名字
      if(list.empty()) cout << 0 << endl;
      else {
        cout << list.rbegin()->second << endl;
        list.erase(list.find(list.rbegin()->first));
      }
    }
    else if (cmd == 3) {
      //返回账户中优先级最低的名字
      if(list.empty()) cout << 0 << endl;
      else {
        cout << list.begin()->second << endl;
        list.erase(list.begin());
      }
    }
  }
  return 0;
}
