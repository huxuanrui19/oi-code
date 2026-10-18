#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const ll INF = (ll)1e18;
int n, m;
ll A[N], B[N], S[N], T[N], P[N], Q[N];
vector<int> pos[N];

// 线段树维护 dp 值，支持区间加、区间 chmax（chmax 的值依赖左区间的最大值）
ll tr[N << 2], lzadd[N << 2], lztag[N << 2];
bool mark[N << 2];

void apply(int o, ll v, ll M){
    tr[o] = max(tr[o] + v, M);
    lzadd[o] += v;
    lztag[o] += v;
    lztag[o] = max(lztag[o], M);
}
void pushdown(int o){
    apply(o << 1, lzadd[o], lztag[o]);
    apply(o << 1 | 1, lzadd[o], lztag[o]);
    lzadd[o] = 0;
    lztag[o] = -INF;
    if(mark[o]){
        mark[o << 1] = mark[o << 1 | 1] = true;
        mark[o] = false;
        apply(o << 1 | 1, 0, tr[o << 1]);
    }
}
void pull(int o){
    tr[o] = max(tr[o << 1], tr[o << 1 | 1]);
}
void build(int o, int l, int r){
    mark[o] = false;
    lztag[o] = -INF;
    if(l == r){
        tr[o] = (l == 0 ? 0 : -INF);
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    pull(o);
}
void range_add(int o, int l, int r, int x, int y, ll v){
    if(x <= l && r <= y) return apply(o, v, -INF);
    if(r < x || l > y) return;
    pushdown(o);
    int mid = (l + r) >> 1;
    range_add(o << 1, l, mid, x, y, v);
    range_add(o << 1 | 1, mid + 1, r, x, y, v);
    pull(o);
}
ll query(int o, int l, int r, int p){
    if(l == r) return tr[o];
    int mid = (l + r) >> 1;
    pushdown(o);
    return p <= mid ? query(o << 1, l, mid, p) : query(o << 1 | 1, mid + 1, r, p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i] >> S[i] >> P[i];
    for(int j = 1; j <= m; j++) cin >> B[j] >> T[j] >> Q[j];
    for(int i = 1; i <= n; i++) A[i] += A[i - 1];
    for(int j = 1; j <= m; j++) B[j] += B[j - 1];
    build(1, 0, m);
    for(int j = 1; j <= m; j++){
        range_add(1, 0, m, j, m, -Q[j]);
        int t = upper_bound(A, A + n + 1, T[j] - B[j]) - A;
        pos[t].push_back(j);
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < (int)pos[i].size(); j++)
            range_add(1, 0, m, pos[i][j], m, Q[pos[i][j]]);
        mark[1] = true;
        if(i != n){
            int t = upper_bound(B, B + m + 1, S[i + 1] - A[i + 1]) - B - 1;
            if(t >= 0) range_add(1, 0, m, 0, t, P[i + 1]);
        }
    }
    for(int j = 0; j < (int)pos[n + 1].size(); j++)
        range_add(1, 0, m, pos[n + 1][j], m, Q[pos[n + 1][j]]);
    cout << query(1, 0, m, m);
    return 0;
}
