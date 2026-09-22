#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = numeric_limits<i64>::max();
i64 add(i64 a, i64 b) {
    if (a == inf || b == inf || a > inf - b)
        return inf;
    return a + b;
}
struct Node {
    int ch[2]{};
    int fail = 0;
    bool bad = false;
};
struct Dep {
    int par, oth, type;
};
int main() {
    freopen("pattern.in", "r", stdin);
    freopen("pattern.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int G, N, M;
    cin >> G >> N >> M;
    vector<pair<int, vector<int>>> rule(N);
    for (auto &item : rule) {
        int &x = item.first;
        vector<int> &v = item.second;
        int k;
        cin >> x >> k;
        v.resize(k);
        for (int &y : v)
            cin >> y;
    }
    vector<Node> ac(1);
    while (M--) {
        int n;
        cin >> n;
        int u = 0;
        while (n--) {
            int x;
            cin >> x;
            if (!ac[u].ch[x]) {
                ac[u].ch[x] = ac.size();
                ac.emplace_back();
            }
            u = ac[u].ch[x];
        }
        ac[u].bad = true;
    }
    queue<int> q;
    for (int i = 0; i < 2; i++) {
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ac[u].bad |= ac[ac[u].fail].bad;
        for (int c = 0; c < 2; c++) {
            int v = ac[u].ch[c];
            if (v) {
                ac[v].fail = ac[ac[u].fail].ch[c];
                q.push(v);
            } else {
                ac[u].ch[c] = ac[ac[u].fail].ch[c];
            }
        }
    }
    vector<pair<int, int>> one;
    vector<array<int, 3>> two;
    int C = G;
    for (auto &item : rule) {
        int x = item.first;
        vector<int> &v = item.second;
        if (v.size() == 1) {
            one.push_back({x, v[0]});
        } else {
            int cur = v[0];
            for (int i = 1; i < (int)v.size(); i++) {
                int p = i + 1 == (int)v.size() ? x : C++;
                two.push_back({p, cur, v[i]});
                cur = p;
            }
        }
    }
    vector<vector<Dep>> dep(C);
    for (const auto &item : one)
        dep[item.second].push_back({item.first, -1, 0});
    for (const auto &item : two) {
        int a = item[0], b = item[1], c = item[2];
        dep[b].push_back({a, c, 1});
        dep[c].push_back({a, b, 2});
    }
    int S = ac.size();
    auto id = [&](int x, int a, int b) {
        return (x * S + a) * S + b;
    };
    vector<i64> dis(C * S * S, inf);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
    auto relax = [&](int x, int a, int b, i64 d) {
        if (ac[a].bad || ac[b].bad || d == inf)
            return;
        int t = id(x, a, b);
        if (d < dis[t]) {
            dis[t] = d;
            pq.push({d, t});
        }
    };
    for (int i = 0; i < S; i++) {
        if (ac[i].bad)
            continue;
        for (int c = 0; c < 2; c++) {
            int j = ac[i].ch[c];
            if (!ac[j].bad)
                relax(c, i, j, 1);
        }
    }
    while (!pq.empty()) {
        pair<i64, int> top = pq.top();
        i64 d = top.first;
        int t = top.second;
        pq.pop();
        if (d != dis[t])
            continue;
        int b = t % S;
        t /= S;
        int a = t % S;
        int x = t / S;
        for (const Dep &item : dep[x]) {
            int par = item.par, oth = item.oth, type = item.type;
            if (type == 0) {
                relax(par, a, b, d);
            } else if (type == 1) {
                for (int c = 0; c < S; c++)
                    relax(par, a, c, add(d, dis[id(oth, b, c)]));
            } else {
                for (int c = 0; c < S; c++)
                    relax(par, c, b, add(dis[id(oth, c, a)], d));
            }
        }
    }
    for (int x = 2; x < G; x++) {
        i64 ans = inf;
        for (int i = 0; i < S; i++)
            ans = min(ans, dis[id(x, 0, i)]);
        if (ans == inf)
            cout << "YES\n";
        else
            cout << "NO " << ans << '\n';
    }
    return 0;
}
