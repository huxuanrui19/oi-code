# -*- coding: utf-8 -*-
# 验证对 20261011 模拟赛标程算法的理解是否正确
import itertools, random, heapq

MOD = 10**9 + 7

# ---------- A: 消消乐 ----------
def std_a(s):
    ans = cnt = tot = 0
    for ch in s:
        if ch == 'A': cnt += 1
        if ch == 'B' and cnt: cnt -= 1; ans += 1
        if ch == 'B': tot += 1
    cnt = 0
    for ch in reversed(s):
        if ch == 'C': cnt += 1
        if ch == 'B' and cnt: cnt -= 1; ans += 1
    return min(ans, tot)

def brute_a(s):
    # BFS 求最大操作数；操作：删 AB(A 在 B 前) 或删 BC(B 在 C 前)
    from functools import lru_cache
    @lru_cache(maxsize=None)
    def f(t):
        best = 0
        for i in range(len(t)):
            for j in range(i+1, len(t)):
                if t[i] == 'A' and t[j] == 'B':
                    best = max(best, 1 + f(t[:i] + t[i+1:j] + t[j+1:]))
                if t[i] == 'B' and t[j] == 'C':
                    best = max(best, 1 + f(t[:i] + t[i+1:j] + t[j+1:]))
        return best
    return f(s)

ok = True
for _ in range(300):
    n = random.randint(1, 9)
    s = ''.join(random.choice('ABC') for _ in range(n))
    if std_a(s) != brute_a(s):
        print("A MISMATCH", s, std_a(s), brute_a(s)); ok = False; break
print("A:", "OK" if ok else "FAIL")

# ---------- C: 子序列（猜：统计非降子序列个数，含空） ----------
def std_c(a, L, queries):
    n = len(a) - 1
    ans = [0] * (len(queries) + 2)
    pre = [[[0]*(L+1) for _ in range(L+1)] for _ in range(n+2)]
    suf = [[[0]*(L+1) for _ in range(L+1)] for _ in range(n+2)]
    s1 = [[0]*(L+1) for _ in range(n+2)]
    s2 = [[0]*(L+1) for _ in range(n+2)]
    def cdq(l, r, V):
        if not V: return
        if l == r:
            for (i, ql, qr) in V: ans[i] = 1
            return
        mid = (l + r) // 2
        for j in range(L+1):
            for k in range(L+1):
                pre[mid+1][j][k] = 0; suf[mid][j][k] = 0
        for i in range(mid, l-1, -1):
            for j in range(L+1):
                for k in range(j, L+1):
                    pre[i][j][k] = pre[i+1][j][k]
            pre[i][a[i]][a[i]] = (pre[i][a[i]][a[i]] + 1) % MOD
            for k in range(a[i], L+1):
                for p in range(k, L+1):
                    pre[i][a[i]][p] = (pre[i][a[i]][p] + pre[i+1][k][p]) % MOD
        for i in range(mid+1, r+1):
            for j in range(L+1):
                for k in range(j, L+1):
                    suf[i][j][k] = suf[i-1][j][k]
            suf[i][a[i]][a[i]] = (suf[i][a[i]][a[i]] + 1) % MOD
            for k in range(0, a[i]+1):
                for p in range(k, a[i]+1):
                    suf[i][k][a[i]] = (suf[i][k][a[i]] + suf[i-1][k][p]) % MOD
        for i in range(l, mid+1):
            for j in range(L+1): s1[i][j] = 0
        for i in range(mid+1, r+1):
            for j in range(L+1): s2[i][j] = 0
        for i in range(l, mid+1):
            for j in range(L+1):
                for k in range(j, L+1):
                    s1[i][k] = (s1[i][k] + pre[i][j][k]) % MOD
        for i in range(mid+1, r+1):
            for j in range(L+1):
                for k in range(j, L+1):
                    s2[i][j] = (s2[i][j] + suf[i][j][k]) % MOD
        ql, qr = [], []
        for (i, wl, wr) in V:
            if wr <= mid: ql.append((i, wl, wr))
            elif wl > mid: qr.append((i, wl, wr))
            else:
                for x in range(1, L+1):
                    for y in range(x, L+1):
                        ans[i] = (ans[i] + pre[wl][x][y]) % MOD
                        ans[i] = (ans[i] + suf[wr][x][y]) % MOD
                for j in range(0, L+1):
                    for k in range(j, L+1):
                        ans[i] = (ans[i] + s1[wl][j] * s2[wr][k]) % MOD
        cdq(l, mid, ql); cdq(mid+1, r, qr)
    cdq(1, n, [(i+1, l, r) for i, (l, r) in enumerate(queries)])
    return [(ans[i+1] + 1) % MOD for i in range(len(queries))]

