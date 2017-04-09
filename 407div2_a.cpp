#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 * 20/4=5..0
 * 13/4=3..1
 */
int main() {
//    freopen("input.txt", "r", stdin);
    int n, k;
    int a[100005];
    int cnt = 0;
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n;) {
        if (a[i] <= 0) {
            i++;
            continue;
        }
        if (a[i] >= (k + k)) {
            cnt += a[i] / (k + k);
            a[i] %= (k + k);
        } else if (a[i] > k) {
            a[i]=0;
            cnt++;
        }else {
            cnt++;
            a[i]-=k;
            a[i+1]-=k;
        }
    }
    printf("%d\n", cnt);

}