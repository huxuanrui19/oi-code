#include <bits/stdc++.h>
using namespace std;
const int K = 998244353;
int n, cnt = 0, f[2010][2010] = {0}, s[2010];
char c[2010][2010];
int power(int x, int k)
{
int t = 1;
for (; k; k >>= 1, x = 1ll * x * x % K)
if (k & 1)
            t = 1ll * t * x % K;
    return t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] == '.')
                ++cnt;
        }
    int tn = power(2, cnt), i2 = power(2, K - 2), i4 = 1ll * i2 * i2 % K;
    for (int i = 2; i <= n + 1; ++i)
        if (c[i - 1][1] == '.')
            f[i][1] = 1ll * tn * i2 % K;
    f[1][1] = tn;
    for (int j = 2; j <= n; ++j)
    {
        s[1] = 0;
        for (int i = 1; i <= n; ++i)
            if (c[i][j - 1] == '.')
                s[i + 1] = (s[i] + 1ll * f[i][j - 1] * i4) % K;
            else
                s[i + 1] = s[i];
        for (int i = 1; i <= n + 1; ++i)
        {
            f[i][j] = f[i][j - 1];
            if (i >= 2 && c[i - 1][j] == '.')
                f[i][j] = (f[i][j] + s[i]) % K;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; ++i)
        if (i == n + 1)
            ans = (ans + f[i][n]) % K;
        else if (c[i][n] == '.')
            ans = (ans + 1ll * f[i][n] * i2) % K;
    cout << ans << endl;
    return 0;
}