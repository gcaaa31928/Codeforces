#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <utility>


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, d;
int p[400005];
int exist[400005]={0};
int mark[400005] = {0};
vector<int> m[400005];
map<pii, int> edge;

struct Compare {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &k, &d);
    queue<pii> q;
    fill(mark, mark + n, -1);
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
        p[i]--;
        if(exist[p[i]])
            continue;
        exist[p[i]] = 1;
        q.push(pii(p[i], p[i]));
        mark[p[i]] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        m[u].push_back(v);
        m[v].push_back(u);
        edge[pii(u, v)] = i;
        edge[pii(v, u)] = i;
    }
    set<int> d_edge;
    while (!q.empty()) {
        int now = q.front().first;
        int pre = q.front().second;
//        printf("-- %d %d\n", now, pre);
        q.pop();
        for (int i = 0; i < m[now].size(); i++) {
            int to = m[now][i];
            if(to==pre)
                continue;
            if (mark[to] != -1) {
//                printf("%d %d\n", now, to);
                d_edge.insert(edge[pii(now, to)]);
            } else {
                mark[to]=1;
                q.push(pii(to, now));
            }
        }
    }


    printf("%d\n", d_edge.size());
    for (set<int>::iterator it=d_edge.begin(); it!=d_edge.end(); it++) {
        printf("%d ", (*it)+1);
    }
}