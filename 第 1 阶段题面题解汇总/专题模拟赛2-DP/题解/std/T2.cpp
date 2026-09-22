#include <bits/stdc++.h>
using namespace std;
constexpr int N = 300007, mod = 998244353, K = 2, S = 1 << (2 * K);
int n, a[N], f[2][S][K + 2], pre[N], cur[N];
char s[N];
bool vis[256];
void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
int main() {
    freopen("rating.in", "r", stdin);
    freopen("rating.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s + 1;
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int o = i & 1, p = o ^ 1;
        memset(f[o], 0, sizeof f[o]);
        memset(vis, 0, sizeof vis);
        for (int j = max(1, i - K); j <= min(n, i + K); j++) vis[(unsigned char)s[j]] = true;
        for (int mask = 0; mask < S; mask++) {
            for (int d = 0; d <= K; d++) {
                int w = f[p][mask][d];
                if (!w) continue;
                pre[i - 1] = i - 1 - d;
                for (int j = 0; j < K; j++) pre[i + j] = pre[i + j - 1] + (mask >> (j + K) & 1);
                for (int j = 1; j <= K; j++) {
                    if (i - 1 - j > 0) pre[i - 1 - j] = pre[i - j] - (mask >> (K - j) & 1);
                }
                bool flag = false;
                int pm = 0, pd = 0;
                for (int c = 0; c < a[i]; c++) {
                    char x = 'A' + c;
                    if (!vis[(unsigned char)x] && flag) {
                        add(f[o][pm][pd], w);
                        continue;
                    }
                    int nm = 0;
                    for (int j = max(1, i - K); j <= i + K; j++) cur[j] = max({pre[j], pre[j - 1] + (s[j] == x), cur[j - 1]});
                    for (int j = max(0, i - K); j <= i + K - 1; j++) {
                        if (cur[j] != cur[j + 1]) nm |= 1 << (j - i + K);
                    }
                    int nd = i - cur[i];
                    add(f[o][nm][nd], w);
                    if (!vis[(unsigned char)x]) {
                        flag = true;
                        pm = nm;
                        pd = nd;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < S; mask++) {
        for (int d = 0; d <= K; d++) add(ans, f[n & 1][mask][d]);
    }
    cout << ans << '\n';
    return 0;
}
