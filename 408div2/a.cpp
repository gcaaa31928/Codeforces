#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>

typedef long long ll;

using namespace std;


int n, m, l;
int a[105];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &l);
    m--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = 1; j < n; j++) {
        if (m + j < n && a[m + j] != 0 && a[m + j] <= l) {
            printf("%d\n", j * 10);
            return 0;
        }
        if (m - j >= 0 && a[m - j] != 0 && a[m - j] <= l) {
            printf("%d\n", j * 10);
            return 0;
        }
    }
}