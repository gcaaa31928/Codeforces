#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <queue>
#include <climits>
#include <set>

typedef long long ll;

using namespace std;

int n;
int a[400005];
vector<int> m[500000];
multiset<int> s;


int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        m[u].push_back(v);
        m[v].push_back(u);
    }
    int minnest = INT_MAX;
    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        s.erase(s.find(a[i]));

        for (int j = 0; j < m[i].size(); j++) {
            tmp = max(tmp, a[m[i][j]] + 1);
            s.erase(s.find(a[m[i][j]]));
        }
        if (s.size() > 0) {
            multiset<int>::iterator most_max = --s.end();
            tmp = max(*(most_max) + 2, tmp);
        }
        minnest = min(minnest, tmp);
        s.insert(a[i]);
        for (int j = 0; j < m[i].size(); j++) {
            s.insert(a[m[i][j]]);
        }
    }
    printf("%d\n", minnest);
}