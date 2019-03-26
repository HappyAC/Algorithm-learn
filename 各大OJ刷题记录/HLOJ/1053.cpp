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

int str2int(string a) {
  int c = 1, res = 0;
  for(int i = a.size() - 1; i >= 0; i--) {
    res += (int)(a[i] - '0') * c;
    c *= 10;
  }
  return res;
}
void run(vector<string> A, vector<string> B, char operation) {
  if(A.size() == 1 && A[0] == "") {
    cout << "[]" << endl;
    return;
  }
  vector<string>::iterator it, tmp;
  //cout << "OPE: " << operation << endl;
  //++
  if(operation == '+') {
    cout << "[";
    for(it = A.begin(); it != A.end(); it++) {
      if(it != A.begin()) cout << ",";
      cout << *it;
    }
    for(it = B.begin(); it != B.end(); it++) {
      cout << "," << *it;
    }
    cout << "]" << endl;
    return;
  }
  it = B.begin();
  // -- 
  while(it != B.end()) {
    for(tmp = A.begin(); tmp != A.end(); tmp++) {
      if((*tmp) == (*it)) {
        //cout << "DEL " << *it << endl;
        A.erase(tmp);
        break;
      }
    }
    it++;
  }
  cout << "[";
  for(it = A.begin(); it != A.end(); it++) {
    if(it != A.begin()) cout << ",";
    cout << *it;
  }
  cout << "]" << endl;
}



int main() {
  char leftSB, rightSB, operation, comma, tmpc;
  string tmps = "";
  int leftSBCnt = 0, rightSBCnt = 0, tmpi;
  vector<string> A, B;

  while(cin >> tmpc) {
    if(tmpc == '.') break;
    if(tmpc == '[') {
      leftSBCnt++;
      continue;
    }
    if(tmpc == ']') {
      rightSBCnt++;
      if(leftSBCnt == 1)
        A.push_back(tmps);
      else
        B.push_back(tmps);
      tmps = "";
      if(rightSBCnt == 2) {
        leftSBCnt = 0, rightSBCnt = 0;
        run(A, B, operation);
        A.clear();
        B.clear();
      }
      continue;
    }
    if(tmpc == ',') {
      //tmpc = str2int(tmps);
      if(leftSBCnt == 1)
        A.push_back(tmps);
      else
        B.push_back(tmps);
      tmps = "";
      continue;
    }
    if(tmpc == '+' || tmpc == '-') {
      operation = tmpc;
      continue;
    }
    tmps += tmpc;
  }

  return 0;
}
