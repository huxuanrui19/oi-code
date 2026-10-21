from itertools import permutations
from collections import deque

def min_cap(a, debug=False):
    n = len(a)
    def ok(out):
        f = out[::-1]
        return all(f[i] <= f[i+1] for i in range(len(f)-1))
    for M in range(0, n+1):
        start = (tuple(range(n)), tuple(), tuple())
        seen = {start}
        dq = deque([start])
        found = False
        while dq:
            pool, st, out = dq.popleft()
            if not pool and not st:
                if ok(out):
                    if debug: print("M=",M,"out=",out, [a[i] for i in out])
                    found = True
                    break
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
        if found:
            return M
    return None

print(min_cap((3,1,2), debug=True))
print(min_cap((1,3,2), debug=True))
print(min_cap((2,2,1), debug=True))
