#include <bits/stdc++.h>
using i64 = long long;
struct Hub {
    int x, y;
    char t;
};
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Hub> a(k);
    std::vector<int> xs, ys;
    xs.reserve(k);
    ys.reserve(k);
    std::unordered_map<i64, int> mp;
    mp.reserve(2 * k);
    auto key = [&](int x, int y) {
        return i64(x) << 32 | y;
    };
    for (int i = 0; i < k; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].t;
        xs.push_back(a[i].x);
        ys.push_back(a[i].y);
        mp[key(a[i].x, a[i].y)] = i;
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    int X = k;
    int Y = X + xs.size();
    int N = Y + ys.size();
    std::vector<std::vector<int>> adj(N), radj(N);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    };
    constexpr int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < k; i++) {
        int x = X + std::lower_bound(xs.begin(), xs.end(), a[i].x) - xs.begin();
        int y = Y + std::lower_bound(ys.begin(), ys.end(), a[i].y) - ys.begin();
        add(x, i);
        add(y, i);
        if (a[i].t == 'B') {
            add(i, x);
        } else if (a[i].t == 'C') {
            add(i, y);
        } else {
            for (int d = 0; d < 8; d++) {
                int nx = a[i].x + dx[d];
                int ny = a[i].y + dy[d];
                auto it = mp.find(key(nx, ny));
                if (it != mp.end()) add(i, it->second);
            }
        }
    }
    std::vector<int> vis(N), it(N), ord;
    std::vector<int> stk;
    ord.reserve(N);
    stk.reserve(N);
    for (int s = 0; s < N; s++) {
        if (vis[s]) continue;
        vis[s] = 1;
        stk.push_back(s);
        while (!stk.empty()) {
            int u = stk.back();
            if (it[u] == int(adj[u].size())) {
                ord.push_back(u);
                stk.pop_back();
                continue;
            }
            int v = adj[u][it[u]++];
            if (!vis[v]) {
                vis[v] = 1;
                stk.push_back(v);
            }
        }
    }
    std::vector<int> bel(N, -1), w;
    int cnt = 0;
    for (int z = N - 1; z >= 0; z--) {
        int s = ord[z];
        if (bel[s] != -1) continue;
        int sum = 0;
        bel[s] = cnt;
        stk.push_back(s);
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            sum += u < k;
            for (auto v : radj[u]) {
                if (bel[v] == -1) {
                    bel[v] = cnt;
                    stk.push_back(v);
                }
            }
        }
        w.push_back(sum);
        cnt++;
    }
    std::vector<std::vector<int>> g(cnt);
    std::vector<int> deg(cnt);
    for (int u = 0; u < N; u++) {
        for (auto v : adj[u]) {
            if (bel[u] != bel[v]) {
                g[bel[u]].push_back(bel[v]);
                deg[bel[v]]++;
            }
        }
    }
    std::queue<int> q;
    std::vector<int> f = w;
    for (int i = 0; i < cnt; i++) {
        if (!deg[i]) q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = std::max(ans, f[u]);
        for (auto v : g[u]) {
            f[v] = std::max(f[v], f[u] + w[v]);
            if (!--deg[v]) q.push(v);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
