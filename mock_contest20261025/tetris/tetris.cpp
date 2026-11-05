#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int S = 1e6 + 5;
const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int fa[S], mn[S], c1[S], c2[S];
bool vis[S];
ll sum[S];

int find(int x) {
    int r = x;
    while (fa[r] != r) r = fa[r];
    while (fa[x] != x) {
        int y = fa[x];
        fa[x] = r;
        x = y;
    }
    return r;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[y] = x;
    c1[x] += c1[y];
    c2[x] += c2[y];
    sum[x] += sum[y];
    mn[x] = min(mn[x], mn[y]);
}

int main() {
    freopen("tetris.in", "r", stdin);
    freopen("tetris.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    int s = m * n;
    for (int i = 0; i < s; i++) {
        int x;
        cin >> x;
        fa[i] = i;
        sum[i] = mn[i] = x;
        c1[i] = 1;
    }

    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = x * n + y;
        c1[p[i]] = 0;
        c2[p[i]] = 1;
        mn[p[i]] = INF;
    }

    for (int u : p) {
        int x = u / n, y = u % n;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            merge(u, nx * n + ny);
        }
    }

    ll ans = 0;
    for (int u : p) {
        int r = find(u);
        if (vis[r]) continue;
        vis[r] = true;
        if (c1[r] < 3 * c2[r]) {
            cout << "No\n";
            return 0;
        }
        ans += sum[r];
        if (c1[r] > 3 * c2[r]) ans -= mn[r];
    }
    cout << ans << '\n';
    return 0;
}
