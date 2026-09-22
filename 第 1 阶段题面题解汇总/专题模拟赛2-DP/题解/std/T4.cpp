#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using i64 = long long;

namespace {

constexpr i64 INF = 4'000'000'000'000'000'000LL;

i64 capped_add(i64 a, i64 b) {
    if (a >= INF || b >= INF || a > INF - b) return INF;
    return a + b;
}

i64 solve_case() {
    int n;
    std::cin >> n;
    std::vector<i64> cost(n), limit(n);
    for (i64 &x : cost) std::cin >> x;
    for (i64 &x : limit) std::cin >> x;

    std::vector<std::vector<std::pair<int, i64>>> graph(n);
    for (int edge = 1; edge < n; ++edge) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    std::vector<int> parent(n, -1), order;
    order.reserve(n);
    order.push_back(0);
    for (std::size_t at = 0; at < order.size(); ++at) {
        int u = order[at];
        for (const auto &edge : graph[u]) {
            int v = edge.first;
            if (v == parent[u]) continue;
            parent[v] = u;
            order.push_back(v);
        }
    }

    std::vector<i64> distance(static_cast<std::size_t>(n) * n);
    struct Frame {
        int u;
        int parent;
        i64 distance;
    };
    std::vector<Frame> stack;
    stack.reserve(n);
    for (int source = 0; source < n; ++source) {
        stack.clear();
        stack.push_back({source, -1, 0});
        while (!stack.empty()) {
            Frame current = stack.back();
            stack.pop_back();
            distance[static_cast<std::size_t>(source) * n + current.u] = current.distance;
            for (const auto &edge : graph[current.u]) {
                int v = edge.first;
                i64 w = edge.second;
                if (v == current.parent) continue;
                stack.push_back({v, current.u, current.distance + w});
            }
        }
    }

    std::vector<i64> dp(static_cast<std::size_t>(n) * n, INF), best(n, INF);
    for (int position = n - 1; position >= 0; --position) {
        int u = order[position];
        i64 *row = dp.data() + static_cast<std::size_t>(u) * n;
        for (int chosen = 0; chosen < n; ++chosen) {
            if (distance[static_cast<std::size_t>(u) * n + chosen] <= limit[u]) {
                row[chosen] = cost[chosen];
            }
        }

        for (const auto &edge : graph[u]) {
            int v = edge.first;
            if (parent[v] != u) continue;
            const i64 *child = dp.data() + static_cast<std::size_t>(v) * n;
            for (int chosen = 0; chosen < n; ++chosen) {
                if (row[chosen] >= INF) continue;
                i64 reuse = child[chosen] >= INF ? INF : child[chosen] - cost[chosen];
                row[chosen] = capped_add(row[chosen], std::min(best[v], reuse));
            }
        }

        best[u] = *std::min_element(row, row + n);
    }
    return best[0];
}

}  // namespace

int main() {
    if (std::FILE* input_file = std::fopen("watch.in", "r")) {
        std::fclose(input_file);
        std::freopen("watch.in", "r", stdin);
        std::freopen("watch.out", "w", stdout);
    }

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_count;
    if (!(std::cin >> test_count)) return 0;
    while (test_count--) std::cout << solve_case() << '\n';
    return 0;
}
