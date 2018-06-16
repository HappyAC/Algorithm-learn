#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

int char2int(char a) {
    return (int)(a - '0');
}

void IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> sIn;
    vector<string> res;
    int     c
        ,   tmp
        ,   in[10]
        ,   out[10]
        ,   inIndex
        ,   outIndex
        ;
    c = pushV.size();
    inIndex = 0, outIndex = 0;
    for(; inIndex < c; inIndex++) {
    	while(sIn.size() != 0) {
        	if(sIn.top() != popV[outIndex]) break;
            res.push_back("out");
        	//cout << popV[outIndex] << " out" << endl;
        	sIn.pop();
        	outIndex++;
    	}
        if(sIn.size() == 0 || sIn.top() != popV[outIndex]) {
            sIn.push(pushV[inIndex]);
            res.push_back("in");
            //cout << pushV[inIndex] << " in" << endl;
        }
    }
    
    while(sIn.size() != 0) {
    	if(sIn.top() != popV[outIndex]) break;
        res.push_back("out");
    	//cout << popV[outIndex] << " out" << endl;
    	sIn.pop();
    	outIndex++;
	}
    if(outIndex == c) {
        cout << "Yes." << endl;
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
    } else {
        cout << "No." << endl;
    }
    cout << "FINISH" << endl;
}

int main() {
    stack<int> sIn;
    int     T
    	, 	c
        ,   inIndex
        ,   outIndex
        ;
    vector<int> 	in
    			,	out
    			;
    char tmp;
    while(cin >> c) {
    	in.clear();
        out.clear();
    	for(int i = 0; i < c; i++) {
    		cin >> tmp;
    		in.push_back(char2int(tmp));
		}
		for(int i = 0; i < c; i++) {
    		cin >> tmp;
    		out.push_back(char2int(tmp));
		}
        IsPopOrder(in, out); 
    }
    return 0;
}
