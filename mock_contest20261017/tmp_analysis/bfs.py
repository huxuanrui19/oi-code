from itertools import permutations
from functools import lru_cache
from collections import deque

def min_cap(a):
    n = len(a)
    # state: pool tuple (left-to-right), stack tuple (bottom-to-top), out tuple (pass order)
    # moves: rightmost pool cart -> pass (append out) or divert (push stack, if len<M))
    #        pop stack -> pool right end (append pool)
    # final ok iff reverse(out) is non-decreasing
    def ok(out):
        f = out[::-1]
        return all(f[i] <= f[i+1] for i in range(len(f)-1))
    for M in range(0, n+1):
        start = (tuple(range(n)), tuple(), tuple())
        seen = {start}
        dq = deque([start])
        while dq:
            pool, st, out = dq.popleft()
            if not pool and not st:
                if ok(out):
                    return M
                continue
            if ok(out) and not pool and not st:
                return M
            # pop stack -> pool right end
            if st:
                ns = st[:-1]
                np = pool + (st[-1],)
                s2 = (np, ns, out)
                if s2 not in seen:
                    seen.add(s2); dq.append(s2)
            # rightmost pool cart acts
            if pool:
                x = pool[-1]
                rest = pool[:-1]
                # pass
                s2 = (rest, st, out + (x,))
                if s2 not in seen:
                    seen.add(s2); dq.append(s2)
                # divert
                if len(st) < M:
                    s2 = (rest, st + (x,), out)
                    if s2 not in seen:
                        seen.add(s2); dq.append(s2)
        # if not found with this M, try bigger
    return None

for n in [3]:
    for a in permutations(range(1, n+1)):
        print(a, min_cap(a))
