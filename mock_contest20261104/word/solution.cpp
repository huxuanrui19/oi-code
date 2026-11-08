#include <bits/stdc++.h>
using namespace std;

// Exact base-30 keys (m <= 6); collisions are resolved by comparing keys.
// Two flat uint32_t arrays use at most 32 MiB under the original 64 MB limit.
class Counter {
    vector<uint32_t> keys, values;
    size_t mask;
    uint64_t salt;

    size_t bucket(uint32_t key) const {
        uint64_t x = key + salt;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return (x ^ (x >> 31)) & mask;
    }
public:
    explicit Counter(size_t max_keys) {
        size_t capacity = 1;
        while (capacity < max_keys + (max_keys + 3) / 4) capacity <<= 1;
        keys.assign(capacity, 0);
        values.assign(capacity, 0);
        mask = capacity - 1;
        salt = chrono::steady_clock::now().time_since_epoch().count();
    }

    uint32_t get(uint32_t key) const {
        ++key; // Zero is the empty-bucket marker; the all-'a' key is valid.
        size_t i = bucket(key);
        while (keys[i] != 0 && keys[i] != key) i = (i + 1) & mask;
        return keys[i] == key ? values[i] : 0;
    }

    void add(uint32_t key) {
        ++key;
        size_t i = bucket(key);
        while (keys[i] != 0 && keys[i] != key) i = (i + 1) & mask;
        keys[i] = key;
        ++values[i];
    }
};

void insert_word(Counter &counts, const string &s, int pos, uint32_t key) {
    if (pos == int(s.size())) {
        counts.add(key);
        return;
    }
    if (s[pos] == '?') {
        insert_word(counts, s, pos + 1, key * 30 + 27);
    } else {
        insert_word(counts, s, pos + 1, key * 30 + s[pos] - 'a');
        insert_word(counts, s, pos + 1, key * 30 + 26);
    }
}

long long query(const Counter &counts, const string &s, int pos, uint32_t key) {
    if (pos == int(s.size())) return counts.get(key);
    int symbol = s[pos] == '?' ? 26 : s[pos] - 'a';
    return query(counts, s, pos + 1, key * 30 + symbol)
         + query(counts, s, pos + 1, key * 30 + 27);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    Counter counts(size_t(n) << m);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ans += query(counts, s, 0, 0);
        insert_word(counts, s, 0, 0);
    }
    cout << ans << '\n';
    return 0;
}
