#include <bits/stdc++.h>
using namespace std;
const int N = 450;
vector<int> row[N], col[N], a[N];
int f[200005], n, m;
int main() {
	freopen("frame.in","r",stdin);
	freopen("frame.out","w",stdout);
		scanf("%d%d", &n, &m);
		if (n < m) {
			for (int i = 0; i <= n; ++i) {
				a[i].resize(m + 1);
				row[i].resize(m + 1);
				col[i].resize(m + 1);
				for (int j = 0; j <= m; ++j)
					a[i][j] = row[i][j] = col[i][j] = 0;
			}
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					scanf("%d", &a[i][j]);
		} else {
			for (int i = 0; i <= m; ++i) {
				a[i].resize(n + 1);
				row[i].resize(n + 1);
				col[i].resize(n + 1);
				for (int j = 0; j <= n; ++j)
					a[i][j] = row[i][j] = col[i][j] = 0;
			}
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					scanf("%d", &a[j][i]);
			swap(n, m);
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				row[i][j] = row[i][j - 1] + a[i][j];
				col[i][j] = col[i - 1][j] + a[i][j];
			}
		int ans = -1e9;
		for (int l = 1; l <= n; ++l)
			for (int r = l + 1; r <= n; ++r) {
				f[m + 1] = -1e9;
				for (int i = m; i >= 1; --i)
					f[i] = max(f[i + 1], row[l][i - 1] + row[r][i - 1] + col[r][i] - col[l - 1][i]);
				for (int i = 1; i < m; ++i)
					ans = max(ans, -row[l][i] - row[r][i] + col[r][i] - col[l - 1][i] + f[i + 1]);
			}
		printf("%d\n", ans);
	return 0;
}
