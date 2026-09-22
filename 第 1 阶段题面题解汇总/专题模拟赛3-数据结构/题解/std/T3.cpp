#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Persistent {
    vector<int> l, r, sum;
    Persistent(int n) : l(1), r(1), sum(1) {
        l.reserve(n);
        r.reserve(n);
        sum.reserve(n);
    }
    int clone(int p) {
        l.push_back(l[p]);
        r.push_back(r[p]);
        sum.push_back(sum[p]);
        return l.size() - 1;
    }
    int add(int p, int l0, int r0, int v) {
        int x = clone(p);
        sum[x]++;
        if (l0 < r0) {
            int m = (l0 + r0) / 2;
            if (v <= m) {
                l[x] = add(l[p], l0, m, v);
            } else {
                r[x] = add(r[p], m + 1, r0, v);
            }
        }
        return x;
    }
};
i64 C2(i64 x) {
    return x * (x - 1) / 2;
}
int main() {
    freopen("relay.in", "r", stdin);
    freopen("relay.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    i64 K;
    if (!(cin >> n >> K)) {
        return 0;
    }
    vector<int> w(n + 1);
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        mx = max(mx, w[i]);
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n + 1), tin(n + 1), tout(n + 1), rev(n + 1);
    int cur = 0;
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(1, 0, 0);
    while (!stk.empty()) {
        auto [u, p, t] = stk.back();
        stk.pop_back();
        if (t == 0) {
            par[u] = p;
            tin[u] = ++cur;
            rev[cur] = u;
            stk.emplace_back(u, p, 1);
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); it++) {
                if (*it != p) {
                    stk.emplace_back(*it, u, 0);
                }
            }
        } else {
            tout[u] = cur;
        }
    }
    int m = mx + 1;
    Persistent seg(n * 22 + 5);
    vector<int> root(n + 1);
    for (int i = 1; i <= n; i++) {
        root[i] = seg.add(root[i - 1], 1, m, w[rev[i]]);
    }
    int ans = 1000000;
    vector<int> lm, rm, base;
    for (int z = 1; z <= n; z++) {
        lm.assign(1, root[0]);
        rm.assign(1, root[n]);
        base.assign(1, 0);
        for (auto y : adj[z]) {
            if (par[y] == z) {
                lm.push_back(root[tin[y] - 1]);
                rm.push_back(root[tout[y]]);
                base.push_back(0);
            }
        }
        int L = root[tin[z] - 1];
        int R = root[tout[z]];
        int inBase = 0;
        int lo = 1, hi = m;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int all = seg.sum[seg.l[rm[0]]] - seg.sum[seg.l[lm[0]]] + base[0];
            int inside = seg.sum[seg.l[R]] - seg.sum[seg.l[L]] + inBase;
            i64 load = i64(inside) * (all - inside) + C2(inside);
            for (int j = 1; j < int(lm.size()); j++) {
                int cnt = seg.sum[seg.l[rm[j]]] - seg.sum[seg.l[lm[j]]] + base[j];
                load -= C2(cnt);
            }
            if (load < K) {
                lo = mid + 1;
                inBase = inside;
                L = seg.r[L];
                R = seg.r[R];
                for (int j = 0; j < int(lm.size()); j++) {
                    base[j] += seg.sum[seg.l[rm[j]]] - seg.sum[seg.l[lm[j]]];
                    lm[j] = seg.r[lm[j]];
                    rm[j] = seg.r[rm[j]];
                }
            } else {
                hi = mid;
                L = seg.l[L];
                R = seg.l[R];
                for (int j = 0; j < int(lm.size()); j++) {
                    lm[j] = seg.l[lm[j]];
                    rm[j] = seg.l[rm[j]];
                }
            }
        }
        int t = lo - 1;
        int res = t == mx ? 1000000 : t - w[z];
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}

