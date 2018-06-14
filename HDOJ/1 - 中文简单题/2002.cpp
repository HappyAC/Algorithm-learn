#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double    x1
          , y1
          , x2
          , y2
          , res;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
  	while(cin >> x1 >> y1 >> x2 >> y2){
  	
    	cout << setprecision(2) << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << endl;
  	}
	return 0;
} 
