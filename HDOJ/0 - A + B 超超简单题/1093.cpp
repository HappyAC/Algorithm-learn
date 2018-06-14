#include <iostream>
using namespace std;

int main() {
	
	int  n
      , m
      , a
			,sum
      ;
  cin >> n;
	while(n--) {
    cin >> m;
    sum = 0;
		while(m--) {
      cin >> a;
      sum += a;
    }
    cout << sum << endl;
	}
	return 0;
} 
