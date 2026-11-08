#include <bits/stdc++.h>
using namespace std;

// State 2*cell+t: remove this entire cell, taking its left (t=0)
// or right (t=1) triangle first. Each dependency is another entire cell.
struct Frame {
    int state, next_edge;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    if (!(cin >> rows >> cols)) return 0;
    vector<string> grid(rows);
    for (string &row : grid) cin >> row;
    const int cells = rows * cols, inf = 2 * cells + 1;
    vector<array<int, 2>> edges(2 * cells);
    auto state = [&](int x, int y, int type) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return -1;
        return 2 * (x * cols + y) + type;
    };
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            for (int type = 0; type < 2; ++type) {
                int u = state(x, y, type);
                edges[u][0] = state(x, y + (type == 0 ? -1 : 1), type);
                bool down = (grid[x][y] == 'N') == (type == 0);
                int nx = x + (down ? 1 : -1);
                edges[u][1] = -1;
                if (nx >= 0 && nx < rows) {
                    int next_type = down ? (grid[nx][y] == 'N' ? 0 : 1)
                                         : (grid[nx][y] == 'N' ? 1 : 0);
                    edges[u][1] = state(nx, y, next_type);
                }
            }
        }
    }

    // Per scan: 0 = unseen, 1 = on stack, 2 = entire cell removed.
    vector<unsigned char> color(cells);
    vector<Frame> stack;
    stack.reserve(cells);
    auto extend = [&](int root) {
        if (color[root / 2] == 2) return 0;
        int added = 2;
        color[root / 2] = 1;
        stack.clear();
        stack.push_back({root, 0});
        while (!stack.empty()) {
            Frame &f = stack.back();
            if (f.next_edge == 2) {
                color[f.state / 2] = 2;
                stack.pop_back();
                continue;
            }
            int v = edges[f.state][f.next_edge++];
            if (v == -1 || color[v / 2] == 2) continue;
            // This scan and every later root in it are impossible.
            if (color[v / 2] == 1) return inf;
            color[v / 2] = 1;
            added += 2;
            stack.push_back({v, 0});
        }
        return added;
    };

    vector<int> left(cols), right(cols);
    for (int x = 0; x < rows; ++x) {
        for (int type = 0; type < 2; ++type) {
            fill(color.begin(), color.end(), 0);
            int total = 0;
            for (int k = 0; k < cols; ++k) {
                int y = type == 0 ? k : cols - 1 - k;
                // Closures are nested along the scan; do not restart a failed DFS.
                if (total < inf) total = min(inf, total + extend(state(x, y, type)));
                (type == 0 ? left[y] : right[y]) = total;
            }
        }
        for (int y = 0; y < cols; ++y) {
            int ans = min(left[y], right[y]);
            if (y) cout << ' ';
            cout << (ans == inf ? -1 : ans);
        }
        cout << '\n';
    }
    return 0;
}
