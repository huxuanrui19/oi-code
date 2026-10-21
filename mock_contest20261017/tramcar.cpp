// tramcar —— 矿车与侧线
//
// 模型：侧线在轨道右端。最右侧的矿车随时可以：
//   1. 直接通过接口向右驶出（"出站"；最终序列 = 出站顺序的逆序——
//      先出站的车停在右端，后出站的车堵在它左边）；
//   2. 进入侧线（栈，容量 M，后进先出）；
//   侧线中的车可随时移回主轨道，放在剩余车的最右侧，
//   成为下一辆可以行动的车（相当于弹栈后可立刻再次出站或重新入线）。
//
// 于是：出站顺序中宝石数必须非递增（最终序列从左到右非递减）。
// 按值从大到小依次出站每辆车时，侧线里恰好压着
// "值比它小、原始位置在它右边"的车，故 K = 0 时
//   答案 = max_i #{ j > i : a_j < a_i }。
//
// 一般情况：空矿车可以花宝石填数。判定容量 M 是否可行：
//   每辆非空车 i 要求（右侧值比它小的非空车数）<= M +（i 右侧的空车数），
//   右侧空车必须填到 >= a_i 才"不算数"；
//   按空车从左到右求出每辆空车至少要填到的值，总花费 <= K 即可行。
//   树状数组 O(n log n) 判定，二分答案。
//
// 子任务：K=0 的两档（12 + 20 分）可直接输出上面的公式；
// K=10^12 的两档（12 + 20 分）相当于"空车随便填"，本做法同样覆盖；满分 24 分。

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int n;
ll k;
ll a[MAXN];        // 每辆矿车的宝石数，0 = 空矿车
ll rk[MAXN];       // a[i] 在非零值中的排名（从 1 开始），空车为 0
ll val[MAXN];      // val[x] = 排名 x 对应的真实宝石数
int tot;           // 不同非零值个数
int cntEmpty;      // 空矿车数量

struct BIT {
    int c[MAXN];
    void clear() { memset(c, 0, sizeof(c)); }
    void add(int p, int v) { for (; p <= tot + 1; p += p & -p) c[p] += v; }
    int query(int p) const { int r = 0; for (; p; p -= p & -p) r += c[p]; return r; }
} bit;

ll R[MAXN];        // R[i] = max(#{ j>i : a_j < a_i } - M, 0)
ll needAt[MAXN];   // needAt[t] = 第 t 辆空车（从左数）至少要填到的排名

// 判定侧线容量 M 是否可行（最优填数的花费不超过 k）
bool check(ll M) {
    bit.clear();
    // 从右往左扫。注意：空车（排名 0）也加入树状数组——
    // 它若填得比 a_i 小，同样会压在 i 下方的侧线里，必须算进"阻挡车数"。
    for (int i = n; i >= 1; i--) {
        bit.add((int)rk[i] + 1, 1);           // 加在 排名+1 处（空车加在位置 1）
        R[i] = max(0LL, (ll)bit.query((int)rk[i]) - M);  // 查询 <= 排名 = 严格小于
    }
    memset(needAt, 0, sizeof(needAt));
    int seenEmpty = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) { seenEmpty++; continue; }
        // 需要 R[i] <= i 右侧的空车数，即 seenEmpty + R[i] <= cntEmpty
        ll r = cntEmpty - R[i] + 1;
        if (r <= seenEmpty) return false;     // 这辆车的要求无法满足
        needAt[r] = max(needAt[r], rk[i]);
    }
    // 前缀最大值：第 t 辆空车要填到所有"要求它"的车中的最大排名
    for (int t = 1; t <= cntEmpty; t++)
        needAt[t] = max(needAt[t], needAt[t - 1]);
    ll cost = 0;
    for (int t = 1; t <= cntEmpty; t++)
        cost += val[needAt[t]];
    return cost <= k;
}

int main() {
    freopen("tramcar.in", "r", stdin);
    freopen("tramcar.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 离散化非零宝石数
    for (int i = 1; i <= n; i++)
        if (a[i]) val[++tot] = a[i];
    sort(val + 1, val + tot + 1);
    tot = (int)(unique(val + 1, val + tot + 1) - val - 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) { cntEmpty++; continue; }
        rk[i] = (ll)(lower_bound(val + 1, val + tot + 1, a[i]) - val);
    }

    // 二分最小容量：check 关于 M 单调
    ll lo = 0, hi = n;
    while (lo < hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
