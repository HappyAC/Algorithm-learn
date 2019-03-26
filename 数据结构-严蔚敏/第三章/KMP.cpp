#include <iostream>
#include <string>
#include <vector>

/*
	KMP ģʽƥ��

ababcabcacbab
abc
*/

using namespace std;

#define MAXSIZE 100

string s, t; // ����mode
int	length;
int nextval[MAXSIZE];

void getNext(string t) {
	int i = 0;
	nextval[0] = -1;
	int j = -1;
	int tlen = t.size() - 1;

	while (i < tlen) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			if (t[i] != t[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else {
			j = nextval[j];
		}
	}
}

int index_KMP(string s, string t) {
	getNext(t);
	int i = 0, j = 0;
	int slen = s.size() - 1;
	int tlen = t.size() - 1;
	while (i <= slen && j <= tlen) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		} else {
			j = nextval[j];
		}
	}
	if (j >= tlen) return i - tlen;
	else return -1; // û�ҵ�
}



int main() {
	while (cin >> s >> t)
		cout << index_KMP(s, t) << endl;

	return 0;
}
