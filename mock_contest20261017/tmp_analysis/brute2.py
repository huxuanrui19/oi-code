import subprocess, itertools, random
from collections import deque
EXE_DIR = r"D:\oi-code\mock_contest20261017\tmp_analysis"
def run(exe, inp):
    r = subprocess.run([EXE_DIR + "\\" + exe], input=inp, capture_output=True, text=True, timeout=10)
    return r.stdout.strip()

def bfs_cap(a):
    n = len(a)
    def ok(out):
        f = out[::-1]
        return all(a[f[i]] <= a[f[i+1]] for i in range(len(f)-1))
    for M in range(0, n+1):
        start = (tuple(range(n)), tuple(), tuple())
        seen = {start}; dq = deque([start])
        while dq:
            pool, st, out = dq.popleft()
            if not pool and not st:
                if ok(out): return M
                continue
            if st:
                s2 = (pool + (st[-1],), st[:-1], out)
                if s2 not in seen: seen.add(s2); dq.append(s2)
            if pool:
                x = pool[-1]; rest = pool[:-1]
                s2 = (rest, st, out + (x,))
                if s2 not in seen: seen.add(s2); dq.append(s2)
                if len(st) < M:
                    s2 = (rest, st + (x,), out)
                    if s2 not in seen: seen.add(s2); dq.append(s2)
    return None

# B with K>0: enumerate fill assignments for empty carts
random.seed(7); bad = 0
for t in range(60):
    n = random.randint(1, 6)
    a = [random.choice([0, 0, 1, 2, 3]) for _ in range(n)]
    K = random.choice([0, 1, 2, 5, 10**12])
    empties = [i for i in range(n) if a[i] == 0]
    best = None
    maxv = max(a) if any(a) else 0
    for fill in itertools.product(range(0, maxv + 2), repeat=len(empties)):
        b = a[:]; cost = 0
        for idx, v in zip(empties, fill):
            b[idx] = v; cost += v
        if cost > K: continue
        # note: filling with equal values allowed; value 0 keeps it "empty" (cost 0)
        c = bfs_cap(b)
        if c is not None and (best is None or c < best): best = c
    inp = f"{n} {K}\n{' '.join(map(str,a))}\n"
    got = int(run("B_std.exe", inp))
    if got != (best if best is not None else -1):
        print("B-K MISMATCH", a, "K=", K, "std:", got, "brute:", best); bad += 1
        if bad > 5: break
print("B(K>0) check done, mismatches:", bad)
