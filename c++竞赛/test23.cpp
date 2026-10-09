#include <bits/stdc++.h>

using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int _ = 1e6 + 7, mod = 32465177;

bool vis[_];

int cnt, pr[_], mu[_], f[_], h[_], y[_];

int ksm(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

void init()
{
	mu[1] = 1;
	f[1] = 1;
	y[1] = 1;
	for(int i = 2; i <= _ - 7; ++i)
	{
		f[i] = 1ll * f[i - 1] * ksm(i, i) % mod;
		y[i] = 1;
		if(!vis[i])
		{
			pr[++cnt] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= cnt && i * pr[j] <= _ - 7; ++j)
		{
			int p = i * pr[j];
			vis[p] = 1;
			if(i % pr[j] == 0)
			{
				mu[p] = 0;
				break;
			}
			mu[p] = -mu[i];
		}
	}
	for(int i = 1; i <= _ - 7; ++i)
		for(int j = 1; i * j <= _ - 7; ++j)
		{
			h[i * j] = ((h[i * j] + mu[i] * i) % (mod - 1) + (mod - 1)) % (mod - 1);
			y[i * j] = 1ll * y[i * j] * ksm(i, i * mu[i] + mod - 1) % mod;
		}
	for(int i = 1; i <= _ - 7; ++i)
	{
		y[i] = ksm(1ll * ksm(i, h[i]) * y[i] % mod, i);
		h[i] = 1ll * h[i] * i % (mod - 1);
	}
	y[0] = 1;
	for(int i = 2; i <= _ - 7; ++i)
	{
		y[i] = 1ll * y[i - 1] * y[i] % mod;
		h[i] = (h[i] + h[i - 1]) % (mod - 1);
	}
}

int s(int x)
{
	return 1ll * x * (x + 1) / 2 % (mod - 1);
}

int g(int x, int y)
{
	return 1ll * ksm(f[x], s(y)) * ksm(f[y], s(x)) % mod;
}

int hh(int l, int r)
{
	return ((h[r] - h[l - 1]) % (mod - 1) + (mod - 1)) % (mod - 1);
}

int yy(int l, int r)
{
	return 1ll * y[r] * ksm(y[l - 1], mod - 2) % mod;
}

int S(int a, int b)
{
	if(a > b) swap(a, b);
	int res = 1;
	for(int i = 1, j; i <= a; i = j + 1)
	{
		j = min(a / (a / i), b / (b / i));
		res = 1ll * res * ksm(g(a / i, b / i), hh(i, j)) % mod * ksm(yy(i, j), 1ll * s(a / i) * s(b / i) % (mod - 1)) % mod; 
	}
	return res;
}

int solve(int l, int r)
{
	swap(l, r);
	int ans1 = 1ll * S(r, r) * S(l - 1, l - 1) % mod, ans2 = 1ll * S(r, l - 1) * S(l - 1, r) % mod;
	return 1ll * ans1 * ksm(ans2, mod - 2) % mod;
}

signed main()
{
	init();
	int t = read(), n = read();
	while(t--)
	{
		write(solve(read(), read()));
		putchar('\n');
	}
}

