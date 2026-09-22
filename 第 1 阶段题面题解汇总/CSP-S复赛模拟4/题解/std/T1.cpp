#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 inf = 1LL << 60;
int main() {
	freopen("signpost.in","r",stdin);
	freopen("signpost.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m, n;
    std::cin >> m >> n;
    int N = n * m;
    std::vector<int> a(N);
    std::vector<std::vector<int>> p(90001);
    int V = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        p[a[i]].push_back(i);
        V = std::max(V, a[i]);
    }
    std::vector<i64> mn(N, inf), mx(N, inf);
    for (auto x : p[0]) mn[x] = mx[x] = 0;
    constexpr int dx[] = {-1, 1, 0, 0};
    constexpr int dy[] = {0, 0, -1, 1};
    for (int v = 1; v <= V; v++) {
        for (auto x : p[v]) {
            int i = x / m, j = x % m;
            i64 res = inf;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                int y = ni * m + nj;
                if (a[y] < v) res = std::min(res, mx[y]);
            }
            if (res < inf) mn[x] = res + v;
        }
        for (auto x : p[v]) {
            int i = x / m, j = x % m;
            i64 res = -1;
            bool bad = false;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                int y = ni * m + nj;
                if (a[y] <= v) {
                    if (mn[y] == inf) bad = true;
                    else res = std::max(res, mn[y]);
                }
            }
            if (!bad && res != -1) mx[x] = res + v;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            i64 x = mn[i * m + j];
            std::cout << (x == inf ? -1 : x) << " \n"[j == m - 1];
        }
    }
    return 0;
}
