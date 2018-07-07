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

string reverse(string num) {
  int zeroIndex = 0, neg = 0;
  for(int i = num.size() - 1; i >= 0; i--) {
    if(num[i] != '0') break;
    zeroIndex++;
  }

  if(num[0] == '-') neg = 1;
  
  reverse(num.begin() + neg, num.end() - zeroIndex);
  return num;
}


int main(int argc, char const *argv[])
{
  int N;
  string temp;
  cin >> N;
  while(N--) {
    cin >> temp;
    cout << reverse(temp) << endl;
  }
  return 0;
}
