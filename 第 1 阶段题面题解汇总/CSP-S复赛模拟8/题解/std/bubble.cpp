#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }

    std::vector<int> b(n, 0);
    int mx = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > mx) {
            while (b[cur] != 0) {
                ++cur;
            }
            b[cur] = a[i];
            mx = a[i];
        } else {
            int pos = std::min(n - 1, i + k);
            b[pos] = a[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " \n"[i + 1 == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
