#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_set>

using namespace std;

int a[100009];
int s[100008];

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        s[i] = abs(a[i] - a[i + 1]);
    }
    int f=1;
    long long res = 0, now = 0, now2 = 0;
    for (int i = 0; i < n - 1; i++) {
        int current = s[i] * f;
        int current2 = s[i] *(-f);
        now += current;
        now2 += current2;
        if (now < 0)
            now = 0;
        if(now2<0)
            now2=0;
        res = max(max(res, now), now2);
        f *= -1;
    }
    printf("%I64d\n", res);

}