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

void solve() {
  string s, maxs = "(max)";
  char max;
  while(cin >> s) {
    max = s[0];
    for(int i = 1; i < s.size(); i++) {
      if(s[i] > max) {
        max = s[i];
      }
    }

    for(int i = 0; i < s.size(); i++) {
      cout << s[i];
      if(s[i] == max) cout << maxs;
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[])
{
  solve();
  return 0;
}
