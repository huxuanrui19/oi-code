#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            // 包含该相邻对的子段数目为 (i+1) * (n - (i+1))
            total += (long long)(i + 1) * (n - (i + 1));
        }
    }

    cout << total << '\n';

    return 0;
}
