// crystal —— 水晶序列
//
// 模型：一次删除 = 左边的字符吞掉紧邻的右边字符（A[i][j]=1 表示类型 i 可吞类型 j）。
//
// 第一步：删除森林。从右往左用栈扫描：
//   处理 i 时弹出所有能被 s_i 删除的栈顶 j（fa[j] = i，即 i 直接删除 j），
//   弹完后的栈顶 nx[i] 就是" i 删完一段后右侧第一个幸存位置"。
//   栈的"后缀一致"性质保证：从 i 出发能转移到的下一个保留位置，
//   恰好是 G[i]（i 删除的位置集合）中各点 v 的最优后继 f[v]。
//
// 第二步：DP。f[i] = 以 i 为首个保留位置时，最优的下一个保留位置：
//   候选 = { i+1 }（一个都不删）∪ { f[v] : v ∈ G[i] }（删除 i 与 v 之间的整段），
//   取"从该位置开始的最优串"字典序最小者。答案沿 1 -> f[1] -> f[f[1]] -> ... 输出。
//
// 第三步：比较两条候选链的字典序。
//   g[i] 即链 i, f[i], f[f[i]], ... 上的字符序列。
//   二进制提升 + 双哈希：f[i][j] = 沿链走 2^j 步的位置，h[i][j] = 这段 2^j 个字符的哈希。
//   从高位到低位同时跳两条链，哈希相等则跳过，首个不同字符决定大小，单次比较 O(log n)。
//
// 复杂度：O(n log n) 预处理，候选总数 O(n)，总复杂度 O(n log n) ~ O(n log^2 n)。

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;
const int LOG = 19;                    // 2^18 = 262144 < 5e5 < 2^19
const ll BASE = 131;
// 双哈希模数：M = 998244353 * 1e9+7（两素数乘积，用 __int128 取模）
const ll MOD = 998244353LL * 1000000007LL;

int k, n;
int mat[26][26];
char s[MAXN];

vector<int> child[MAXN];               // G[i]：被 i 直接删除的位置（从右往左弹出，倒序）
int nx[MAXN];                          // nx[i]：i 右侧第一个幸存位置（哨兵 n+1）
int stk[MAXN], top;

int f[MAXN][LOG];                      // f[i][j]：i 沿链走 2^j 步（0 表示链结束）
ll h[MAXN][LOG];                       // h[i][j]：这段 2^j 个字符的双哈希
ll pw[LOG];                            // pw[j] = BASE^(2^j) mod MOD

// 比较"从 x 开始的链"与"从 y 开始的链"的字典序，返回较优（字典序更小）的起点
int better(int x, int y) {
    int sx = x, sy = y;                // 记住原起点
    for (int j = LOG - 1; j >= 0; j--) {
        if (f[x][j] && f[y][j] && h[x][j] == h[y][j]) {
            x = f[x][j];
            y = f[y][j];               // 前 2^j 个字符相同，同步跳过
        }
    }
    // 此刻 s[x] != s[y]（或其一为链尾 0），首字符小者整条链更小
    return (s[x] < s[y]) ? sx : sy;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            char ch;
            cin >> ch;
            mat[i][j] = ch - '0';
        }
    cin >> (s + 1);
    for (int i = 1; i <= n; i++) s[i] -= 'a';

    // pw[j] = BASE^(2^j) mod MOD（用 __int128 防溢出）
    pw[0] = BASE;
    for (int j = 1; j < LOG; j++)
        pw[j] = (ll)((__int128)pw[j - 1] * pw[j - 1] % MOD);

    // 第一步：从右往左栈扫描，建删除森林
    stk[0] = n + 1;                    // 栈底哨兵：nx 的终点
    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && mat[s[i]][s[stk[top]]]) {
            int j = stk[top--];        // j 被 i 直接删除
            child[i].push_back(j);
        }
        nx[i] = stk[top];
        stk[++top] = i;
    }

    // 第二步 + 第三步：倒序 DP（此时所有 v > i 的 f[v][*] 已就绪）
    for (int i = n; i >= 1; i--) {
        int best = i + 1;              // 一个都不删的候选
        for (int v : child[i])
            if (v != n + 1)            // 哨兵不参与转移
                best = better(best, f[v][0]);
        f[i][0] = best;
        h[i][0] = (ll)s[i] + 1000000;  // 单字符哈希（加偏移避免前导零歧义）
        for (int j = 1; j < LOG; j++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            h[i][j] = (ll)((__int128)h[i][j - 1] * pw[j - 1] % MOD
                         + h[f[i][j - 1]][j - 1]) % MOD;
        }
    }

    // 输出：1 号位置必定保留，沿 f 链输出
    for (int i = 1; i != n + 1; i = f[i][0])
        putchar(s[i] + 'a');
    putchar('\n');
    return 0;
}
