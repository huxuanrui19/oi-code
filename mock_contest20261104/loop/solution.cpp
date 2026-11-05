#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct Point {
    long long x, y;
};

int n, p[N], q[N], cnt[N];
long long bit[N];
Point a[N];

void add(int x, int v) {
    for (; x <= n; x += x & -x) bit[x] += v;
}

long long sum(int x) {
    long long res = 0;
    for (; x; x -= x & -x) res += bit[x];
    return res;
}

int main() {
    freopen("loop.in", "r", stdin);
    freopen("loop.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long len;
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        p[i] = i;
    }

    sort(a + 1, a + n + 1, [](Point u, Point v) {
        return u.x < v.x;
    });
    sort(p + 1, p + n + 1, [](int i, int j) {
        return a[i].y < a[j].y;
    });

    long long contain = 0, dif = 0;
    int pos = 0;
    for (int i = n; i >= 1; i--) {
        contain += sum(p[i]);
        add(p[i], 1);
        q[p[i]] = i;
        if (p[i] > i) {
            pos++;
            dif += 2 * (p[i] - i);
            cnt[p[i] - i]++;
        }
    }

    long long ans = contain - dif + 1LL * pos * (n - pos);
    for (int t = 1; t <= n; t++) {
        ans = min(ans, contain - dif + 1LL * pos * (n - pos));

        dif -= 2LL * pos;
        pos -= cnt[t];
        int i = q[t];
        contain += n - 2 * i + 1;
        if (i < n) {
            pos++;
            dif += 2 * (n - i);
            cnt[n - i + t]++;
        }
    }
    cout << ans << '\n';
    return 0;
}
