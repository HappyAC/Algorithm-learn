#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>

using namespace std;


int main() {
    int     T
        ,   insNum
        , 	tmp
        , 	n
        ,	MAX_LEN = 100
        ;
    bool insFlag;
    list<int> l;

    cin >> T;

    while(T--) {
    	l.clear();
    	cin >> n;
    	insFlag = false;
    	while(n--) {
    		cin >> tmp;
    		l.push_back(tmp);
		}
		cin >> insNum;
		
		list<int>::iterator it;
		for(it = l.begin(); it != l.end(); it++) {
			if(insNum < *it) {
				insFlag = true;
				it = l.insert(it, insNum);
				break;
			}
		}
		if(!insFlag) l.push_back(insNum);
		for(it = l.begin(); it != l.end(); it++) {
			if(it != l.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
    }
}


















