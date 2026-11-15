#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll s;
    cin >> n >> s;

    unordered_map<ll, vector<int>> idx;   // 值 -> 下标列表
    unordered_map<ll, int> cnt;           // 值 -> 剩余个数
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        ll w = (a + 1) % s;
        idx[w].push_back(i);
        cnt[w]++;
    }

    priority_queue<pair<int, ll>> pq;     // (剩余个数, 值) 大根堆，按个数优先
    for (auto &kv : cnt) pq.push({kv.second, kv.first});

    ll cur = 0, ans = 0;
    vector<int> order; order.reserve(n);

    while (!pq.empty()) {
        if (cur == s - 1) cur = 0, ans++;          // 被迫空行
        auto d = pq.top(); pq.pop();
        int c = d.first; ll v = d.second;
        if (pq.empty() || (cur + v) % s != s - 1) {  // 只剩一种值，或 v 安全
            cur = (cur + v) % s;
            order.push_back(idx[v].back()); idx[v].pop_back();
            if (--c) pq.push({c, v});
        } else {                                      // v 会空行 -> 取次数第二多（一定安全）
            auto t = pq.top(); pq.pop();
            pq.push(d);                               // v 放回
            int c2 = t.first; ll v2 = t.second;
            cur = (cur + v2) % s;
            order.push_back(idx[v2].back()); idx[v2].pop_back();
            if (--c2) pq.push({c2, v2});
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << order[i] << " \n"[i == n - 1];
    return 0;
}
