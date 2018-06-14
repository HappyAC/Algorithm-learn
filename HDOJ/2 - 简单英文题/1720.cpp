#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;


int getDecimal(char n) {
  n = (n >= 'A' && n <= 'Z') ? (n+32) : n;
  string s = "0123456789abcdef";
  cout << s << endl;
  int i = 0;
  for(; i < s.length(); i++) {
    if(s[i] == n) return i;
  }
  return i;
}

int main() {
  char    a
        , b
        ;
  int     _a
        , _b
        ;
  while(cin >> hex >> _a >> _b) {
    cout << dec << _a + _b << endl;
  }
  return 0;
}