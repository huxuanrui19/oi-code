#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int mod = 1e9 + 7;

int n, a[N], pre[N], nxt[N];
int mx[N], mn[N], bit[N];

void add_max(int x, int v) {
    for (; x < N; x += x & -x) mx[x] = max(mx[x], v);
}

int get_max(int x) {
    int res = 0;
    for (; x; x -= x & -x) res = max(res, mx[x]);
    return res;
}

void add_min(int x, int v) {
    for (; x < N; x += x & -x) mn[x] = min(mn[x], v);
}

int get_min(int x) {
    int res = n + 1;
    for (; x; x -= x & -x) res = min(res, mn[x]);
    return res;
}

void add(int x, int v) {
    if (x <= 0) return;
    for (; x <= n + 1; x += x & -x) bit[x] = (bit[x] + v) % mod;
}

int sum(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res = (res + bit[x]) % mod;
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("arrange.in", "r", stdin);
    freopen("arrange.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        pre[i] = get_max(a[i]);
        add_max(a[i], i);
    }

    fill(mn, mn + N, n + 1);
    for (int i = n; i >= 1; i--) {
        nxt[i] = get_min(a[i]);
        add_min(a[i], i);
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        // A prefix may start here exactly when a[i] is a prefix minimum.
        dp[i] = (sum(n + 1) - sum(pre[i]) + mod + (pre[i] == 0)) % mod;
        add(nxt[i], dp[i]);
    }

    int ans = 0, low = n + 1;
    for (int i = n; i >= 1; i--) {
        low = min(low, a[i]);
        if (a[i] == low) ans = (ans + dp[i]) % mod;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
