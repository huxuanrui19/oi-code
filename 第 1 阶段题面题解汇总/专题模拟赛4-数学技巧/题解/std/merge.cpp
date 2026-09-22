#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 5E3 + 10, mod = 998244353;

int n;
string s;
int dp[N][N], cat[N];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> s, s = ' ' + s;

    if (n == 1) {
        cout << (s.back() == '0' ? 1 : 0) << '\n';
        return 0;
    }

    cat[0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < i; j ++)
            (cat[i] += (i64)cat[j] * cat[i - j - 1] % mod) %= mod;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= i; j ++) {
            dp[i][j] = dp[i - 1][j];
            if (j && i > 1) (dp[i][j] += (i64)(s[i] != s[i - 1] ? 1 : mod - 1) * dp[i - 2][j - 1] % mod) %= mod;
        }

    int res = 0;
    for (int i = 0; i < n; i ++)
        (res += (i64)dp[n][i] * cat[n - i - 1] % mod) %= mod;

    cout << (i64)res * (mod + 1 >> 1) % mod << '\n';

    return 0;
}