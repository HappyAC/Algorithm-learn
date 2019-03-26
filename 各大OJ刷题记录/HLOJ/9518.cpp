#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

string int2str(int num);
int str2int(string snum);
stack<double> push(stack<double> s, string word);
double calc(double a, double b, char method);


double calc(double a, double b, char method) {
	// cout << b << method << a << endl;
	double res;
	switch (method) {
	case '+':
		res = (b) + (a);
		break;
	case '-':
		res = (b) - (a);
		break;
	case '*':
		res = (b) * (a);
		break;
	case '/':
		res = (b) / (a);
		break;
	}

	return res;
}

stack<double> push(stack<double> s, string word) {
	if (word == "+" || word == "-" || word == "*" || word == "/") {
		double a = s.top();
		s.pop();
		double b = s.top();
		s.pop();


		s.push(calc(a, b, word[0]));
	}
	else {
		s.push(str2int(word));
	}
	return s;
}

int str2int(string snum) {
	int sum = 0;
	int step = 1;
	for (int i = snum.size() - 1; i >= 0; i--) {
		sum += step * int(snum[i] - '0');
		step *= 10;
	}

	return sum;
}

string int2str(int num) {
	string snum;
	int anum;
	while (num) {
		anum = num % 10;
		snum = char('0' + anum) + snum;
		num /= 10;
	}

	return snum;
}

int main() {
	string line;
	string tmp = "";
	stack<double> s;
	double res;
	while (cin >> tmp) {
		if (tmp == "$") {
			res = s.top();
			cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;

			while (!s.empty()) s.pop();
		}
		s = push(s, tmp);
	}
	return 0;
}


