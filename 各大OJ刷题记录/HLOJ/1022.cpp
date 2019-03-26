#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

/*
Description

把 M个同样的苹果放在 N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用 K表示）5，1，1和1，5，1 是同一种分法。
Input

第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
Output

对输入的每组数据M和N，用一行输出相应的K。
*/

/**
令 f(m, n) 为把m个苹果放在n个盘子中的分法总数
两种情况
1. 有空盘子
  即把m个苹果放在 n-1 个盘子里
2. 没有空盘子
  所有的盘子中都放一个，即把 m-n个苹果放在n个盘子里
*/

int f(int m, int n) {
  if(m < 0) return 0;
  if(n == 1 || m == 1) return 1;

  return f(m, n - 1) + f(m - n, n);
}

int main () {
  int   T
      , m
      , n
      ;
  cin >> T;
  while(T--) {
    cin >> m >> n;
    cout << f(m, n) << endl;
  }
  return 0;
}