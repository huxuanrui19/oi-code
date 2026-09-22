#include <bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define LL long long
using namespace std;
const int maxn = 100010;
const LL mod = 1000000007;

struct node {
	int x, y, rank;
};

bool cmp1(node x, node y) {
	return x.x == y.x ? x.y < y.y : x.x < y.x;
}

bool cmp2(node x, node y) {
	return x.y == y.y ? x.x < y.x : x.y < y.y;
}
node a[maxn];

struct SegementTree {
	LL sum, cnt, lz;
};
SegementTree tr[maxn * 4];

LL qpow(LL x, LL y) {
	LL ans = 1;
	for (; y; y >>= 1) {
		if (y & 1)
			ans = (ans * x) % mod;
		x = (x * x) % mod;
	}
	return ans;
}

void pushup(int x) {
	tr[x].sum = (tr[ls(x)].sum + tr[rs(x)].sum) % mod;
	tr[x].cnt = (tr[ls(x)].cnt + tr[rs(x)].cnt) % mod;
}

void maintain(int x, int y) {
	tr[x].sum = (tr[x].sum * qpow(2, y)) % mod;
	tr[x].lz += y;
}

void pushdown(int x) {
	if (tr[x].lz) {
		if (tr[ls(x)].cnt)
			maintain(ls(x), tr[x].lz);
		if (tr[rs(x)].cnt)
			maintain(rs(x), tr[x].lz);
		tr[x].lz = 0;
	}
}

void build(int x, int l, int r) {
	if (l == r) {
		tr[x].sum = tr[x].cnt = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(x), l, mid);
	build(rs(x), mid + 1, r);
	pushup(x);
}

void update_cnt(int x, int l, int r, int pos, int y, int z) {
	if (l == r) {
		tr[x].cnt = 1;
		tr[x].sum = (qpow(2, y) * qpow(2, z)) % mod;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if (pos <= mid)
		update_cnt(ls(x), l, mid, pos, y, z);
	else
		update_cnt(rs(x), mid + 1, r, pos, y, z);
	pushup(x);
}

void update_sum(int x, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		tr[x].lz++;
		tr[x].sum = (tr[x].sum * 2) % mod;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if (ql <= mid)
		update_sum(ls(x), l, mid, ql, qr);
	if (qr > mid)
		update_sum(rs(x), mid + 1, r, ql, qr);
	pushup(x);
}

LL query_cnt(int x, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		return tr[x].cnt;
	}
	int mid = (l + r) >> 1;
	pushdown(x);
	LL ans = 0;
	if (ql <= mid)
		ans += query_cnt(ls(x), l, mid, ql, qr);
	if (qr > mid)
		ans += query_cnt(rs(x), mid + 1, r, ql, qr);
	return ans;
}

LL query_sum(int x, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		return tr[x].sum;
	}
	int mid = (l + r) >> 1;
	LL ans = 0;
	pushdown(x);
	if (ql <= mid)
		ans += query_sum(ls(x), l, mid, ql, qr);
	if (qr > mid)
		ans += query_sum(rs(x), mid + 1, r, ql, qr);
	return ans % mod;
}

int main() {
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a + 1, a + 1 + n, cmp1);
		for (int i = 1; i <= n; i++) {
			a[i].rank = i;
		}
		sort(a + 1, a + 1 + n, cmp2);
		build(1, 1, n);
		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			LL tmp = query_cnt(1, 1, n, 1, a[i].rank);
			update_cnt(1, 1, n, a[i].rank, tmp, a[i].x);
			ans = (ans + query_sum(1, 1, n, a[i].rank, n) * qpow(3, a[i].y) % mod) % mod;
			if (a[i].rank != n)
				update_sum(1, 1, n, a[i].rank + 1, n);
		}
		printf("%lld\n", ans);
	}
}