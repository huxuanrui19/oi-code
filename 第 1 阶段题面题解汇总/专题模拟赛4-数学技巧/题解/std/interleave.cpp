#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

i64 power(i64 a, i64 b, i64 mod) {
    i64 res = 1 % mod;
    while (b > 0) {
        if (b & 1) {
            res = static_cast<i64>(static_cast<i128>(res) * a % mod);
        }
        a = static_cast<i64>(static_cast<i128>(a) * a % mod);
        b >>= 1;
    }
    return res;
}

std::vector<i64> prime_factors(i64 x) {
    std::vector<i64> factors;
    for (i64 p = 2; p <= x / p; ++p) {
        if (x % p != 0) {
            continue;
        }
        factors.push_back(p);
        while (x % p == 0) {
            x /= p;
        }
    }
    if (x > 1) {
        factors.push_back(x);
    }
    return factors;
}

i64 euler_phi(i64 x) {
    i64 phi = x;
    for (i64 p : prime_factors(x)) {
        phi = phi / p * (p - 1);
    }
    return phi;
}

void solve() {
    i64 n;
    std::cin >> n;
    i64 mod = 2 * n - 1;
    if (mod == 1) {
        std::cout << 1 << "\n";
        return;
    }

    i64 order = euler_phi(mod);
    for (i64 p : prime_factors(order)) {
        while (order % p == 0 && power(2, order / p, mod) == 1) {
            order /= p;
        }
    }
    std::cout << order << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
