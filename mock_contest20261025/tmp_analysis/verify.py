import heapq
import random
from math import gcd
from itertools import combinations


def candy(a):
    n = len(a) - 1
    d = [0 if x == -1 else 10 ** 9 for x in a]
    for i in range(2, n + 1):
        d[i] = min(d[i], d[i - 1] + 1)
    for i in range(n - 1, 0, -1):
        d[i] = min(d[i], d[i + 1] + 1)
    d = d[:]
    total = sum(max(x, 0) for x in a)
    used = 0
    ans = 0
    last = 0
    flag = False
    q = []
    for i in range(1, n + 1):
        last = min(last, d[i])
        if a[i] == 0:
            continue
        if a[i] == -1:
            if flag:
                ans += 1
                flag = False
            continue
        if flag:
            last, d[i] = d[i], last
            if (used + d[i]) * 2 <= i - 1:
                used += d[i]
                heapq.heappush(q, -d[i])
                ans += 1
                flag = False
            elif q and d[i] <= -q[0]:
                x = -heapq.heappop(q)
                ans -= 1
                used -= x
                used += d[i]
                heapq.heappush(q, -d[i])
                ans += 1
                d[i] = x
            last, d[i] = d[i], last
        for _ in range(1, a[i]):
            if (used + d[i]) * 2 <= i - 1:
                used += d[i]
                heapq.heappush(q, -d[i])
                ans += 1
            elif q and d[i] <= -q[0]:
                x = -heapq.heappop(q)
                ans -= 1
                used -= x
                flag = True
                last = x
                used += d[i]
                heapq.heappush(q, -d[i])
                ans += 1
            else:
                break
        if not flag:
            flag = True
            last = d[i]
        else:
            last = min(last, d[i])
    return total - ans - flag


def candy_brute(a):
    n = len(a) - 1
    shops = [i for i in range(1, n + 1) for _ in range(max(a[i], 0))]
    bit = {}
    for j, p in enumerate(shops):
        bit[p] = bit.get(p, 0) | (1 << j)
    full = (1 << len(shops)) - 1

    def options(pos, carry, rem):
        yield pos, carry, rem
        if a[pos] == -1 and carry:
            yield pos, False, rem
        if a[pos] > 0 and not carry and (rem & bit[pos]):
            b = (rem & bit[pos]) & -(rem & bit[pos])
            yield pos, True, rem ^ b

    def alice(h, pos, carry, rem):
        if h % 2 == 0:
            p = h // 2 + 1
            if p <= n and a[p] > 0 and (rem & bit[p]):
                r = rem & bit[p]
                return pos, carry, rem ^ r, r.bit_count()
        return pos, carry, rem, 0

    start = []
    for pos, carry, rem in options(1, False, full):
        pos, carry, rem, cost = alice(0, pos, carry, rem)
        start.append((0, pos, carry, rem, cost))
    dist = {}
    pq = []
    for h, pos, carry, rem, cost in start:
        state = (h, pos, carry, rem)
        if cost < dist.get(state, 99):
            dist[state] = cost
            heapq.heappush(pq, (cost, state))
    end = 2 * (n - 1)
    while pq:
        cost, (h, pos, carry, rem) = heapq.heappop(pq)
        if dist[(h, pos, carry, rem)] != cost:
            continue
        if h == end:
            return cost
        for p0, c0, r0 in options(pos, carry, rem):
            for step in (-1, 1):
                p1 = p0 + step
                if not 1 <= p1 <= n:
                    continue
                h1 = h + 1
                for p2, c2, r2 in options(p1, c0, r0):
                    p2, c2, r2, add = alice(h1, p2, c2, r2)
                    state = (h1, p2, c2, r2)
                    nc = cost + add
                    if nc < dist.get(state, 99):
                        dist[state] = nc
                        heapq.heappush(pq, (nc, state))
    raise RuntimeError('no answer')


def prison(t, d, T):
    n = len(t) - 1
    l = [0] * (n + 1)
    fa = [0] * (n + 1)
    son = [0] * (n + 1)
    mx = [0] * (n + 1)
    stk = []
    ans = n
    for i in range(1, n + 1):
        if t[i] <= T:
            while stk and t[stk[-1]] + i - stk[-1] >= t[i]:
                stk.pop()
            stk.append(i)
        else:
            while stk and t[stk[-1]] + i - stk[-1] > T:
                stk.pop()
            if not stk:
                ans -= 1
            else:
                l[i] = stk[-1]
    stk = []
    for i in range(n, 0, -1):
        if not l[i]:
            continue
        while stk and l[stk[-1]] > l[i]:
            stk.pop()
        if stk:
            fa[i] = stk[-1]
        stk.append(i)
    for i in range(1, n + 1):
        if l[i]:
            mx[i] = 1
        if fa[i] and mx[i] + 1 > mx[fa[i]]:
            mx[fa[i]] = mx[i] + 1
            son[fa[i]] = i
    lengths = []
    for i in range(1, n + 1):
        if not l[i] or (fa[i] and son[fa[i]] == i):
            continue
        u = i
        x = 0
        while u:
            x += 1
            u = son[u]
        lengths.append(x)
    lengths.sort(reverse=True)
    return ans - sum(lengths[:d])


