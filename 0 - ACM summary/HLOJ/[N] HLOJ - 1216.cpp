#include <iostream>
// #include <algorithm>
// #include <string>
// #include <cmath>
// #include <iomanip>
// #include <map>
// #include <list>
// #include <stack>
// #include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    int T, n, tmp, sum;
    vector<int> A, B;
    scanf("%d", &T);
    while (T--)
    {
        sum = 0;
        scanf("%d", &n);
        A.clear();
        B.clear();

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            A.push_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            B.push_back(tmp);
        }

        
        vector<int>::iterator itA;
        vector<int>::iterator itB;
        int now = 1; // 1 A  0 B
        bool changeFlag = false;
        itA = A.begin();
        itB = B.begin();
        while(1) {
            if(itA == A.begin()) {
                if(*itA > *itB) {
                    now = 1;
                    sum += *itA;
                    cout << *itA << endl;
                } else {
                    now = 0;
                    sum += *itB;
                    cout << *itB << endl;
                }
                itA++, itB++;
                continue;
            }
            
            if(itA == A.end()) {
                cout << "end" << endl;
                cout << *itA << endl;
                cout << *itB << endl;
                break;
            }
            if(now == 1) {
                //比较A + A+1 与 (B + 1)
                if(*itA + *(itA + 1) >= *(itB + 1)) {
                    //不换车
                } else {
                    //换车
                    changeFlag = true;
                }
            } else {
                //比较A 与 B + (B + 1)
                if(*itB + *(itB + 1) >= *(itA + 1)) {
                    //不换车
                } else {
                    //换车
                    changeFlag = true;
                }
            }
            if(changeFlag) {
                if(now == 1) {
                    now = 0;
                } else {
                    now = 1;
                }
                changeFlag = false;
                itA++, itB++;
                cout << "change" << endl;
            }
            if(now == 1) {
                sum += *itA;
                cout << *itA << endl;
            } else {
                sum += *itB;
                cout << *itB << endl;
            }
            itA++, itB++;
        }
        cout << sum << endl;
    }
    return 0;
}
