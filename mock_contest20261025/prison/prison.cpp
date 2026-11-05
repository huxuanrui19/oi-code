#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("prison.in", "r", stdin);
    freopen("prison.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, T;
    cin >> n >> d >> T;
    vector<int> t(n + 1), l(n + 1), fa(n + 1);
    vector<int> son(n + 1), mx(n + 1), stk;
    for (int i = 1; i <= n; i++) cin >> t[i];

    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (t[i] <= T) {
            while (!stk.empty() && t[stk.back()] + i - stk.back() >= t[i])
                stk.pop_back();
            stk.push_back(i);
        } else {
            while (!stk.empty() && t[stk.back()] + i - stk.back() > T)
                stk.pop_back();
            if (stk.empty()) ans--;
            else l[i] = stk.back();
        }
    }

    // 所有区间只会包含或不相交，按包含关系建成森林
    stk.clear();
    for (int i = n; i >= 1; i--) {
        if (!l[i]) continue;
        while (!stk.empty() && l[stk.back()] > l[i]) stk.pop_back();
        if (!stk.empty()) fa[i] = stk.back();
        stk.push_back(i);
    }

    // 父亲的编号一定更大，可以直接递推长链
    for (int i = 1; i <= n; i++) {
        if (l[i]) mx[i] = 1;
        if (fa[i] && mx[i] + 1 > mx[fa[i]]) {
            mx[fa[i]] = mx[i] + 1;
            son[fa[i]] = i;
        }
    }

    vector<int> len;
    for (int i = 1; i <= n; i++) {
        if (!l[i] || (fa[i] && son[fa[i]] == i)) continue;
        int x = 0;
        for (int u = i; u; u = son[u]) x++;
        len.push_back(x);
    }

    int k = min(d, (int)len.size());
    if (k < (int)len.size())
        nth_element(len.begin(), len.begin() + k, len.end(), greater<int>());
    for (int i = 0; i < k; i++) ans -= len[i];
    cout << ans << '\n';
    return 0;
}
