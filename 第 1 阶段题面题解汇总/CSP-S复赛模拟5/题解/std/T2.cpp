#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 inf = 4'000'000'000'000'000'000LL;
struct Route {
    i64 x, y;
    std::vector<int> a;
    std::vector<i64> d;
};
i64 key(int x, int y) {
    if (x > y) std::swap(x, y);
    return i64(x) << 32 | unsigned(y);
}
i64 get(i64 t, i64 d, i64 x, i64 y) {
    t -= d;
    if (t <= x) return x;
    return x + (t - x + y - 1) / y * y;
}
int main() {
    if (FILE *f = fopen("route.in", "r")) {
        fclose(f);
        freopen("route.in", "r", stdin);
        freopen("route.out", "w", stdout);
    }
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, s, k;
    i64 t;
    std::cin >> n >> m >> s >> k >> t;
    std::unordered_map<i64, i64> w;
    w.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 c;
        std::cin >> u >> v >> c;
        w[key(u, v)] = c;
    }
    std::vector<Route> r(s);
    for (auto &[x, y, a, d] : r) {
        int l;
        std::cin >> l >> x >> y;
        a.resize(l);
        d.resize(l);
        for (auto &v : a) std::cin >> v;
        for (int i = 1; i < l; i++) d[i] = d[i - 1] + w[key(a[i - 1], a[i])];
    }
    std::vector<i64> f(n + 1, inf), g(n + 1);
    f[1] = t;
    i64 ans = inf;
    for (int z = 0; z <= k; z++) {
        std::fill(g.begin(), g.end(), inf);
        for (auto &[x, y, a, d] : r) {
            i64 best = inf;
            for (int i = 0; i < (int)a.size(); i++) {
                if (best < inf) g[a[i]] = std::min(g[a[i]], best + d[i]);
                if (f[a[i]] < inf) best = std::min(best, get(f[a[i]], d[i], x, y));
            }
        }
        ans = std::min(ans, g[n]);
        f.swap(g);
    }
    if (ans == inf) std::cout << "FAIL\n";
    else std::cout << ans << '\n';
    return 0;
}
