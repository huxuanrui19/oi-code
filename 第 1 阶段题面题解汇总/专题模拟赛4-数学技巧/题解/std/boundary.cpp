#include <bits/stdc++.h>
const int mod = 1e9+7;
const int N = 40000;
int x, k, c[1505][1505], ans, pri[N], vis[N], cnt;
void solve(int A) {
    if(A < 1) return;
    std::vector<int> pf;
    int val = A;
    for(int i = 1; i <= cnt && pri[i] <= val; ++i) {
        if(val % pri[i] == 0) pf.push_back(0);
        while(val % pri[i] == 0) val /= pri[i], ++pf[(int)pf.size() - 1];
    }
    if(val > 1) pf.push_back(1);
    int m = pf.size();
    int count = 0;
    for(int s = 0; s < 1 << m * 2; ++s) {
        std::vector<int> num = pf;
        for(int &x: num) ++x;
        for(int i = 0; i < m; ++i)
            if(s >> i & 1)
                num[i] = std::max(num[i] - 1, 0);
        for(int i = m; i < m << 1; ++i)
            if(s >> i & 1)
                num[i - m] = std::max(num[i - m] - 1, 0);
        int mul = 1;
        for(int i = 0; i < m; ++i) mul *= num[i];
        if(mul >= k) {
            if(__builtin_popcount(s) & 1) count = (count + mod - c[mul][k]) % mod;
            else count = (count + c[mul][k]) % mod;
        }
    }
    ans += count, ans %= mod;
}
signed main() {
    for(int i = 2; i <= 39000; ++i) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= 39000; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    for(int i = 0; i <= 1500; ++i) c[i][0] = c[i][i] = 1;
    for(int i = 1; i <= 1500; ++i) for(int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    
    scanf("%d%d", &x, &k);
    int b = sqrt(x);
    for(int d = 1; d <= b; ++d) if(x % d == 0) {
        solve(x / d - 1);
        if(d * d != x) solve(d - 1);
    }
    printf("%d\n", ans);
    return 0;
}