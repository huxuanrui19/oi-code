#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	freopen("ratiosum.in","r",stdin);
	freopen("ratiosum.out","w",stdout);	
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int V = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        V = max(V, a[i]);
    }
    vector<array<int, 2>> ch(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        while (!s.empty() && a[s.back()] > a[i]) {
            x = s.back();
            s.pop_back();
        }
        if (!s.empty()) ch[s.back()][1] = i;
        ch[i][0] = x;
        s.push_back(i);
    }
    int rt = s[0];
    vector<int> ord{rt};
    for (int k = 0; k < n; k++) {
        int u = ord[k];
        if (ch[u][0]) ord.push_back(ch[u][0]);
        if (ch[u][1]) ord.push_back(ch[u][1]);
    }
    vector<int> L(n + 1), R(n + 1);
    for (int k = n - 1; k >= 0; k--) {
        int u = ord[k];
        L[u] = ch[u][0] ? L[ch[u][0]] : u;
        R[u] = ch[u][1] ? R[ch[u][1]] : u;
    }
    vector<int> pos(V + 1);
    for (int i = 1; i <= n; i++) pos[a[i]] = i;
    vector<int> pre(n + 2), suf(n + 2);
    iota(pre.begin(), pre.end(), 0);
    iota(suf.begin(), suf.end(), 0);
    auto find = [](vector<int> &f, int x) {
        int y = x;
        while (f[y] != y) y = f[y];
        while (f[x] != x) {
            int z = f[x];
            f[x] = y;
            x = z;
        }
        return y;
    };
    vector<int> q(n + 1), p(n + 1), head(V + 1, -1), nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        nxt[i] = head[a[i]];
        head[a[i]] = i;
    }
    i64 ans = 0;
    for (int x = 1; x <= V; x++) {
        if (x > 1 && pos[x - 1]) {
            int u = pos[x - 1];
            pre[u] = find(pre, u - 1);
            suf[u] = find(suf, u + 1);
        }
        for (int i = head[x]; i != -1;) {
            int z = nxt[i];
            int nq = find(pre, i);
            int np = find(suf, i);
            int d = x / a[i];
            if (d > 1) {
                int lx = max(L[i] - 1, nq);
                int ry = min(R[i] + 1, np);
                i64 dl = max(0, q[i] - lx);
                i64 dr = max(0, ry - p[i]);
                i64 cnt = dl * (ry - i) + dr * (i - lx) - dl * dr;
                ans += i64(d - 1) * cnt;
            }
            q[i] = nq;
            p[i] = np;
            if (x + a[i] <= V) {
                nxt[i] = head[x + a[i]];
                head[x + a[i]] = i;
            }
            i = z;
        }
    }
    for (int i = 1; i <= n; i++) {
        int d = V / a[i];
        int lx = L[i] - 1;
        int ry = R[i] + 1;
        i64 dl = max(0, q[i] - lx);
        i64 dr = max(0, ry - p[i]);
        i64 cnt = dl * (ry - i) + dr * (i - lx) - dl * dr;
        ans += i64(d) * cnt;
    }
    cout << ans << "\n";
    return 0;
}
