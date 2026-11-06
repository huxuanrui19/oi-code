#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans;
unordered_map<long long, int> mp;

void add(const string &s, int pos, long long key) {
    if (pos == m) {
        mp[key]++;
        return;
    }
    if (s[pos] == '?') {
        add(s, pos + 1, key * 30 + 27);
    } else {
        add(s, pos + 1, key * 30 + s[pos] - 'a');
        add(s, pos + 1, key * 30 + 26);
    }
}

void query(const string &s, int pos, long long key) {
    if (pos == m) {
        auto it = mp.find(key);
        if (it != mp.end()) ans += it->second;
        return;
    }
    if (s[pos] == '?') {
        query(s, pos + 1, key * 30 + 26);
    } else {
        query(s, pos + 1, key * 30 + s[pos] - 'a');
    }
    query(s, pos + 1, key * 30 + 27);
}

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        query(s, 0, 0);
        add(s, 0, 0);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
