#include <iostream>
#include <string>
#include <algorithm>

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

int string2int(string num) {
	int sum = 0;
	for(int i = num.size() - 1; i >= 0; i--) {
		sum += num[i] - '0';
	}
	return sum;
}

string int2string(int num) {
	string res = "";
	int i;
	string t;
	while(num) {
		i = num % 10;
		t = '0' + i;
		res = t + res;
		num /= 10;
	}
	return res;
}

//大数乘法 Karatsuba乘法
string Karatsuba(string num1, string num2) {
	if(num1.size() < 4 && num2.size() < 4)
		return int2string(string2int(num1) * string2int(num2));

	int size1 = num1.size();
	int size2 = num2.size();
	int half_size = max(size1, size2) / 2;

	string a = num1.substr(0, size1 - half_size);
	string b = num1.substr(size1 - half_size);
	string c = num1.substr(0, size2 - half_size);
	string d = num2.substr(size2 - half_size);

	string z2 = Karatsuba(a, c);
	string z0 = Karatsuba(b, d);

	//z1 = karatsuba((a + b), (c + d)) - z0 - z2;
	string z1 = sub(sub(Karatsuba(add(a, b), add(c, d)), z0), z2);

	string tmp = "";
	tmp.assign("0", 2 * half_size);
	z2 += tmp;
	tmp = "";
	tmp.assign("0", half_size);
	z1 += tmp;
	return add(add(z2, z1), z0);
}

int main () {
	string num1, num2;
	cin>> num1 >> num2;
	cout << Karatsuba(num1, num2) << endl;
	return 0;
}