def brute_c(a, queries):
    res = []
    for (l, r) in queries:
        cnt = 1  # 空序列
        seg = a[l:r+1]
        for masksize in range(1, len(seg)+1):
            for comb in itertools.combinations(range(len(seg)), masksize):
                vals = [seg[i] for i in comb]
                if all(vals[i] <= vals[i+1] for i in range(len(vals)-1)):
                    cnt += 1
        res.append(cnt % MOD)
    return res

ok = True
for _ in range(200):
    n = random.randint(1, 7)
    L = random.randint(1, 4)
    a = [0] + [random.randint(1, L) for _ in range(n)]
    qs = []
    for _ in range(random.randint(1, 5)):
        l = random.randint(1, n); r = random.randint(l, n)
        qs.append((l, r))
    x, y = std_c(a, L, qs), brute_c(a, qs)
    if x != y:
        print("C MISMATCH", a, qs, x, y); ok = False; break
print("C:", "OK" if ok else "FAIL")

# ---------- B: 修路 ----------
# 假设1：选边的子集，要求 建成图任意两点最短路 <= 原图最短路，最小化总代价
def std_b(n, edges):
    # edges: list of (u, v, l, c), 1-indexed vertices
    G = [[] for _ in range(n+1)]
    fa = list(range(n+1))
    def find(x):
        while fa[x] != x:
            fa[x] = fa[fa[x]]; x = fa[x]
        return x
    ans = 0
    chosen = [False]*len(edges)
    e0 = sorted([(u, v, c) for (u, v, l, c) in edges if l == 0], key=lambda e: e[2])
    for (u, v, c) in e0:
        fu, fv = find(u), find(v)
        if fu == fv: continue
        fa[fu] = fv; ans += c
    pos_edges = [(i, u, v, l, c) for i, (u, v, l, c) in enumerate(edges) if l != 0]
    INF = float('inf')
    def dij(s):
        dis = [INF]*(n+1); vis = [False]*(n+1)
        dis[s] = 0; pq = [(0, s)]
        while pq:
            d, u = heapq.heappop(pq)
            if vis[u]: continue
            vis[u] = True
            for (v, w) in G[u]:
                if not vis[v] and d + w < dis[v]:
                    dis[v] = d + w; heapq.heappush(pq, (dis[v], v))
        return dis
    for (i, u, v, l, c) in sorted(pos_edges, key=lambda e: (e[3], e[4])):
        nu, nv = find(u), find(v)
        if l < dij(nu)[nv]:
            G[nu].append((nv, l)); G[nv].append((nu, l))
            ans += c
    return ans

def brute_b(n, edges, mode):
    import itertools
    # 原图最短路
    INF = float('inf')
    def alldis(E):
        d = [[INF]*(n+1) for _ in range(n+1)]
        for i in range(1, n+1): d[i][i] = 0
        for (u, v, l) in E:
            if l < d[u][v]: d[u][v] = d[v][u] = l
        for k in range(1, n+1):
            for i in range(1, n+1):
                for j in range(1, n+1):
                    if d[i][k] + d[k][j] < d[i][j]:
                        d[i][j] = d[i][k] + d[k][j]
        return d
    orig = alldis([(u, v, l) for (u, v, l, c) in edges])
    best = INF
    m = len(edges)
    for mask in range(1 << m):
        E, cost = [], 0
        for i in range(m):
            if mask >> i & 1:
                E.append((edges[i][0], edges[i][1], edges[i][2])); cost += edges[i][3]
        if cost >= best: continue
        d = alldis(E)
        good = True
        for i in range(1, n+1):
            for j in range(1, n+1):
                if orig[i][j] < INF and d[i][j] > orig[i][j]:
                    good = False; break
            if not good: break
        if mode == 'dominate' and good:
            best = cost
        if mode == 'connect':
            # 连通即可（0 长度边连通）—— 不可能，直接跳过
            pass
    return best

ok = True
for _ in range(60):
    n = random.randint(2, 5)
    m = random.randint(1, 6)
    edges = []
    for _ in range(m):
        u = random.randint(1, n); v = random.randint(1, n)
        while v == u: v = random.randint(1, n)
        l = random.randint(0, 4)
        c = random.randint(1, 10)
        edges.append((u, v, l, c))
    x = std_b(n, edges)
    y = brute_b(n, edges, 'dominate')
    if x != y:
        print("B MISMATCH", n, edges, "std=", x, "brute=", y); ok = False; break
print("B (最短路不超过原图 hypothesis):", "OK" if ok else "FAIL")
