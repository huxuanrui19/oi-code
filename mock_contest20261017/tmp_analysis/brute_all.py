import subprocess, itertools, random
from collections import deque

EXE_DIR = r"D:\oi-code\mock_contest20261017\tmp_analysis"

def run(exe, inp):
    r = subprocess.run([EXE_DIR + "\\" + exe], input=inp, capture_output=True, text=True, timeout=10)
    return r.stdout.strip()

# ---------- B: tramcar ----------
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

random.seed(1); bad = 0
for t in range(120):
    n = random.randint(1, 7)
    a = [random.randint(0, 4) for _ in range(n)]
    if all(x > 0 for x in a):
        b = bfs_cap(a)
        inp = f"{n} 0\n{' '.join(map(str,a))}\n"
        got = int(run("B_std.exe", inp))
        if got != b:
            print("B MISMATCH", a, "std:", got, "bfs:", b); bad += 1
            if bad > 5: break
print("B check done, mismatches:", bad)

# K=0 closed formula: max_i #{j>i: a_j <= a_i}
def formula_b0(a):
    n = len(a)
    return max((sum(1 for j in range(i+1, n) if a[j] <= a[i]) for i in range(n)), default=0)

random.seed(2); bad = 0
for t in range(200):
    n = random.randint(1, 7)
    a = [random.randint(0, 4) for _ in range(n)]
    b = bfs_cap(a); f = formula_b0(a)
    if b != f:
        print("FORMULA MISMATCH", a, "bfs:", b, "formula:", f); bad += 1
        if bad > 5: break
print("K=0 formula check done, mismatches:", bad)

# ---------- A: median ----------
def brute_median(a):
    n = len(a)
    def med(seg):
        s = sorted(seg); return s[len(s)//2]
    for i in range(1, n, 2):  # cut after position i (odd prefix length)
        if med(a[:i]) == med(a[i:]):
            return "Yes"
    return "No"

random.seed(3); bad = 0
for t in range(300):
    n = random.choice([2,4,6,8])
    a = [random.randint(1, 6) for _ in range(n)]
    inp = f"{n}\n{' '.join(map(str,a))}\n"
    got = run("A_std.exe", inp)
    b = brute_median(a)
    if got != b:
        print("A MISMATCH", a, "std:", got, "brute:", b); bad += 1
        if bad > 5: break
print("A check done, mismatches:", bad)
