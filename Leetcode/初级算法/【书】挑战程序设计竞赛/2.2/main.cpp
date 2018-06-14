/**
�ⷨ1�� �ڽӾ���
N�� ��station��  <= 500   ��ʹ���ڽӾ���
1. Ѱ�����·��
2. ����Я�������ٳ�����
3. ���㷵��ʱ���صĳ�����

����ͼ�� ��Ȩ��
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream> //�û�����ת��

#define INF 9999999

using namespace std;

const int MAX_CITY = 200;

int         cost[MAX_CITY][MAX_CITY]              //����·��
, HAPPY[MAX_CITY]                                 //���г��е��Ҹ�ֵ
, d[MAX_CITY]                                     //��ĳ�㵽�������е�ľ���
, h[MAX_CITY]																			//��ĳ�㵽�������ܹ��ջ��happiness
, t[MAX_CITY]																			//��ĳ�㵽��������ͬ���·������
, n[MAX_CITY]																			//��ĳ�㵽�����㾭���ĵ�ĸ���
, city_num                                        //��������
, road_num                                        //��·����
, ROM_ID										  										//ROM���е�id
, start_id = 0                                    //��ʼ�ĳ���id
;

bool        used[MAX_CITY]                        //�Ƿ���ҹ��ö���
;

string      CITYS[MAX_CITY]                       //���г���
, p[MAX_CITY]																			//��ĳ�㵽�������·��
, start_city                                      //��ʼ�ĳ�����
;

string int2string(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

//���ݳ������ֻ�ȡ����id
int getIdByName(string cityName) {
	int i;
	for (i = 0; i < city_num; i++)
		if (CITYS[i] == cityName) break;
	return i;
}

void Dijkstra() {
	d[0] = 0;                                       //���ľ�����ȷ����
	h[0] = 0;
	p[0] = start_city;
	n[0] = 0;
	t[0] = 1;

	while (true) {
		int v = -1;
		//��û��ʹ�ù��Ķ�����ѡ��һ��������С�ĵ�
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
				if (h[i] < h[v] + HAPPY[i]) {  //ѡȡhappiness max
					d[i] = d[v] + cost[i][v];
					h[i] = h[v] + HAPPY[i];
					n[i] = n[v] + 1;
					p[i] = p[v] + "->" + CITYS[i];
				}
				else if (h[i] == h[v] + HAPPY[i]
					&& (h[i] / n[i]) < (h[v] + HAPPY[i]) / (n[i] + 1)) { //happiness ��ͬ average max
					d[i] = d[v] + cost[i][v];
					h[i] = h[v] + HAPPY[i];
					n[i] = n[v] + 1;
					p[i] = p[v] + "->" + CITYS[i];
				}
			}
		}
	}
}

//��ʼ��������
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
