#include <iostream>
#include <stack>
#include <string>



using namespace std;



int main () {
	string line;
	stack<char> s;
	while (cin >> line) {
		for (int i = 0; i < line.size(); i++) {
			if (s.empty()) {
				s.push(line[i]);
				continue;
			}
			
			if (line[i] == ')' && s.top() == '(') {
				s.pop();
			} else if (line[i] == ']' && s.top() == '[') {
				s.pop();
			} else {
				s.push(line[i]);	
			}
		}
		
		if (s.empty()) cout << "yes" << endl;
		else {
			cout << "no" << endl;
			while (!s.empty()) s.pop();
		}
		
	}
	
	return 0;
}
