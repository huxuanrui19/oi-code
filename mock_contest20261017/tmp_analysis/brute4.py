import subprocess, random, itertools
from collections import deque
EXE_DIR = r"D:\oi-code\mock_contest20261017\tmp_analysis"
def run(exe, inp):
    r = subprocess.run([EXE_DIR + "\\" + exe], input=inp, capture_output=True, text=True, timeout=10)
    return r.stdout.strip()

INF = 10**9
def dists(n, edges):
    # double cover BFS from (1,0)
    g = [[] for _ in range(2*n+1)]
    for x, y in edges:
        g[x].append(y+n); g[y+n].append(x)
        g[y].append(x+n); g[x+n].append(y)
    d = [INF]*(2*n+1)
    d[1] = 0
    dq = deque([1])
    while dq:
        u = dq.popleft()
        for v in g[u]:
            if d[v] == INF:
                d[v] = d[u]+1; dq.append(v)
    return d

def brute(n, edges):
    d = dists(n, edges)
    tgt = [(min(d[i], d[i+n]), max(d[i], d[i+n])) for i in range(1, n+1)]
    # all undirected graphs with loops allowed: pairs (x,y), 1<=x<=y<=n
    pairs = [(x, y) for x in range(1, n+1) for y in range(x, n+1)]
    best = None
    for mask in range(1 << len(pairs)):
        e2 = [pairs[i] for i in range(len(pairs)) if mask >> i & 1]
        d2 = dists(n, e2)
        okk = True
        for i in range(1, n+1):
            if (min(d2[i], d2[i+n]), max(d2[i], d2[i+n])) != tgt[i-1]:
                okk = False; break
        if okk and (best is None or len(e2) < best):
            best = len(e2)
    return best

random.seed(5); bad = 0
for t in range(300):
    n = random.randint(2, 4)
    allp = [(x, y) for x in range(1, n+1) for y in range(x, n+1)]
    while True:
        edges = [p for p in allp if random.random() < 0.5]
        # connected?
        par = list(range(n+1))
        def find(a):
            while par[a] != a: par[a] = par[par[a]]; a = par[a]
            return a
        for x, y in edges:
            par[find(x)] = find(y)
        if len({find(i) for i in range(1, n+1)}) == 1: break
    b = brute(n, edges)
    inp = "1\n" + f"{n} {len(edges)}\n" + "".join(f"{x} {y}\n" for x, y in edges) + "\n"
    got = int(run("C_std.exe", inp))
    if got != b:
        print("C MISMATCH", n, edges, "std:", got, "brute:", b); bad += 1
        if bad > 5: break
print("C check done, mismatches:", bad)
