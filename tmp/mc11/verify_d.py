# -*- coding: utf-8 -*-
# 验证 D：标程线段树模拟 vs O(nm) 暴力 DP
import random

def std_d(aA, S, P, aB, T, Q):
    # C++ 标程先做前缀和
    A = aA[:]; B = aB[:]
    for i in range(1, len(A)): A[i] += A[i-1]
    for j in range(1, len(B)): B[j] += B[j-1]
    n, m = len(A) - 1, len(B) - 1
    INF = float('inf')
    NEG = -10**30
    size = 4 * (m + 2) + 5
    tr = [0]*size; lzadd = [0]*size; lztag = [NEG]*size; mark = [False]*size

    def apply(o, v, M):
        tr[o] = max(tr[o] + v, M)
        lzadd[o] += v
        lztag[o] += v
        lztag[o] = max(lztag[o], M)
    def pushdown(o):
        apply(o*2, lzadd[o], lztag[o])
        apply(o*2+1, lzadd[o], lztag[o])
        lzadd[o] = 0; lztag[o] = NEG
        if mark[o]:
            mark[o*2] = mark[o*2+1] = True
            mark[o] = False
            apply(o*2+1, 0, tr[o*2])
    def pull(o):
        tr[o] = max(tr[o*2], tr[o*2+1])
    def build(o, l, r):
        mark[o] = False; lztag[o] = NEG
        if l == r:
            tr[o] = 0 if l == 0 else NEG
            return
        mid = (l+r)//2
        build(o*2, l, mid); build(o*2+1, mid+1, r)
        pull(o)
    def range_add(o, l, r, x, y, v):
        if x <= l and r <= y: return apply(o, v, NEG)
        if r < x or l > y: return
        pushdown(o)
        mid = (l+r)//2
        range_add(o*2, l, mid, x, y, v)
        range_add(o*2+1, mid+1, r, x, y, v)
        pull(o)
    def query(o, l, r, p):
        if l == r: return tr[o]
        mid = (l+r)//2
        pushdown(o)
        return query(o*2, l, mid, p) if p <= mid else query(o*2+1, mid+1, r, p)

    build(1, 0, m)
    from bisect import bisect_right
    qwq = [[] for _ in range(n + 2)]
    for j in range(1, m+1):
        range_add(1, 0, m, j, m, -Q[j])
        t = bisect_right([A[0]] + [A[i] for i in range(1, n+1)], T[j] - B[j])
        # upper_bound(A, A+n+1, key) - A = bisect_right：含 A[0]=0 共 n+1 个元素
        qwq[t].append(j)
    for i in range(0, n+1):
        for j in qwq[i]:
            range_add(1, 0, m, j, m, Q[j])
        mark[1] = True
        if i != n:
            t = bisect_right([B[0]] + [B[i] for i in range(1, m+1)], S[i+1] - A[i+1]) - 1
            if t >= 0: range_add(1, 0, m, 0, t, P[i+1])
    for j in qwq[n+1]:
        range_add(1, 0, m, j, m, Q[j])
    return query(1, 0, m, m)

def brute_d(aA, S, P, aB, T, Q):
    A = aA[:]; B = aB[:]
    for i in range(1, len(A)): A[i] += A[i-1]
    for j in range(1, len(B)): B[j] += B[j-1]
    n, m = len(A) - 1, len(B) - 1
    NEG = -10**30
    dp = [[NEG]*(m+1) for _ in range(n+1)]
    dp[0][0] = 0
    for i in range(n+1):
        for j in range(m+1):
            if i == 0 and j == 0: continue
            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j] + (P[i] if A[i] + B[j] <= S[i] else 0))
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i][j-1] + (Q[j] if A[i] + B[j] <= T[j] else 0))
    return dp[n][m]

ok = True
for _ in range(200):
    n = random.randint(1, 5)
    m = random.randint(1, 5)
    A = [0] + [random.randint(1, 6) for _ in range(n)]
    B = [0] + [random.randint(1, 6) for _ in range(m)]
    S = [0] + [random.randint(1, 30) for _ in range(n)]
    T = [0] + [random.randint(1, 30) for _ in range(m)]
    P = [0] + [random.randint(0, 10) for _ in range(n)]
    Q = [0] + [random.randint(0, 10) for _ in range(m)]
    x = std_d(A, S, P, B, T, Q)
    y = brute_d(A, S, P, B, T, Q)
    if x != y:
        print("D MISMATCH"); print(A,S,P,B,T,Q); print("std=",x,"brute=",y); ok = False; break
print("D:", "OK" if ok else "FAIL")
