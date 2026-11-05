#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
const int INF = 1e9;

int n, a[N], d[N];
priority_queue<int> q;

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) tot += a[i];
    }

    for (int i = 1; i <= n; i++) d[i] = a[i] == -1 ? 0 : INF;
    for (int i = 2; i <= n; i++) d[i] = min(d[i], d[i - 1] + 1);
    for (int i = n - 1; i >= 1; i--) d[i] = min(d[i], d[i + 1] + 1);

    ll sum = 0;
    int ans = 0, last = 0;
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        last = min(last, d[i]);
        if (a[i] == 0) continue;
        if (a[i] == -1) {
            if (flag) ans++, flag = false;
            continue;
        }

        // 把上一家店的最后一颗糖改成普通糖果
        if (flag) {
            swap(last, d[i]);
            if ((sum + d[i]) * 2 <= i - 1) {
                sum += d[i];
                q.push(d[i]);
                ans++;
                flag = false;
            } else if (!q.empty() && d[i] <= q.top()) {
                int x = q.top();
                q.pop();
                ans--;
                sum -= x;
                sum += d[i];
                q.push(d[i]);
                ans++;
                d[i] = x;
            }
            swap(last, d[i]);
        }

        // 先处理普通糖果，再处理本店最后一颗糖果
        for (int j = 1; j < a[i]; j++) {
            if ((sum + d[i]) * 2 <= i - 1) {
                sum += d[i];
                q.push(d[i]);
                ans++;
            } else if (!q.empty() && d[i] <= q.top()) {
                int x = q.top();
                q.pop();
                ans--;
                sum -= x;
                flag = true;
                last = x;
                sum += d[i];
                q.push(d[i]);
                ans++;
            } else break;
        }

        if (!flag) flag = true, last = d[i];
        else last = min(last, d[i]);
    }

    cout << tot - ans - flag << '\n';
    return 0;
}
