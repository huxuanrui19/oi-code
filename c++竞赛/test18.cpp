#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5, mod = 32465177;

int t, n, l, r;
int p[N], mob[N], tmp1[N], tmp2[N], b[N], c[N], d[N], e[N], f[N], g[N], gg[N];
bool st[N];

inline int qpow(int x, __int128 k)
{
    if (k < 0)
        k *= 2 - mod; // 注意负指数数的处理
    int res = 1;
    while (k)
    {
        if (k & 1)
            (res *= x) %= mod;
        (x *= x) %= mod, k >>= 1;
    }
    return res;
}

inline void init()
{
	// 线性筛预处理莫比乌斯函数
    mob[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            p[++p[0]] = i, mob[i] = -1;
        for (int j = 1; i * p[j] <= n; j++)
        {
            st[i * p[j]] = 1;
            if (i % p[j])
                mob[i * p[j]] = -mob[i];
            else
            {
                mob[i * p[j]] = 0;
                break;
            }
        }
    }
    b[0] = g[0] = gg[0] = 1;
    // 暴力预处理 b,c，同时存下 tmp1,tmp2 为后面的预处理做准备
    for (int i = 1; i <= n; i++)
        tmp1[i] = qpow(i, i), tmp2[i] = qpow(tmp1[i], -1), b[i] = b[i - 1] * tmp1[i] % mod, c[i] = i * (i + 1) / 2,
        e[i] = 1;
    // 预处理 d,e，e 可以分讨
    for (int i = 1; i <= n; i++)
        for (int j = 1; i * j <= n; j++)
        {
            d[i * j] += i * mob[i];
            if (mob[i] > 0)
                (e[i * j] *= tmp1[i]) %= mod;
            else if (mob[i] < 0)
                (e[i * j] *= tmp2[i]) %= mod;
        }
    // 预处理 f,g
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + i * d[i], g[i] = g[i - 1] * qpow(qpow(i, d[i]) * e[i] % mod, i) % mod, gg[i] = qpow(g[i], -1);
}

inline int a(int n, int m)
{
    return qpow(b[n], c[m]) * qpow(b[m], c[n]) % mod;
}

inline int cal(int n, int m)
{
    int res = 1;
    // 整除分块
    for (int l = 1, r; l <= n; l = r + 1)
        r = min(n / (n / l), m / (m / l)),
        (res *= qpow(a(n / l, m / l), f[r] - f[l - 1]) * qpow(g[r] * gg[l - 1] % mod, (__int128)c[n / l] * c[m / l]) %
                mod) %= mod;
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t >> n, init();
    while (t--)
        cin >> l >> r, cout << cal(r, r) * cal(l - 1, l - 1) % mod * qpow(cal(l - 1, r), -2) % mod << "\n";
    return 0;
}

