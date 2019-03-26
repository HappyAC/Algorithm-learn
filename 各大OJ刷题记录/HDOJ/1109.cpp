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

#define P pair<double, double>
double dis(P a, P b) {
  double xx = (a.first - b.first) * (a.first - b.first);
  double yy = (a.second - b.second) * (a.second - b.second);
  return sqrt(xx + yy);
}

void solve() {
  int T, tmpWidth, tmpHeight, tmpHoleNum;
  double longerst = -1, tmpX, tmpY;
  cin >> T;
  P res, tmp, shor;
  vector<P> holes;
  while(T--) {
    //init
    holes.clear();
    longerst = -1;


    cin >> tmpWidth >> tmpHeight >> tmpHoleNum;
    while(tmpHoleNum--) {
      cin >> tmpX >> tmpY;
      holes.push_back(P(tmpX, tmpY));
    }

    for(int x = 1; x <= tmpWidth; x++) {
      for(int y = 1; y <= tmpHeight; y++) {
        int shortest = 9999999;
        for(int i = 0; i < holes.size(); i++) {
          if(dis(P(x, y), holes[i]) < shortest) {
            //update
            shor.first = x;
            shor.second = y;
            shortest = dis(P(x, y), holes[i]);
          }
        }
        if(longerst < shortest) {
          //update
          longerst = shortest;
          res.first = shor.first;
          res.second = shor.second;
        }
      }
    }

    cout << res.first << " : " << res.second << endl;
  }

}

int main(int argc, char const *argv[])
{
  solve();
  return 0;
}
