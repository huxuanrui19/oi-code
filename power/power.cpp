#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    if (FILE *file = fopen("power.in", "r")) {
        fclose(file);
        freopen("power.in", "r", stdin);
        freopen("power.out", "w", stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        const ll INF = (1LL << 62);
        vector<ll> dist(n + 1, INF);
        vector<int> from(n + 1, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            dist[x] = 0;
            from[x] = x;
            pq.push({0, x});
        }

        ll ans = INF;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) {
                continue;
            }

            for (auto [v, w] : graph[u]) {
                if (from[v] != 0 && from[v] != from[u]) {
                    ans = min(ans, dist[u] + dist[v] + (ll)w);
                }

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    from[v] = from[u];
                    pq.push({dist[v], v});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
