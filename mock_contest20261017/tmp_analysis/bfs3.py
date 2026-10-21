from itertools import permutations
from collections import deque

def min_cap(a, debug=False):
    n = len(a)
    def ok(out):
        f = out[::-1]              # final left-to-right cart order
        return all(a[f[i]] <= a[f[i+1]] for i in range(len(f)-1))
    for M in range(0, n+1):
        start = (tuple(range(n)), tuple(), tuple())
        seen = {start}
        dq = deque([start])
        while dq:
            pool, st, out = dq.popleft()
            if not pool and not st:
                if ok(out):
                    if debug: print("M=", M, "pass order:", [a[i] for i in out])
                    return M
                continue
            if st:
                s2 = (pool + (st[-1],), st[:-1], out)
                if s2 not in seen:
                    seen.add(s2); dq.append(s2)
            if pool:
                x = pool[-1]
                rest = pool[:-1]
                s2 = (rest, st, out + (x,))
                if s2 not in seen:
                    seen.add(s2); dq.append(s2)
                if len(st) < M:
                    s2 = (rest, st + (x,), out)
                    if s2 not in seen:
                        seen.add(s2); dq.append(s2)
    return None

# verify against candidate formulas
def formula_larger_right(a):
    n = len(a)
    return max(sum(1 for j in range(i+1, n) if a[j] > a[i]) for i in range(n))
def formula_smaller_right(a):
    n = len(a)
    return max(sum(1 for j in range(i+1, n) if a[j] < a[i]) for i in range(n))
def formula_disp(a):
    n = len(a)
    order = sorted(range(n), key=lambda i: (a[i], i))
    p = [0]*n
    for pos, i in enumerate(order):
        p[i] = pos
    return max(abs(p[i]-i) for i in range(n))

for n in [2,3]:
    for a in set(permutations(range(1,n+1))):
        m = min_cap(a)
        fl = formula_larger_right(a)
        fs = formula_smaller_right(a)
        fd = formula_disp(a)
        mark = ""
        if m is None: mark = "UNSOLVABLE"
        elif m != fl and m != fs and m != fd: mark = "<== no formula matches"
        print(a, "BFS:", m, "largerR:", fl, "smallerR:", fs, "disp:", fd, mark)
