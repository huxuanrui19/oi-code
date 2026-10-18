#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
const int MOD = 1e9 + 7;
int n, q, L, a[N], ans[N << 2];
struct Query{
    int id, l, r;
};
vector<Query> qs;
// pre[i][j][k]：区间 [i,mid] 中值域最小为 j、最大为 k 的合法子序列数
// suf[i][j][k]：区间 [mid+1,i] 中同理
int pre[N][21][21], suf[N][21][21];
int s1[N][21], s2[N][21];

void addmod(int &x, int y){
    x = (x + y) % MOD;
}

void cdq(int l, int r, vector<Query> vec){
    if(vec.empty()) return;
    if(l == r){
        for(int i = 0; i < (int)vec.size(); i++) ans[vec[i].id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    memset(pre[mid + 1], 0, sizeof pre[mid + 1]);
    memset(suf[mid], 0, sizeof suf[mid]);
    for(int i = mid; i >= l; i--){
        for(int j = 0; j <= L; j++)
            for(int k = j; k <= L; k++)
                pre[i][j][k] = pre[i + 1][j][k];
        addmod(pre[i][a[i]][a[i]], 1);
        for(int k = a[i]; k <= L; k++)
            for(int p = k; p <= L; p++)
                addmod(pre[i][a[i]][p], pre[i + 1][k][p]);
    }
    for(int i = mid + 1; i <= r; i++){
        for(int j = 0; j <= L; j++)
            for(int k = j; k <= L; k++)
                suf[i][j][k] = suf[i - 1][j][k];
        addmod(suf[i][a[i]][a[i]], 1);
        for(int k = 0; k <= a[i]; k++)
            for(int p = k; p <= a[i]; p++)
                addmod(suf[i][k][a[i]], suf[i - 1][k][p]);
    }
    for(int i = l; i <= mid; i++) memset(s1[i], 0, sizeof s1[i]);
    for(int i = mid + 1; i <= r; i++) memset(s2[i], 0, sizeof s2[i]);
    for(int i = l; i <= mid; i++)
        for(int j = 0; j <= L; j++)
            for(int k = j; k <= L; k++)
                addmod(s1[i][k], pre[i][j][k]);
    for(int i = mid + 1; i <= r; i++)
        for(int j = 0; j <= L; j++)
            for(int k = j; k <= L; k++)
                addmod(s2[i][j], suf[i][j][k]);
    vector<Query> ql, qr;
    for(int i = 0; i < (int)vec.size(); i++){
        Query w = vec[i];
        if(w.r <= mid) ql.push_back(w);
        else if(w.l > mid) qr.push_back(w);
        else{
            for(int j = 1; j <= L; j++)
                for(int k = j; k <= L; k++){
                    addmod(ans[w.id], pre[w.l][j][k]);
                    addmod(ans[w.id], suf[w.r][j][k]);
                }
            for(int j = 0; j <= L; j++)
                for(int k = j; k <= L; k++)
                    addmod(ans[w.id], (int)((ll)s1[w.l][j] * s2[w.r][k] % MOD));
        }
    }
    cdq(l, mid, ql);
    cdq(mid + 1, r, qr);
}

int main(){
    freopen("subseq.in","r",stdin);
    freopen("subseq.out","w",stdout);
    cin >> n >> L;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        qs.push_back((Query){i, l, r});
    }
    cdq(1, n, qs);
    for(int i = 1; i <= q; i++) printf("%d\n", (ans[i] + 1) % MOD);
    return 0;
}
