#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 mod = 998244353;
int main() {
    freopen("alert.in", "r", stdin);
    freopen("alert.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> f(k + 1), g(k + 1), h(k + 1), nh(k + 1), sum(k + 1);
    f[0] = h[0] = 1;
    for (int i = 1; i <= n; i++) {
        std::fill(g.begin(), g.end(), 0);
        for (int j = 1; j <= std::min(i, k); j++) {
            g[j] = (f[j] * j + f[j - 1] * (k - j + 1)) % mod;
        }
        f.swap(g);
        sum[k] = 0;
        for (int j = k - 1; j >= 0; j--) sum[j] = (sum[j + 1] + h[j]) % mod;
        std::fill(nh.begin(), nh.end(), 0);
        for (int j = 1; j <= std::min(i, k - 1); j++) {
            nh[j] = (h[j - 1] * (k - j + 1) + sum[j]) % mod;
        }
        nh[k] = (h[k] * k + h[k - 1]) % mod;
        h.swap(nh);
    }
    std::cout << (f[k] - h[k] + mod) % mod << '\n';
    return 0;
}
