#include <iostream>
#include <string>

using namespace std;

string add(string num1, string num2) {
  int t1, t2, carry = 0, max_len, min_len, sum;
	string ts, res = "";

	if (num2.size() > num1.size()){
		string temp = num2;
		num2 = num1;
		num1 = temp;
	}
	max_len = num1.size();
	min_len = num2.size();
	while ( max_len && min_len ) {
		t1 = num1[max_len-1] - '0';
		t2 = num2[min_len-1] - '0';
		sum = t1 + t2 + carry;
		carry = sum/10;
		sum %= 10;
		ts = sum + '0';
		res = ts + res;

		max_len--;
		min_len--;
	}
	while( max_len ){
		t1 = num1[max_len-1] - '0';
		sum = t1 + carry;
		carry = sum/10;
		sum %= 10;
		ts = sum + '0';
		res = ts + res;

		max_len--;
	}
	if ( carry )
		res = "1" + res;
    
    return res;
}

int main () {
	string num1, num2;
	cin>> num1 >> num2;
	cout << add(num1, num2) << endl;
	return 0;
}
