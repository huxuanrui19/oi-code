#include <bits/stdc++.h>
using i64 = long long;
struct Fenwick {
    int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x) a[x] += v;
    }
    int sum(int x) {
        int res = 0;
        for (; x; x -= x & -x) res += a[x];
        return res;
    }
};
struct FenwickMax {
    int n;
    std::vector<int> a;
    FenwickMax(int n) : n(n), a(n + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x) a[x] = std::max(a[x], v);
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= x & -x) res = std::max(res, a[x]);
        return res;
    }
};
int main() {
    if (FILE *f = fopen("pickup.in", "r")) {
        fclose(f);
        freopen("pickup.in", "r", stdin);
        freopen("pickup.out", "w", stdout);
    }
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }
    std::vector<int> p(q + 1), del(n + 1, q + 1);
    for (int i = 1; i <= q; i++) {
        std::cin >> p[i];
        del[a[p[i]]] = i;
    }
    std::vector<std::vector<int>> e(q + 1);
    FenwickMax mx(n);
    for (int x = 1; x <= n; x++) {
        int i = pos[x];
        int l = mx.query(n + 1 - i), r = del[x];
        if (l < r) {
            e[l].push_back(i);
            if (r <= q) e[r].push_back(-i);
            mx.add(n + 1 - i, r);
        }
    }
    Fenwick bv(n), bp(n), br(n);
    std::vector<char> vis(n + 1);
    std::set<std::pair<int, int>> s;
    auto calc = [&](int i) -> i64 {
        int x = a[i];
        int rp = i - bp.sum(i);
        int rv = x - bv.sum(x);
        return rp - rv;
    };
    i64 ans = 0;
    for (int t = 0; t <= q; t++) {
        if (t) {
            int i = p[t], x = a[i];
            if (!vis[i]) {
                auto it = s.lower_bound({x, 0});
                --it;
                ans -= br.sum(it->second) - br.sum(i);
            }
            bv.add(x, 1);
            bp.add(i, 1);
        }
        for (auto x : e[t]) {
            if (x < 0) {
                int i = -x;
                vis[i] = false;
                s.erase({a[i], i});
                br.add(i, -1);
                ans -= calc(i);
            } else {
                int i = x;
                vis[i] = true;
                s.insert({a[i], i});
                br.add(i, 1);
                ans += calc(i);
            }
        }
        if (t) std::cout << ' ';
        std::cout << ans + n - t;
    }
    std::cout << '\n';
    return 0;
}
