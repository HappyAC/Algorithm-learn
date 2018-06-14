#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
  	int T;
  	string tel;
	cin >>T;
	while(T--) {
		cin >> tel;
		cout << "6" + tel.substr(6) << endl;
	}
  return 0;
}
