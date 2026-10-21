// median —— 中位数分割
//
// 结论：设 pre[i] = a[1..i] 的中位数（i 为奇数），suf[i] = a[i..n] 的中位数（n-i+1 为奇数）。
// 存在合法分割  <=>  存在奇数 i 满足 pre[i] == suf[i+1]。
//
// 引理：三段长度均为奇数、中位数均为 m 的序列拼接后，中位数仍为 m。
//   （拼接后长度仍为奇数；小于 m 的元素至多占一半，大于 m 的同理，故第 k 大恰为 m。）
// 证明：n 为偶数，合法分割的段数 k 为偶数且 k >= 2。取第一刀 i（i 为奇数）：
//   第一段中位数为 m；后面所有段拼起来（奇数个奇数段）中位数也为 m，
//   于是只需验证"两段"即可。反之若 pre[i] == suf[i+1] = m，直接把 a 切成
//   a[1..i] 与 a[i+1..n] 这两段（长度均为奇数），由引理它们的中位数都是 m。
//
// 实现：对顶堆 O(n log n) 递推所有奇数位置的 pre / suf。
//   pre：大根堆 p 存较小的一半，小根堆 q 存较大的一半，|p| = |q| + 1，堆顶即中位数。
//   每两步加入两个元素后重平衡一次。

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n;
ll a[MAXN];
ll pre[MAXN], suf[MAXN];

// 对顶堆：p 大根堆（存较小半），q 小根堆（存较大半），保持 |p| = |q| + 1
priority_queue<ll> p;
priority_queue<ll, vector<ll>, greater<ll>> q;

// 把两个新元素 x, y 加入对顶堆并重新平衡，堆顶 p.top() 即当前中位数
void pushPair(ll x, ll y) {
    if (x > p.top()) q.push(x); else p.push(x);
    if (y > p.top()) q.push(y); else p.push(y);
    while (p.size() > q.size() + 1) q.push(p.top()), p.pop();
    while (p.size() < q.size() + 1) p.push(q.top()), q.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // pre[i]：前缀 a[1..i] 的中位数，i 为奇数
    p.push(a[1]);
    pre[1] = a[1];
    for (int i = 3; i <= n; i += 2) {
        pushPair(a[i - 1], a[i]);
        pre[i] = p.top();
    }

    // suf[i]：后缀 a[i..n] 的中位数，n - i + 1 为奇数
    while (!p.empty()) p.pop();
    while (!q.empty()) q.pop();
    p.push(a[n]);
    suf[n] = a[n];
    for (int i = n - 2; i >= 1; i -= 2) {
        pushPair(a[i], a[i + 1]);
        suf[i] = p.top();
    }

    // 存在奇数切点 i：pre[i] == suf[i+1]
    for (int i = 1; i <= n; i += 2) {
        if (pre[i] == suf[i + 1]) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
