#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, f[2][N][N], d[2][N][N];
char s[N][N];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct node { int x, y; };
queue <node> Q;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '1')
				Q.push({i, j});
	}
	for(int i = 0; Q.size() > 0; i++) {
		int siz = Q.size();
		while(siz--) {
			int x = Q.front().x;
			int y = Q.front().y;
			Q.pop();
			d[i % 2][x][y] = i;
			for(int j = 0; j < 4; j++) {
				int p = x + dx[j];
				int q = y + dy[j];
				if(p < 1 || p > n || q < 1 || q > m || f[(i + 1) % 2][p][q]) continue;
				f[(i + 1) % 2][p][q] = 1;
				Q.push({p, q}); 
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int g = min({i, n - i + 1, j, m - j + 1});
			int odd = min(d[1][i][j], g % 2 == 0 ? g + 1 : g);
			int eve = min(d[0][i][j], g % 2 == 1 ? g + 1 : g);
			ans = max({ans, odd - 2, eve - 2});
		}
	}
	cout << ans;
	return 0;
}
