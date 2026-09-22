#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> p, siz;

    DSU(int n) : p(n), siz(n, 1) {
        std::iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        p[y] = x;
        siz[x] += siz[y];
    }
};

int main() {
    std::freopen("starmatch.in", "r", stdin);
    std::freopen("starmatch.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int m = 2 * n + 1;
    int N = 2 * m;

    std::vector<int> u(m), v(m), deg(N);
    std::vector<std::vector<std::pair<int, int>>> adj(N);

    DSU dsu(N);

    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;

        u[i] = x;
        v[i] = m + y;

        adj[u[i]].push_back({v[i], i});
        adj[v[i]].push_back({u[i], i});

        deg[u[i]]++;
        deg[v[i]]++;

        dsu.merge(u[i], v[i]);
    }

    std::vector<int> ecnt(N);
    for (int i = 0; i < m; i++) {
        ecnt[dsu.find(u[i])]++;
    }

    int odd = -1;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i && ecnt[i] % 2) {
            odd = i;
            cnt++;
        }
    }

    std::string ans(m, '0');

    if (cnt != 1) {
        std::cout << ans << '\n';
        return 0;
    }

    std::vector<int> dfn(N), low(N);
    std::vector<i64> sub(N);
    std::vector<bool> bridge(m), ok(m);

    int cur = 0;

    auto dfs = [&](auto &&self, int x, int pe) -> void {
        dfn[x] = low[x] = ++cur;
        sub[x] = deg[x];

        for (auto [y, id] : adj[x]) {
            if (id == pe) {
                continue;
            }

            if (!dfn[y]) {
                self(self, y, id);

                sub[x] += sub[y];
                low[x] = std::min(low[x], low[y]);

                if (low[y] > dfn[x]) {
                    bridge[id] = true;

                    i64 e = (sub[y] - 1) / 2;
                    if (e % 2 == 0) {
                        ok[id] = true;
                    }
                }
            } else {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
    };

    for (int i = 0; i < N; i++) {
        if (deg[i] && !dfn[i]) {
            dfs(dfs, i, -1);
        }
    }

    for (int i = 0; i < m; i++) {
        if (dsu.find(u[i]) != odd) {
            continue;
        }

        if (!bridge[i] || ok[i]) {
            ans[i] = '1';
        }
    }

    std::cout << ans << '\n';

    return 0;
}