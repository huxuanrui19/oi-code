#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353, MAXN = 1005, MAXM = 2015;

//小江提醒：该版本代码要用上玄学卡常技术才能过最后两个点 
 
int n;
int a[MAXN], pos[MAXN];  // a: 最终序列; pos[v]: 值 v 的位置
int bel[MAXN];           // bel[v]: 值 v 属于哪个环
int cyc[2][MAXN];        // cyc: 每个环的元素
int clen[2], ccnt;       // clen: 环长度; ccnt: 环个数
int ori[2];              // ori: 方向 1(顺) / -1(逆) / 0(任意) / 2(非法)
int lab[MAXN];           // lab[v]: 1在顺集合A, 0在逆集合B
int up[MAXM];            // up[e]: 1表示 e 先于 e+1
int C[MAXN][MAXN];       // C: 组合数
int F[MAXM][MAXM];       // F: 区间DP

// ==================== 辅助函数 ====================
int add(int x, int y) { x += y; if (x >= MOD) x -= MOD; return x; }
int mul(long long x, long long y) { return (int)(x * y % MOD); }

// ==================== 模块 1：预处理组合数 ========
void init() {
    for (int i = 0; i <= 1000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
}

// ==================== 模块 2：拆环 ================
// 返回是否恰好拆出 2 个环
bool split() {
    for (int i = 1; i <= n; i++) bel[i] = -1;
    ccnt = 0; clen[0] = clen[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (bel[i] != -1) continue;
        if (ccnt >= 2) return false; // 超过 2 个环直接无解
        
        int j = i;
        while (bel[j] == -1) {
            bel[j] = ccnt;
            cyc[ccnt][clen[ccnt]++] = j;
            j = pos[j];
        }
        ccnt++;
    }
    return ccnt == 2;
}

// ==================== 模块 3：算方向 ================
// 核心：合法同向环的“总步数”必然等于 n
int getOri(int k) {
    int L = clen[k];
    if (L <= 2) return 0; // 长度 1 或 2，顺逆等价

    int s1 = 0, s2 = 0; // s1:顺向总步数, s2:逆向总步数
    for (int t = 0; t < L; t++) {
        int u = cyc[k][t], p = pos[u];
        s1 += (p - u + n) % n;
        s2 += (u - p + n) % n;
    }

    // 当 L > 2 时，s1 和 s2 数学上不可能同时等于 n，直接判断即可
    if (s1 == n) return 1;
    if (s2 == n) return -1;
    return 2; // 步数不对，非法
}

// ==================== 模块 4：建拓扑限制 ==============
// 只需传入顺时针环编号 cw，剩下的自然都是逆时针环
void build(int cw) {
    // 标记 每个元素属于顺时针环还是逆时针环，为后面确定相邻边的先后关系做准备 
    for (int v = 1; v <= n; v++) {
        lab[v] = (bel[v] == cw) ? 1 : 0;
    }
    // 构造 up 数组
    for (int e = 1; e <= 2 * n; e++) {
        int v = (e % n) + 1;
        up[e] = (lab[v] == 0) ? 1 : 0;
    }
}

// ==================== 模块 5：区间DP计算方案数 ==========
int f(int cw, int ccw) {
    // 方向冲突拦截 (ori 为 2 或冲突方向时直接返回)
    if (ori[cw] != 1 && ori[cw] != 0) return 0;
    if (ori[ccw] != -1 && ori[ccw] != 0) return 0;

    build(cw);

    for (int i = 1; i <= 2 * n; i++) F[i][i] = 1;

    // 链上区间 DP
    for (int len = 2; len <= n - 1; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1, s = 0;
            for (int x = i; x <= j; x++) {
                // 1. 前置检查：如果 x 不能作为区间最后使用的边，直接跳过
                // 左边：如果不是左边界，必须满足 up[x-1] == 1
                if (x > i && up[x - 1] != 1) continue;
                // 右边：如果不是右边界，必须满足 up[x] == 0
                if (x < j && up[x] != 0) continue;
                
                // 2. 左右两段的独立方案数（边界情况默认是 1）
                int lv = 1, rv = 1;
                if (x > i) lv = F[i][x - 1];
                if (x < j) rv = F[x + 1][j];
                
                // 3. 合并左右两段（穿插组合数 * 左段方案 * 右段方案）
                int cb = C[len - 1][x - i];
                s = add(s, mul(cb, mul(lv, rv)));
            }
            F[i][j] = s;
        }
    }

    // 环拼接：枚举圆环上最后被操作的那条边
    int res = 0;
    for (int x = 1; x <= n; x++) {
        // 1. 找到 x 的左边那条边
        int pre;
        if (x == 1) pre = n; // 如果是 1 号边，它的左边是环尾的 n 号边
        else pre = x - 1;
        // 2. 检查 x 是否可以是最后一条边 
        // 最后一条边的条件：左边的边要先于 x，右边的边也要先于 x
        if (up[pre] == 1 && up[x] == 0) {
            // 3. 如果 x 是最后一条边，把它拿走，剩下的 n-1 条边变成了一条长链
            // 链的起点是 x+1，终点是 x+n-1
            int L = x + 1;
            int R = x + n - 1;
            res = add(res, F[L][R]);
        }
    }
    return res;
}

int main() {
    int sub, T;
    scanf("%d%d", &sub, &T);
    init();

    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        if (n == 1) { printf("1\n"); continue; }

        for (int i = 1; i <= n; i++) pos[a[i]] = i;

        if (!split()) { printf("0\n"); continue; }

        ori[0] = getOri(0);
        ori[1] = getOri(1);
        if (ori[0] == 2 || ori[1] == 2) { printf("0\n"); continue; }

        int ans = 0;
        ans = add(ans, f(0, 1)); // 假设 0顺 1逆
        ans = add(ans, f(1, 0)); // 假设 1顺 0逆

        printf("%d\n", ans);
    }
    return 0;
}
