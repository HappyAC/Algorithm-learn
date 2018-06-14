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

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> sIn;
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
        	//cout << out[outIndex] << " out" << endl;
        	sIn.pop();
        	outIndex++;
    	}
        if(sIn.size() == 0 || sIn.top() != popV[outIndex]) {
            sIn.push(pushV[inIndex]);
            //cout << in[inIndex] << " in" << endl;
        }
    }
    
    while(sIn.size() != 0) {
    	if(sIn.top() != popV[outIndex]) break;
    	//cout << out[outIndex] << " out" << endl;
    	sIn.pop();
    	outIndex++;
	}
    
    return outIndex == c;
}

int main() {
    stack<int> sIn;
    int     T
    	, 	c
    	,	tmp
        ,   inIndex
        ,   outIndex
        ;
    vector<int> 	in
    			,	out
    			;
    cin >> T;
    while(T--) {
    	cin >> c;
    	for(int i = 0; i < c; i++) {
    		cin >> tmp;
    		in.push_back(tmp);
		}
		for(int i = 0; i < c; i++) {
    		cin >> tmp;
    		out.push_back(tmp);
		}
        if(IsPopOrder(in, out)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
