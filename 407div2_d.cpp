#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>

typedef long long ll;

using namespace std;

struct edge {
    int x, y;
};

int deg[1000009] = {0};
edge edges[1000009];

int p[1000006];
int vis[1000006] = {0};
int n, m;

int getf(int x) {
    return x == p[x] ? x : (p[x] = getf(p[x]));
}

void _union(int x, int y) {
    x = getf(x), y = getf(y);
    p[x] = y;
}

bool connect() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        _union(edges[i].x, edges[i].y);
    }
    set<int> bag;
    for (int i = 0; i < n; i++) {
        if (!vis[i])continue;
        bag.insert(getf(i));
    }
    return bag.size() <= 1;
}

ll loops = 0;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        edges[i].x = x;
        edges[i].y = y;
        vis[x] = 1;
        vis[y] = 1;
        if (x == y) {
            loops++;
        } else {
            deg[x]++;
            deg[y]++;
        }
    }
    if (!connect()) {
        printf("0\n");
        return 0;
    }
    ll cnt = 0;
    cnt += loops * (m - loops);
    cnt += loops * (loops - 1) / 2;
    for (int i = 0; i < n; i++) {
        cnt += (ll) (deg[i]) * (deg[i] - 1) / 2;
    }
    printf("%I64d", cnt);
}