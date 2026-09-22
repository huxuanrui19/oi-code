#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  if (y < x) x = y;
}
constexpr int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m, a[MAXN], sz[MAXN], son[MAXN], fa[MAXN], dep[MAXN], tp[MAXN];
int dfn[MAXN], dfc, rev[MAXN];
vector<int> g[MAXN];
struct way_t {
  int num, rem;
};
way_t operator+(int x, const way_t &y) { return {x + y.num, y.rem}; }
bool operator<(const way_t &x, const way_t &y) {
  return x.num == y.num ? x.rem > y.rem : x.num < y.num;
}
struct myvec {
  way_t f;
  int g;
};
struct matrix {
  way_t f[20];
  int g[20];
};
myvec operator+(const myvec &x, const matrix &y) {
  myvec ret;
  ret.f = min(x.f.num + y.f[x.f.rem], x.f.num + 1 + y.f[x.g]);
  ret.g = y.g[x.g];
  return ret;
}
matrix operator+(const matrix &x, const matrix &y) {
  matrix ret;
  for (int i = 0; i < 20; ++i) {
    ret.f[i] = min(x.f[i].num + y.f[x.f[i].rem], x.f[i].num + 1 + y.f[x.g[i]]);
    ret.g[i] = y.g[x.g[i]];
  }
  return ret;
}
struct node {
  matrix s1, s2;
};
node operator+(const node &x, const node &y) {
  return {x.s1 + y.s1, y.s2 + x.s2};
}
void dfs1(int u, int pre) {
  fa[u] = pre;
  dep[u] = dep[pre] + 1;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == pre) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int top) {
  tp[u] = top;
  dfn[u] = ++dfc;
  rev[dfc] = u;
  if (son[u]) dfs2(son[u], top);
  for (auto v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
int get_lca(int u, int v) {
  while (tp[u] != tp[v]) {
    if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
    u = fa[tp[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
node tr[MAXN * 4];
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
void push_up(int p) { tr[p] = tr[ls(p)] + tr[rs(p)]; }
void build(int p, int l, int r) {
  if (l == r) {
    tr[p].s1.f[0] = {1, a[rev[l]] - 1};
    tr[p].s1.g[0] = a[rev[l]] - 1;
    for (int i = 1; i < 20; ++i) {
      tr[p].s1.f[i] = {0, i - 1};
      tr[p].s1.g[i] = max(i - 1, a[rev[l]] - 1);
    }
    tr[p].s2 = tr[p].s1;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls(p), l, mid);
  build(rs(p), mid + 1, r);
  push_up(p);
}
void update(int p, int l, int r, int pos) {
  if (l == r) {
    tr[p].s1.f[0] = {1, a[rev[l]] - 1};
    tr[p].s1.g[0] = a[rev[l]] - 1;
    for (int i = 1; i < 20; ++i) {
      tr[p].s1.f[i] = {0, i - 1};
      tr[p].s1.g[i] = max(i - 1, a[rev[l]] - 1);
    }
    tr[p].s2 = tr[p].s1;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    update(ls(p), l, mid, pos);
  } else {
    update(rs(p), mid + 1, r, pos);
  }
  push_up(p);
}
void apply1(int p, int l, int r, int ql, int qr, myvec &v) {
  if (ql <= l && r <= qr) {
    v = v + tr[p].s1;
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) apply1(ls(p), l, mid, ql, qr, v);
  if (qr > mid) apply1(rs(p), mid + 1, r, ql, qr, v);
}
void apply2(int p, int l, int r, int ql, int qr, myvec &v) {
  if (ql <= l && r <= qr) {
    v = v + tr[p].s2;
    return;
  }
  int mid = (l + r) >> 1;
  if (qr > mid) apply2(rs(p), mid + 1, r, ql, qr, v);
  if (ql <= mid) apply2(ls(p), l, mid, ql, qr, v);
}
int main() {
  freopen("fuelpath.in", "r", stdin);
  freopen("fuelpath.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  cin >> m;
  while (m--) {
    char typ;
    cin >> typ;
    if (typ == 'Q') {
      int u, v;
      cin >> u >> v;
      int t = get_lca(u, v);
      myvec now = {{0, 0}, 0};
      while (dep[tp[u]] > dep[t]) {
        apply2(1, 1, n, dfn[tp[u]], dfn[u], now);
        u = fa[tp[u]];
      }
      if (u != t) apply2(1, 1, n, dfn[t] + 1, dfn[u], now);
      v = fa[v];
      stack<pair<int, int>> stk;
      while (dep[tp[v]] >= dep[t]) {
        stk.emplace(dfn[tp[v]], dfn[v]);
        v = fa[tp[v]];
      }
      if (dep[v] >= dep[t]) stk.emplace(dfn[t], dfn[v]);
      while (!stk.empty()) {
        apply1(1, 1, n, stk.top().first, stk.top().second, now);
        stk.pop();
      }
      cout << now.f.num << "\n";
    } else {
      int u;
      cin >> u >> a[u];
      update(1, 1, n, dfn[u]);
    }
  }
  return 0;
}
