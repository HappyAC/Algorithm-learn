#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>

using namespace std;

struct Node {
    string  name;
    int     stu[12]
            , solved
            , time
            ;
};

int str2int(string s) {
	int   a = 1
		, sum = 0
		, neg = 1
		;
	if(s[0] == '-') {
		neg = -1;
		s = s.substr(1);
	}
	for(int i = s.size() - 1; i >= 0; i--) {
		sum += (int)(s[i] - '0') * a;
		a *= 10;
	}
	return sum;
}

void getSolveStu(string ss, int &sol, int &wt) {
	sol = 0, wt = 0;
	if(ss[0] == '-') {
		wt = str2int(ss);
		return;
	}
	int   s = -1
		, e = -1
		;
		
	for(int i = 0; i < ss.size(); i++) {
		if(ss[i] == '(') s = i;
		if(ss[i] == ')') e = i;
	}
	
	if(s == -1) sol = str2int(ss);
	else {
		sol = str2int(ss.substr(0, s));
		wt  = str2int(ss.substr(s + 1, e - s - 1));
	}
}


bool cmp(Node a, Node b) {
	if(a.solved != b.solved) return a.solved > b.solved; //题数大的在前 
	if(a.time != b.time) return a.time < b.time; //时间短的在前 
	return a.name < b.name; //名字字典序小的在前 
}


int main() {
	
    int   n
        , m
        , num = 0
        , wt 			//wrong time
		, costt			//cost time
        ;
    Node data[10000];
    string na;
    string qstu;
    cin >> n >> m;
    while(cin >> na) {
    	//if(na == "00") break;
        data[num].name = na;
        data[num].solved = 0;
        data[num].time	 = 0;
        for(int i = 0; i < n; i++) {
        	cin >> qstu;
        	getSolveStu(qstu, costt, wt);
        	
        	if(costt != 0) {
        		data[num].time += costt + wt * m;
        		data[num].solved++;
			}
		}
        num++;
    }
    sort(data, data + num, cmp);
    
    for(int i = 0; i < num; i++) {
    	cout<<resetiosflags(ios::right);
    	cout.setf(ios::left);
    	cout << setw(10)    << data[i].name   << " ";
    	cout.setf(ios::right);
		cout << setw(2)   << data[i].solved << " ";
		cout << setw(4)  << data[i].time   << endl;
	}
    return 0;
}


