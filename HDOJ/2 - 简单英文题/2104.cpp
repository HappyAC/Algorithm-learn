#include <iostream>
#include <algorithm>

using namespace std;


int main() {
  int   T
      , sum = 0
      , M
      , N
      , gender
      , punish = 1
      , num
      ;
  cin >> T;
  while(T--) {
    sum = 0, num = 0, punish = 1;
    cin >> M >> N;
    while(N--) {
       cin >> gender;
       if(gender == 1) {
         num = max(M, num + 1);
       } else {
         num++;
       }
       //cout << num << endl;
       if(num > M) {
         sum += punish;
         punish *= 2;
       }
    }
    if(sum != 0) 
    	cout << sum <<"0000 RMB" << endl;
    else
    	cout <<"0 RMB" << endl;
  }
  return 0;
}
