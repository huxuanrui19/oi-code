#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define int long long
#define mod 998244353
#define N 50001
#define M 410
vector<int> vec[N];
int dp[N][M][2], siz[N], temp[M][2], m;

void add(int u, int v) { //使用边更新数�?
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i <= siz[u]; i++) { //这里时间复杂度可以证明为n*m
		for (int j = 0; j <= siz[v]; j++) {
			temp[i + j][0] += 2 * dp[u][i][0] * dp[v][j][1] + dp[u][i][0] * dp[v][j][0];
			temp[i + j][0] %= mod;
			temp[i + j][1] += 2 * dp[u][i][1] * (dp[v][j][0] + dp[v][j][1]);
			temp[i + j][1] %= mod;
			temp[i + j + 1][1] += dp[u][i][0] * dp[v][j][0];
			temp[i + j + 1][1] %= mod;
		}
	}
	for (int i = 0; i < m; i++) { //将temp复制到dp�?
		dp[u][i][0] = (temp[i][0] + temp[i + m][0]) % mod; //i+j有可能超过n
		dp[u][i][1] = (temp[i][1] + temp[i + m][1]) % mod;
	}
	siz[u] = min(siz[u] + siz[v], m); //siz[u]不能超过m,否则会数组出界�?
}

void dfs(int id, int from) {
	siz[id] = 1;
	dp[id][0][0] = 1;
	for (int i = 0; i < vec[id].size(); i++) {
		int to = vec[id][i];
		if (to == from)
			continue;
		dfs(to, id); //树形dp的惯例，自底向上更新
		add(id, to);
	}
}

signed main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int n;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%lld%lld", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	cout << (dp[1][0][0] + dp[1][0][1]) % mod;
}