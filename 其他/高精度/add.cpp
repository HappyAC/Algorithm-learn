#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXSIZE = 1000;

string add (string a, string b) {
	string ans;
	int na[MAXSIZE] = {0}, nb[MAXSIZE] = {0};
	int la = a.size(), lb = b.size();
	
	for (int i = 0; i < la; i++) na[la-i-1] = a[i] - '0';
	for (int i = 0; i < lb; i++) nb[lb-i-1] = b[i] - '0';
	
	int lmax = la > lb ? la:lb;
	
	for (int i = 0; i < lmax; i++) {
		na[i] += nb[i];
		na[i+1] += na[i] / 10;
		na[i] %= 10;
	}
	
	if(na[lmax]) lmax++;
	
	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';
	
	return ans;
}


int main() {
	string a, b;
	while(cin >> a >> b) {
		cout << add(a, b) << endl;
	}
	return 0;
} 
