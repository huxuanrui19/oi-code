#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int D = 245;
const int mod = 998244353;

int dp[2][N][D];

int main() {
    freopen("ground.in", "r", stdin);
    freopen("ground.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i * i <= k; i++) {
        if (k % i) continue;
        v.push_back(i);
        if (i * i != k) v.push_back(k / i);
    }
    sort(v.begin(), v.end());

    int m = v.size();
    vector<int> id(k + 1);
    for (int i = 0; i < m; i++) id[v[i]] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == -1) continue;

            for (int t = 0; t < m; t++) {
                int ways = 0;
                if (i == 1 && j == 1) ways = t == 0;
                else {
                    if (i > 1) ways = dp[0][j][t];
                    if (j > 1) ways = (ways + dp[1][j - 1][t]) % mod;
                }
                if (!ways) continue;

                int g = __gcd((long long)v[t] * x, (long long)k);
                int &to = dp[1][j][id[g]];
                to = (to + ways) % mod;
            }
        }
        memcpy(dp[0], dp[1], sizeof(dp[0]));
        memset(dp[1], 0, sizeof(dp[1]));
    }

    cout << dp[0][n][id[k]] << '\n';
    return 0;
}
