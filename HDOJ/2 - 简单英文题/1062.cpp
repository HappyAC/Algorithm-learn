#include <iostream> 
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  string    s
          , temp
          , col
          ;
  char line[1001];
  int   n
      , begin
      , end
      , mark
      ;
  cin >> n;
  cin.get();
  while(n--) {
    s = "";
    cin.getline(line, 1000);
    s = line;
    s[s.size()] = '*'; //TODO: 为什么这个*号不会输出
    int pos = 0;
    for(int i = 0; i <= s.size(); i++) {
      if(s[i] == ' ') {
        reverse(s.begin() + pos, s.begin() + i);
        pos = i + 1;
      }
    }
    cout << s << endl;
  }
  return 0;
}
