#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_set>

using namespace std;

unordered_set<long long> s;

int main() {
//    freopen("input.txt", "r", stdin);
    long long b, q, l, m;
    scanf("%I64d%I64d%I64d%I64d", &b, &q, &l, &m);
    for (int i = 0; i < m; i++) {
        long long tmp;
        scanf("%I64d", &tmp);
        s.insert(tmp);
    }
    if (abs(b) > l) {
        printf("0\n");
        return 0;
    }
    if (b == 0) {
        if (s.find(0) != s.end()) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }
    if (q == 0) {
        if (s.find(0) != s.end()) {
            if (s.find(b) != s.end())
                printf("0\n");
            else
                printf("1\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }
    if (q == 1) {
        if (s.find(b) != s.end()) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    } else if (q == -1) {
        if (s.find(b) != s.end() && s.find(-b) != s.end()) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }
    int cnt = 0;
    for (; abs(b) <= l; b *= q) {
        if (s.find(b) != s.end()) {
            continue;
        }
        cnt++;
    }
    printf("%d\n", cnt);

}