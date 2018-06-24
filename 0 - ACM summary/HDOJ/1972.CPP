#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <list>
#include <stack>
#include <vector>
#include <queue>

using namespace std;


struct job
{
    int prio;
    bool isCur;
};


bool hasMorePrio(queue<job> q) {
    job f = q.front();
    q.pop();
    while(!q.empty()) {
        job ff = q.front();
        q.pop();
        if(ff.prio > f.prio) return true;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    int T, N, M, tmp, cost;
    vector<job> lst;
    queue<job> que;
    cin >> T;
    while(T--) {
        cost = 0;
        lst.clear();
        while(!que.empty()) que.pop();

        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            job tmpJob;
            cin >> tmpJob.prio;
            if(i == M)
                tmpJob.isCur = true;
            else
                tmpJob.isCur = false;
            lst.push_back(tmpJob);
        }

        for(int i = 0; i < N; i++) {
            job tmp = lst[i];
            // cout << tmp.prio << " " << tmp.isCur << endl;
            que.push(tmp);
        }

        while(1) {
            job tmp = que.front();
            if(hasMorePrio(que)) {
                //有更大优先级的 将当前的放在队列最后
                // cout << "cur: " << tmp.prio << endl;
                // cout << "has more" << endl;
                que.pop();
                que.push(tmp);
            } else {
                //无更大优先级的 print it
                // cout << "cur: " << tmp.prio << endl;
                // cout << "has no more" << endl;
                cost++;
                que.pop();
                // cout << "print " << tmp.prio << endl;
                //cout << "is cur" << tmp.isCur << endl;
                if(tmp.isCur) break;
            }
        }
        cout << cost << endl;
    }
    return 0;
}
