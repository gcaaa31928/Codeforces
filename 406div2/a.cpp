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

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
//    freopen("input.txt", "r", stdin);
    int a, b, c, d;
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);
    int t = abs(b - d);
    if (d > b) {
        swap(a, c);
        swap(b, d);
    }
    if (t % gcd(a, c) != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0;; i++) {
        if (((b - d) + a * i) % c == 0) {
            printf("%d", b + a * i);
            return 0;
        }
    }

}