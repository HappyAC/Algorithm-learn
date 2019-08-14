#include <iostream>
#include <string>
#include <cmath>

using namespace std;


//大数减法
string sub(string num1, string num2) {
  int t1, t2, carry = 0, max_len, min_len, tmp_sub;
	string ts, res = "";

	if (num2.size() > num1.size()){
		string temp = num2;
		num2 = num1;
		num1 = temp;
	}
	max_len = num1.size();
	min_len = num2.size();
  while(max_len && min_len) {
    t1 = num1[max_len - 1] - '0' + carry;  //被减数
    t2 = num2[min_len - 1] - '0';  //减数
    carry = 0;
    if(t1 < t2 && (max_len - 1) > 0) { //如果被减数小于减数 并且可以借位
      t1 += 10;
      carry = -1;
    }

    tmp_sub = t1 - t2;
    ts      = '0' + abs(tmp_sub);
    if(tmp_sub < 0)
      ts = "-" + ts;

    res = ts + res;

    max_len--;
    min_len--;
  }
  while( max_len ) {
    t1  = num1[max_len - 1] - '0' + carry;
    tmp_sub = t1;
    ts  = '0' + tmp_sub;
    carry = 0;
    res = ts + res;

    max_len --;
  }
  while(res[0] == '0') res = res.substr(1);
  return res;
}

int main () {
	string num1, num2;
  while(cin>> num1 >> num2) {
    cout << sub(num1, num2) << endl;
  }
	return 0;
}
