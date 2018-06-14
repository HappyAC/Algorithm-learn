#include <iostream> 
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;


string int2str(int n) {
	int a = 10, t;
	string s = "";
	while(n) {
		t = n % a;
		s = (char)('0' + t) + s;
		n /= 10;
	}
	return s;
}

int char2int(char a) {
	return (int)(a - '0');
}


int main() {
	int T;
	int a, b, d, n, res, test;
	string aa, sum, _test;
	char dd;
	cin >> T;
	while(T--) {
		res = 0;
		cin >> a >> b >> d >> n;
		if(n < 4) {
			int _s = 0;
			int ten = 1;
			for(int i = 0; i < n; i++) {
				_s += ten * a;
				ten *= 10;
			}
			_s = _s * b;
			string ss = int2str(_s);
			for(int i = 0; i < ss.size(); i++) {
				if((int)(ss[i] - '0') == d) res ++;
			}
		} else if(a * b < 10) { //case 1 
			if(a*b == d) {
				cout << n << endl;
			} else {
				cout << 0 << endl;
			}
			continue;
		} else {
			test = a + a * 10 + a * 100 + a * 1000;
			test *= b;
			_test = int2str(test);
			int len = _test.size();
			if(_test[len - 2] == _test[len - 3]) { //case 2-1
				if(char2int(_test[0]) == d) res++;
				if(char2int(_test[1]) == d) res += (n + 1 - 2); //减去头尾 
				if(char2int(_test[len - 1]) == d) res++;
			} else {
				if(char2int(_test[0]) == d) res++;
				if(char2int(_test[1]) == d) res += (n + 1 - 3); //减去头1 尾2
				if(char2int(_test[len - 1]) == d) res++;
				if(char2int(_test[len - 2]) == d) res++;
			}
		}
		cout << res << endl;
	}
  return 0;
}

