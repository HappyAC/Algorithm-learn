#include <iostream>
#include <cmath>

using namespace std;


int main() {
	string s;
	string left, right;
	int half, len;
	bool flag;
	while(cin >> s) {
		flag = true;
		if(s.size() % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}
		len = s.size();
		half = len / 2;
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != s[(i + half) % len]) {
				flag = false;
				break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
