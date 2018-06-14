#include <iostream>
using namespace std;

int main() {
	
	int  a
      ,n
      ,sum
      ,m;
  cin >> m;
	while(m--) {
    cin >> n;
    sum = 0;
    while(n--) {
      cin >> a;
      sum += a;
    }
    if(m == 0) cout << sum << endl;
		else cout << sum << endl << endl;
	}
	return 0;
} 
