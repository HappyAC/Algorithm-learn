#include <iostream>
using namespace std;


int sum (int n) {
	int sum = 0;
  if(n % 2 == 0)
	while(n) {
		sum += n;
		n--;
	}
	return sum;
}

int sum_math(int n) {
  if(n % 2 == 0)
    return (n / 2) * (n + 1);

  return n * ((n + 1) / 2);
}

int main() {
	
	int n;
	while(cin >> n) {
		cout << sum_math(n) << endl << endl;
	}
	return 0;
} 
