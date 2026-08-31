#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

struct FhqTreap {
    struct Node {
        int val, siz, l, r;
        unsigned pri;
    };

    vector<Node> tr;
    int root;
    mt19937 rng;

    FhqTreap() : tr(1), root(0), rng((unsigned)chrono::steady_clock::now().time_since_epoch().count()) {}

    void reserve(int n) {
        tr.reserve(n + 1);
    }

    int size(int p) const {
        return p ? tr[p].siz : 0;
    }

    int new_node(int val) {
        tr.push_back({val, 1, 0, 0, rng()});
        return (int)tr.size() - 1;
    }

    void push_up(int p) {
        if (p) tr[p].siz = size(tr[p].l) + size(tr[p].r) + 1;
    }

    void split(int p, long long val, int &x, int &y) {
        if (!p) {
            x = y = 0;
            return;
        }
        if (tr[p].val <= val) {
            x = p;
            split(tr[p].r, val, tr[p].r, y);
            push_up(x);
        } else {
            y = p;
            split(tr[p].l, val, x, tr[p].l);
            push_up(y);
        }
    }

    int merge(int x, int y) {
        if (!x || !y) return x | y;
        if (tr[x].pri < tr[y].pri) {
            tr[x].r = merge(tr[x].r, y);
            push_up(x);
            return x;
        }
        tr[y].l = merge(x, tr[y].l);
        push_up(y);
        return y;
    }

    void insert(int val) {
        int x, y;
        split(root, val, x, y);
        root = merge(merge(x, new_node(val)), y);
    }

    void erase(int val) {
        int x, y, z;
        split(root, val, x, z);
        split(x, val - 1LL, x, y);
        if (y) y = merge(tr[y].l, tr[y].r);
        root = merge(merge(x, y), z);
    }

    int rank_of(int val) {
        int x, y;
        split(root, val - 1LL, x, y);
        int ans = size(x) + 1;
        root = merge(x, y);
        return ans;
    }

    int kth(int p, int k) const {
        while (p) {
            int left_size = size(tr[p].l);
            if (k <= left_size) {
                p = tr[p].l;
            } else if (k == left_size + 1) {
                return tr[p].val;
            } else {
                k -= left_size + 1;
                p = tr[p].r;
            }
        }
        return 0;
    }

    int kth(int k) const {
        return kth(root, k);
    }

    int predecessor(int val) {
        int x, y;
        split(root, val - 1LL, x, y);
        int ans = kth(x, size(x));
        root = merge(x, y);
        return ans;
    }

    int successor(int val) {
        int x, y;
        split(root, val, x, y);
        int ans = kth(y, 1);
        root = merge(x, y);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    FhqTreap treap;
    treap.reserve(n);
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            treap.insert(x);
        } else if (op == 2) {
            treap.erase(x);
        } else if (op == 3) {
            cout << treap.rank_of(x) << "\n";
        } else if (op == 4) {
            cout << treap.kth(x) << "\n";
        } else if (op == 5) {
            cout << treap.predecessor(x) << "\n";
        } else if (op == 6) {
            cout << treap.successor(x) << "\n";
        }
    }
    return 0;
}
