#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
// head

const int N = 101000;
int n, u, v;
VI e[N];
ll sz[N], ans, dp[N];
set<pair<ll, int> > blk[N];
ll query(int u) {
	if (!SZ(blk[u]))
		return 0;
	else
		return blk[u].rbegin()->fi;
}

void dfs(int u, int f) {
	sz[u] = 1;
	for (auto v : e[u]) {
		if (v == f)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		blk[u].insert(mp(sz[v] * (n - sz[v]), v));
	}
	ans += sz[u] * (n - sz[u]);
	ans -= query(u);
}

void dfs2(int u, int f) {
	dp[u] = ans;
	for (auto v : e[u]) {
		if (v == f)
			continue;
		ans = dp[u];
		ans += query(u);
		blk[u].erase(mp(sz[v] * (n - sz[v]), v));
		ans -= query(u);
		ans += query(v);
		blk[v].insert(mp(sz[v] * (n - sz[v]), u));
		ans -= query(v);
		dfs2(v, u);
		blk[u].insert(mp(sz[v] * (n - sz[v]), v));
		blk[v].erase(mp(sz[v] * (n - sz[v]), u));
	}
}

int main() {
	freopen("decomposition.in", "r", stdin);
	freopen("decomposition.out", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	ans = 0;
	dfs(1, 0);
	dfs2(1, 0);
	rep(i, 1, n + 1) printf("%lld\n", dp[i]);
}
