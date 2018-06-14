/**
解法1： 邻接矩阵
N： 总station数  <= 500   【使用邻接矩阵】
1. 寻找最短路径
2. 计算携带的最少车辆数
3. 计算返回时带回的车辆数

无向图， 带权重
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream> //用户类型转换

#define INF 9999999

using namespace std;

const int MAX_CITY = 200;

int         cost[MAX_CITY][MAX_CITY]              //所有路径
, HAPPY[MAX_CITY]                                 //所有城市的幸福值
, d[MAX_CITY]                                     //从某点到其他所有点的距离
, h[MAX_CITY]																			//从某点到其他点能够收获的happiness
, t[MAX_CITY]																			//从某点到其他点相同最短路径个数
, n[MAX_CITY]																			//从某点到其他点经过的点的个数
, city_num                                        //城市数量
, road_num                                        //道路数量
, ROM_ID										  										//ROM城市的id
, start_id = 0                                    //开始的城市id
;

bool        used[MAX_CITY]                        //是否查找过该顶点
;

string      CITYS[MAX_CITY]                       //所有城市
, p[MAX_CITY]																			//从某点到其他点的路径
, start_city                                      //开始的城市名
;

string int2string(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

//根据城市名字获取城市id
int getIdByName(string cityName) {
	int i;
	for (i = 0; i < city_num; i++)
		if (CITYS[i] == cityName) break;
	return i;
}

void Dijkstra() {
	d[0] = 0;                                       //起点的距离是确定的
	h[0] = 0;
	p[0] = start_city;
	n[0] = 0;
	t[0] = 1;

	while (true) {
		int v = -1;
		//从没有使用过的顶点中选择一个距离最小的点
		for (int i = 0; i < city_num; i++) {
			if (!used[i] && (v == -1 || d[i] < d[v]))
				v = i;
		}

		if (v == -1) break;
		used[v] = true;

		for (int i = 0; i < city_num; i++) {
			if (i == v) continue;

			if (d[i] > d[v] + cost[i][v]) {
				d[i] = d[v] + cost[i][v];
				h[i] = h[v] + HAPPY[i];
				n[i] = n[v] + 1;
				p[i] = p[v] + "->" + CITYS[i];
				t[i] = t[v];
			}
			else if (d[i] == d[v] + cost[i][v] && d[i] != INF) {
				t[i] = t[i] + t[v];
				if (h[i] < h[v] + HAPPY[i]) {  //选取happiness max
					d[i] = d[v] + cost[i][v];
					h[i] = h[v] + HAPPY[i];
					n[i] = n[v] + 1;
					p[i] = p[v] + "->" + CITYS[i];
				}
				else if (h[i] == h[v] + HAPPY[i]
					&& (h[i] / n[i]) < (h[v] + HAPPY[i]) / (n[i] + 1)) { //happiness 相同 average max
					d[i] = d[v] + cost[i][v];958
					h[i] = h[v] + HAPPY[i];
					n[i] = n[v] + 1;
					p[i] = p[v] + "->" + CITYS[i];
				}
			}
		}
	}
}

//初始化各数组
void init() {
	//fill
	for (int i = 0; i < city_num; i++) {
		fill(cost[i], cost[i] + city_num, INF);
	}
	fill(HAPPY, HAPPY + city_num, 0);
	fill(d, d + city_num, INF);
	fill(used, used + city_num, false);
	fill(h, h + city_num, 0);
	fill(t, t + city_num, 0);
	fill(n, n + city_num, 0);
	fill(p, p + city_num, "");
	CITYS[0] = start_city;
}

void input() {
	cin >> city_num >> road_num >> start_city;
	init();

	for (int i = 1; i < city_num; i++) {
		cin >> CITYS[i] >> HAPPY[i];
	}
	ROM_ID = getIdByName("ROM");

	int   s       //from
		, t       //to
		, c    //ftom -> to cost
		;
	string    s_n     //from name
		, t_n     //to name
		;
	for (int i = 0; i < road_num; i++) {
		cin >> s_n >> t_n >> c;
		s = getIdByName(s_n);
		t = getIdByName(t_n);
		cost[s][t] = c;
		cost[t][s] = c;
	}
}

/**
*
*
*	MAIN
*
*
*/
int main() {

	input();
	Dijkstra();

	cout << t[ROM_ID] << " " << d[ROM_ID] << " " << h[ROM_ID] << " " << h[ROM_ID] / n[ROM_ID] << endl;
	cout << p[ROM_ID] << endl;

	system("pause");
	return 0;
}
