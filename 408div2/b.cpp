#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <unordered_set>

typedef long long ll;

using namespace std;


int n, m, k;
unordered_set<int> s;


int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);
        s.insert(tmp);
    }
    int current = 1;
    for (int i = 0; i < k; i++) {
        if (s.find(current) != s.end()) {
            printf("%d\n", current);
            return 0;
        }
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == current) {
            current = y;
        } else if (y == current) {
            current = x;
        }

    }
    printf("%d\n", current);
}