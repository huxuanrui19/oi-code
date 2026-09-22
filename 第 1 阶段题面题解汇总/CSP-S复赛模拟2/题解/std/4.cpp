#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    int k;
    std::cin >> k;

    const int m = n / 2 - 1;
    std::vector<i64> width(m), depth(m);
    for (int i = 0; i < m; i++) {
        width[i] = x[2 * i + 2] - x[2 * i + 1];
        depth[i] = y[2 * i + 1];
    }

    std::vector<int> left(m, -1), right(m, -1), parent(m, -1);
    std::vector<int> stk;
    stk.reserve(m);
    for (int i = 0; i < m; i++) {
        int last = -1;
        while (!stk.empty() && depth[stk.back()] > depth[i]) {
            last = stk.back();
            stk.pop_back();
        }
        if (!stk.empty()) {
            right[stk.back()] = i;
            parent[i] = stk.back();
        }
        if (last != -1) {
            left[i] = last;
            parent[last] = i;
        }
        stk.push_back(i);
    }

    const int root = stk.front();
    std::vector<int> order;
    order.reserve(m);
    std::vector<int> todo{root};
    while (!todo.empty()) {
        int u = todo.back();
        todo.pop_back();
        order.push_back(u);
        if (left[u] != -1) {
            todo.push_back(left[u]);
        }
        if (right[u] != -1) {
            todo.push_back(right[u]);
        }
    }

    std::vector<i64> sum_width(m), weight(m), best(m);
    std::vector<int> heavy(m, -1);
    for (auto it = order.rbegin(); it != order.rend(); it++) {
        int u = *it;
        sum_width[u] = width[u];
        if (left[u] != -1) {
            sum_width[u] += sum_width[left[u]];
        }
        if (right[u] != -1) {
            sum_width[u] += sum_width[right[u]];
        }

        i64 parent_depth = parent[u] == -1 ? 0 : depth[parent[u]];
        weight[u] = (depth[u] - parent_depth) * sum_width[u];

        if (left[u] != -1 &&
            (right[u] == -1 || best[left[u]] >= best[right[u]])) {
            heavy[u] = left[u];
        } else if (right[u] != -1) {
            heavy[u] = right[u];
        }

        best[u] = weight[u];
        if (heavy[u] != -1) {
            best[u] += best[heavy[u]];
        }
    }

    std::vector<i64> gain;
    std::vector<std::pair<int, i64>> chains{{root, 0}};
    while (!chains.empty()) {
        auto [u, sum] = chains.back();
        chains.pop_back();
        sum += weight[u];

        int v = heavy[u];
        if (v == -1) {
            gain.push_back(sum);
            continue;
        }
        if (left[u] != -1 && left[u] != v) {
            chains.emplace_back(left[u], 0);
        }
        if (right[u] != -1 && right[u] != v) {
            chains.emplace_back(right[u], 0);
        }
        chains.emplace_back(v, sum);
    }

    std::sort(gain.begin(), gain.end(), std::greater<i64>());
    const int take = std::min(k, static_cast<int>(gain.size()));
    i64 ans = 0;
    for (int i = 0; i < take; i++) {
        ans += gain[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
