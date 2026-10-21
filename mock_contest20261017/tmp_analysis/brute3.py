import subprocess, random
EXE_DIR = r"D:\oi-code\mock_contest20261017\tmp_analysis"
def run(exe, inp):
    r = subprocess.run([EXE_DIR + "\\" + exe], input=inp, capture_output=True, text=True, timeout=10)
    return r.stdout.strip()

def brute_crystal(k, mat, s):
    # BFS over reachable strings
    seen = {s}
    dq = [s]
    best = s
    while dq:
        cur = dq.pop()
        if cur < best: best = cur
        for p in range(1, len(cur)):
            if mat[ord(cur[p-1])-97][ord(cur[p])-97]:
                nxt = cur[:p] + cur[p+1:]
                if nxt not in seen:
                    seen.add(nxt); dq.append(nxt)
    return best

random.seed(11); bad = 0
for t in range(250):
    k = random.randint(1, 4)
    n = random.randint(1, 9)
    mat = [[random.randint(0,1) for _ in range(k)] for _ in range(k)]
    s = "".join(random.choice("abcdef"[:k]) for _ in range(n))
    inp = f"{k} {n}\n" + "\n".join("".join(str(x) for x in row) for row in mat) + f"\n{s}\n"
    got = run("D_std.exe", inp)
    b = brute_crystal(k, mat, s)
    if got != b:
        print("D MISMATCH", k, n, s, "std:", repr(got), "brute:", repr(b)); bad += 1
        if bad > 5: break
print("D check done, mismatches:", bad)
