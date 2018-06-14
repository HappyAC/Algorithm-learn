#include <iostream> 
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string getSum(int i, int zn) {
	int a = 1;
	string sum;
	string z;
	z.assign(zn, '0');
	sum.assign(i, '5');
	
	return sum + z;
}

int main() {
	int n, f, res;
	int sum_f = 0, sum_z = 0;
	string r;
	bool flag = false;
	while(cin >> n) {
		res = 0;
		sum_f = 0, sum_z = 0;
		while(n--) {
			cin >> f;
			if(f == 5) sum_f++;
			else sum_z++;
			
		}
		if(sum_z == 0) {
			cout << "-1" << endl;
			continue;
		}
		if(sum_f < 9){
			cout << "0" << endl;
			continue;
		}
		int count = sum_f / 9;
		count *= 9;
		
		r = getSum(count, sum_z);
		cout << r << endl;
	}
	
}

