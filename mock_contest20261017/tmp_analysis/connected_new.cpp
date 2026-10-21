// connected —— 复制图
//
// 关键观察：f_G(a, b) 只与"从 1 到 a 的奇/偶长度最短路径"有关。
//   设 D0(a) = 从 1 到 a 的偶数长度最短路径，D1(a) = 奇数长度最短路径（不存在为 INF）。
//   在同一条边上来回走可以让任意路径 +2，故
//     f_G(a, b) 为真  <=>  b >= D_{b mod 2}(a)。
//   所以 G' 合法 <=> 每个点的 (D0, D1) 都被原样保留。
//
// 求法：二分图翻倍（拆点）后从 (1, 0) 做一次 BFS。
//   - 若 1 没有奇数长度回路（G 二分）：奇偶完全分离，G' 取一棵以 1 为根的树即可，n-1 条边。
//   - 否则每个点两维都有限。设每点二元组 (x, y) = {D0, D1} 排序后（x < y）。
//     点 v 在翻倍图里的两个点 (v,0)、(v,1) 各需要一条"父边"连到距离恰好 -1 的点。
//     若存在二元组为 (x-1, y-1) 的点，一条边即可同时充当两个父边；
//     否则需要两条边，分别连向 (x-1, y+1) 与 (x+1, y-1) 两组。
//     按 (x+y, x) 排序后，所有组落在若干条"链" (x,y) -> (x+1,y-1) -> ... 上；
//     链上相邻两组 u(大小 m0)、v(大小 m1) 之间连 max(m0', m1) 条边：
//     一条 u-v 边可以同时充当 u 中一点的"右下父边"和 v 中一点的"左上父边"。
//     有双亲组 (x-1,y-1) 存在的组，其节点改用双亲边，不再占用下一组的配额。
//     链尾剩余 t 个未满足的"右下"需求：若 y = x+1 可在组内两两配对（(t+1)/2 条边），
//     否则各需一条边（t 条）。1 号点所在的第一组无需父边（*(i>1) 即扣除它）。
//
// 复杂度：O((N + M) log N)。多组数据，ΣN <= 1e5，ΣM <= 2e5。

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[2 * MAXN];          // 翻倍图：i 与 i+n 分别表示 (点 i, 偶/奇层)
int dis[2 * MAXN];

struct Pair {
    ll x, y;                      // 排序后的 (D0, D1)
    bool operator<(const Pair& o) const {
        if (x + y != o.x + o.y) return x + y < o.x + o.y;
        return x < o.x;
    }
    bool operator==(const Pair& o) const { return x == o.x && y == o.y; }
};

Pair a[MAXN];

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= 2 * n; i++) g[i].clear(), dis[i] = INF;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);   // 允许自环；无重边
        // 无向边 (x,y) 在翻倍图中：(x,p) <-> (y,p^1)
        g[x].push_back(y + n); g[y + n].push_back(x);
        g[y].push_back(x + n); g[x + n].push_back(y);
    }

    // 从 (1, 0) BFS 求奇偶最短路
    queue<int> qu;
    dis[1] = 0; qu.push(1);
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v : g[u])
            if (dis[v] == INF) { dis[v] = dis[u] + 1; qu.push(v); }
    }

    // 二分图：1 没有奇环，奇偶两层互不连通，取 BFS 树即可
    if (dis[1 + n] == INF) { printf("%d\n", n - 1); return; }

    for (int i = 1; i <= n; i++)
        a[i] = {min(dis[i], dis[i + n]), max(dis[i], dis[i + n])};
    sort(a + 1, a + n + 1);

    ll ans = 0, t = 0;            // t：链上上一组尚未被满足的"右下父边"需求数
    set<Pair> seen;
    for (int i = 1; i <= n;) {
        int j = i;
        while (j + 1 <= n && a[j + 1] == a[i]) j++;
        ll cnt = j - i + 1;       // 本组大小
        bool hasDouble = seen.count({a[i].x - 1, a[i].y - 1});  // 双亲组存在？
        seen.insert(a[i]);
        // 与链上上一组之间的边：一条边同时覆盖两侧各一个需求，故取 max
        if (cnt >= t) {
            if (i > 1) ans += cnt;            // 第一组（1 号点所在组）无需父边
            if (!hasDouble) t = cnt;          // 本组节点仍需要"右下父边"配额
        } else {
            if (i > 1) ans += t;
            t = cnt;
        }
        // 链结束（下一组不是 (x+1, y-1)）：处理剩余配额
        if (j == n || a[j + 1].x != a[i].x + 1 || a[j + 1].y != a[i].y - 1) {
            ans += (a[i].x + 1 != a[i].y) ? t : (t + 1) / 2;
            t = 0;
        }
        i = j + 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
