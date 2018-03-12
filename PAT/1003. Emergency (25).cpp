#include <iostream>
#include <vector>
/**
Sample Input
5 6 0 2     (有几个城市, 共有几条路, 你当前在哪个城市, 你要去救援哪个城市)
1 2 1 5 3   (城市从0开始，每个城市里的救援队有几人)
0 1 1       (从城市0到城市1距离为1)
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4     (2条最短路径,最多能聚集4个人)

*/
using namespace std;

struct Dis {
    int cityID;
    int dis;
}

struct Term {
    int cityID;
    int num;
}

/**
* 寻找出最短的路
*
* @return int[][] 二维数组，存放若干条路径
*/
vector<vector<Term>> findShortestWay(vector<vector<Dis>>, int start, int end);

int main() {
    int cityNums, roadNums, currentCity, savedCity;
    cin >> cityNums >> roadNums >> currentCity >> savedCity;
    //创建邻接链表来表示无向图
    vector<vector<Dis>> map;
    int i, j;
    int cityTerm[cityNums]; //用来表示城市里救援队伍人数
    for(i = 0; i < cityNums; i++) {
        cin >> cityTerm[i];
        vector<Dis> city;
        map.push_back(city);
    }
    //读取路
    int start, end, distance;
    while(roadNums--) {
        cin >> start >> end >> distance;

        Dis d = new Dis();
        d.cityID = end;
        d.dis = distance;

        map[i].push_back(d);
    }
    return 0;
}

vector<vector<Term>> findShortestWay(vector<vector<Dis>>, int start, int end) {
    vector<vector<Term>> result;

    
}
