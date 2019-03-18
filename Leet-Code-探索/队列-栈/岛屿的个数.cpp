#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector < vector<char> > map;
	vector < vector<int> >  flag;
	int w;
	int h;
	int sum;
	
	void input () {
		sum = 0;
		cin >> w >> h;
		
		map.resize(h);
		flag.resize(h);
		for (int i = 0; i < h; i++) {
			map[i].resize(w);
			flag[i].resize(w);
		}
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
	}
	
	int numIslands() {
        // map = grid;
        for (int i = 0; i < map.size(); i++) {
        	for (int j = 0; j < map[0].size(); j++) {
        		if (map[i][j] == '0' || flag[i][j] == 1) continue;
        		
        		search(i, j);
        		sum++;
			}
		}
    }
    
    void search(int x, int y) {
    	pair<int, int> start;
    	start.first = x;
    	start.second = y;
    	queue< pair<int, int> > q;
    	q.push(start);
    	int moveX[4] = {-1, 0, 1, 0};
    	int moveY[4] = {0, -1, 0, 1};
    	pair<int, int> curPos;
    	pair<int, int> nextPos;
    	while (!q.empty()) {
    		curPos = q.front();
    		q.pop();
    		flag[curPos.first][curPos.second] = 1;
    		// cout << "cur: " << curPos.first << "," << curPos.second << endl;
			for (int i = 0; i < 4; i++) {
				//cout << "flag[0][0]=" << flag[curPos.second][curPos.first] << endl;
				nextPos.first = curPos.first + moveX[i];
				nextPos.second = curPos.second + moveY[i];
				
				if (checkPos(nextPos.first, nextPos.second)) {
					q.push(nextPos);
					// cout << "push: " << nextPos.first << "," << nextPos.second << endl;
					flag[nextPos.first][nextPos.second] = 1;
				}
			}
		}
	}
	
	bool checkPos (int x, int y) {
		// cout << "check: " << x << "," << y << endl;
		// cout << map[x][y] << endl;
		if (x < 0 || x >= h	|| y < 0 || y >= w) return false;
		if (map[x][y] == '0' || flag[x][y] == 1) {
			return false;
		}
		return true;
	}
};

int main () {
	Solution slu;
	slu.input();
	slu.numIslands();
	cout << slu.sum << endl;
	return 0;
}
