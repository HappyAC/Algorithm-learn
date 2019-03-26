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

int string2int(string s) {
  while(s[0] == '0' && s.size() != 1) s = s.substr(1);
  int c = 1, sum = 0;
  for(int i = s.size() - 1; i >= 0; i--) {
    sum += (int)(s[i] - '0') * c;
    c *= 10;
  }
  return sum;
}

int main(int argc, char const *argv[])
{
  string s, tmps;
  int tmpi;
  vector<int> nums;
  while(cin >> s){
    nums.clear();
    tmps = "";
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '5') {
        if(tmps == "") continue;
        tmpi = string2int(tmps);
        nums.push_back(tmpi);
        tmps = "";
        continue;
      }
      tmps += s[i];
    }
    if(tmps != "") {
      tmpi = string2int(tmps);
      nums.push_back(tmpi);
    }
    sort(nums.begin(), nums.end());
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++) {
      if(it != nums.begin()) cout << " ";
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
