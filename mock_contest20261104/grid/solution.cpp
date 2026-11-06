#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const long long inf = 1e15;

int n, m, vis[N][N];
char s[N][N];
long long lef[N][N], rig[N][N];

long long dfs(int x, int y, int type) {
    if (x < 1 || x > n || y < 1 || y > m) return 0;
    if (vis[x][y] == -1) return inf;
    if (vis[x][y] == 1) return 0;

    vis[x][y] = -1;
    long long res = 2;
    if (type == 0) {
        if (s[x][y] == 'N') {
            res += dfs(x, y - 1, 0);
            res += dfs(x + 1, y, s[x + 1][y] == 'N' ? 0 : 1);
        } else {
            res += dfs(x, y - 1, 0);
            res += dfs(x - 1, y, s[x - 1][y] == 'N' ? 1 : 0);
        }
    } else {
        if (s[x][y] == 'N') {
            res += dfs(x, y + 1, 1);
            res += dfs(x - 1, y, s[x - 1][y] == 'N' ? 1 : 0);
        } else {
            res += dfs(x, y + 1, 1);
            res += dfs(x + 1, y, s[x + 1][y] == 'N' ? 0 : 1);
        }
    }

    if (res >= inf) return inf;
    vis[x][y] = 1;
    return res;
}

int main() {
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> (s[i] + 1);

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= m; j++) {
            lef[i][j] = min(inf, lef[i][j - 1] + dfs(i, j, 0));
        }

        memset(vis, 0, sizeof(vis));
        for (int j = m; j >= 1; j--) {
            rig[i][j] = min(inf, rig[i][j + 1] + dfs(i, j, 1));
        }

        for (int j = 1; j <= m; j++) {
            long long ans = min(lef[i][j], rig[i][j]);
            if (ans >= inf) cout << -1 << ' ';
            else cout << ans << ' ';
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