def prison_brute(t, d, T):
    n = len(t) - 1
    ans = n
    for mask in range(1 << (n - 1)):
        if mask.bit_count() > d:
            continue
        now = [0] * (n + 1)
        for i in range(1, n + 1):
            if i == 1 or (mask >> (i - 2)) & 1:
                now[i] = t[i]
            else:
                now[i] = min(t[i], now[i - 1] + 1)
        ans = min(ans, sum(x <= T for x in now[1:]))
    return ans


def ground(grid, k):
    n = len(grid) - 1
    dp = [[[0] * k for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            x = grid[i][j]
            if x == -1:
                continue
            if i == 1 and j == 1:
                dp[i][j][x % k] = 1
                continue
            for r in range(k):
                ways = dp[i - 1][j][r] + dp[i][j - 1][r]
                dp[i][j][r * x % k] += ways
    return dp[n][n][0]


def ground_fast(grid, k):
    n = len(grid) - 1
    div = [x for x in range(1, k + 1) if k % x == 0]
    m = len(div)
    dp = [[[0] * m for _ in range(n + 1)] for _ in range(2)]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            x = grid[i][j]
            if x == -1:
                continue
            for z in range(m):
                if i == 1 and j == 1:
                    ways = int(z == 0)
                else:
                    ways = dp[0][j][z] + dp[1][j - 1][z]
                g = gcd(div[z] * x, k)
                dp[1][j][div.index(g)] += ways
        dp[0] = [row[:] for row in dp[1]]
        dp[1] = [[0] * m for _ in range(n + 1)]
    return dp[0][n][div.index(k)]


def tetris_fast(grid, centers):
    m, n = len(grid), len(grid[0])
    s = m * n
    fa = list(range(s))
    sm = [grid[i][j] for i in range(m) for j in range(n)]
    mn = sm[:]
    c1 = [1] * s
    c2 = [0] * s

    def find(x):
        while fa[x] != x:
            fa[x] = fa[fa[x]]
            x = fa[x]
        return x

    def merge(x, y):
        x, y = find(x), find(y)
        if x == y:
            return
        fa[y] = x
        c1[x] += c1[y]
        c2[x] += c2[y]
        sm[x] += sm[y]
        mn[x] = min(mn[x], mn[y])

    ps = []
    for x, y in centers:
        u = x * n + y
        ps.append(u)
        c1[u], c2[u], mn[u] = 0, 1, 10 ** 9
    for u in ps:
        x, y = divmod(u, n)
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n:
                merge(u, nx * n + ny)
    vis = set()
    ans = 0
    for u in ps:
        r = find(u)
        if r in vis:
            continue
        vis.add(r)
        if c1[r] < 3 * c2[r]:
            return None
        ans += sm[r]
        if c1[r] > 3 * c2[r]:
            ans -= mn[r]
    return ans


def tetris_brute(grid, centers):
    m, n = len(grid), len(grid[0])
    opts = []
    for x, y in centers:
        ns = []
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n:
                ns.append(nx * n + ny)
        cur = []
        for arm in combinations(ns, 3):
            cells = {x * n + y, *arm}
            cur.append((cells, sum(grid[u // n][u % n] for u in cells)))
        opts.append(cur)

    ans = None

    def dfs(i, used, val):
        nonlocal ans
        if i == len(centers):
            ans = val if ans is None else max(ans, val)
            return
        for cells, add in opts[i]:
            if not used & cells:
                dfs(i + 1, used | cells, val + add)

    dfs(0, set(), 0)
    return ans


def main():
    random.seed(1)
    for tc in range(3000):
        n = random.randint(2, 6)
        a = [0] + [random.choice([-1, 0, 1, 2]) for _ in range(n)]
        a[random.randint(1, n)] = -1
        x, y = candy(a), candy_brute(a)
        if x != y:
            print('candy mismatch', tc, a, x, y)
            return
    print('candy: 3000 tests passed, up to 2 candies per shop')

    for tc in range(3000):
        n = random.randint(2, 9)
        d = random.randint(1, n - 1)
        T = random.randint(1, 12)
        t = [0] + [random.randint(1, 15) for _ in range(n)]
        x, y = prison(t, d, T), prison_brute(t, d, T)
        if x != y:
            print('prison mismatch', tc, n, d, T, t, x, y)
            return
    print('prison: 3000 tests passed')

    for tc in range(1000):
        n = random.randint(1, 5)
        k = random.randint(1, 30)
        grid = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                grid[i][j] = random.choice([-1, 1, 2, 3, 4, 5, 6, 7, 8])
        grid[1][1] = random.randint(1, 8)
        x, y = ground(grid, k), ground_fast(grid, k)
        if x != y:
            print('ground mismatch', tc, n, k, grid, x, y)
            return
    print('ground: 1000 tests passed')

    for tc in range(3000):
        m = random.randint(1, 4)
        n = random.randint(1, 4)
        grid = [[random.randint(0, 9) for _ in range(n)] for _ in range(m)]
        cells = list(range(m * n))
        random.shuffle(cells)
        centers = [divmod(u, n) for u in cells[:random.randint(1, min(4, m * n))]]
        x, y = tetris_fast(grid, centers), tetris_brute(grid, centers)
        if x != y:
            print('tetris mismatch', tc, grid, centers, x, y)
            return
    print('tetris: 3000 tests passed')


if __name__ == '__main__':
    main()
