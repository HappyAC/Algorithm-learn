#include <iostream> 
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string bigNumAdd(string a, string b) {
	string s;
	char carry = '0';
	string result = "";
	int temp, c;
	if(a.size() > b.size()) {
		s.assign(a.size() - b.size(), '0');
		b = s + b;
	} else if(a.size() < b.size()) {
		s.assign(b.size() - a.size(), '0');
		a = s + a;
	}
	for(int i = a.size() - 1; i >= 0; i--) {
		temp = (int)(a[i] - '0') + (int)(b[i] - '0') + (int)(carry - '0');
		carry = '0';
		if(temp > 9) {
			carry = '1';
			temp %= 10;
		}
		result = (char)('0' + temp) + result;
	}
	if(carry == '1')
		result = "1" + result;
	return result;
}

int main() {
	int n;
	string a, b;
	cin >> n;
	int i = 1;
	while(cin >> a >> b) {
		if(i != 1) cout << endl;
		cout << "Case " << i++ << ":"  << endl;
		cout << a << " + " << b << " = " << bigNumAdd(a, b) << endl;
	}
  return 0;
}
