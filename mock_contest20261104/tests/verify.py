#!/usr/bin/env python3
"""Independent small-state oracles, provided samples, and optional boundary cases.
Run: python3 tests/verify.py --cxx g++ --stress
All executables and input/output files live in a temporary directory.
"""
from pathlib import Path
import argparse, collections, functools, itertools, os, random, subprocess, tempfile

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument('--cxx', default=os.environ.get('CXX', 'g++'))
parser.add_argument('--stress', action='store_true')
args = parser.parse_args()
workspace = tempfile.TemporaryDirectory(prefix='contest-20261104-')
build = Path(workspace.name)
for name in ['arrange', 'word', 'grid', 'loop']:
    subprocess.run([args.cxx, '-std=c++14', '-O2', '-Wall', '-Wextra',
                    str(ROOT/name/'solution.cpp'), '-o', str(build/name)], check=True)

def run(name, data):
    (build/(name+'.in')).write_text(data)
    subprocess.run([str(build/name)], cwd=build, check=True, timeout=60)
    return list(map(int, (build/(name+'.out')).read_text().split()))

def brute(g):
 r,c=len(g),len(g[0]); sides=[]
 for x in range(r):
  for y in range(c):
   sides.extend([[(x,y,'L'),(x,y,'B' if g[x][y]=='N' else 'T')],[(x,y,'R'),(x,y,'T' if g[x][y]=='N' else 'B')]])
 edges={};adj=[0]*len(sides)
 for u,ss in enumerate(sides):
  for x,y,d in ss:
   edge={'L':('v',x,y),'R':('v',x,y+1),'T':('h',x,y),'B':('h',x+1,y)}[d]
   if edge in edges:
    v=edges[edge];adj[u]|=1<<v;adj[v]|=1<<u
   edges[edge]=u
 ans=[-1]*(r*c);q=collections.deque([0]);seen={0}
 while q:
  mask=q.popleft();dist=bin(mask).count("1")
  for cell in range(r*c):
   if ans[cell]<0 and (mask>>(2*cell))&3==3:ans[cell]=dist
  for u in range(2*r*c):
   if mask>>u&1:continue
   if mask>>(u^1)&1 or mask&adj[u]==adj[u]:
    v=mask|1<<u
    if v not in seen:seen.add(v);q.append(v)
 return ans

# Supplied input/output pairs (the unrelated ans.out is not used).
for name in ['arrange', 'word', 'grid']:
    files = sorted((ROOT/name/name).glob('*.in'))
    for f in files:
        assert run(name, f.read_text()) == list(map(int, f.with_suffix('.out').read_text().split())), f
    print(name, 'provided cases:', len(files), flush=True)

@functools.lru_cache(None)
def reachable(p):
    result = {p}
    for i in range(len(p)-1):
        j = i if p[i] > p[i+1] else i+1
        result.update(reachable(p[:j]+p[j+1:]))
    return frozenset(result)

count=0
for n in range(1,7):
    for p in itertools.permutations(range(1,n+1)):
        assert run('arrange', str(n)+'\n'+' '.join(map(str,p))+'\n') == [len(reachable(p))], p
        count += 1
print('arrange exhaustive permutations:', count, flush=True)

rng=random.Random(20261104)
for data, answer in [('3 3\n??b\nc??\nc?c\n', 2),
                     ('4 6\nab??c?\n??kll?\na?k??c\n?bcd??\n', 3),
                     ('5 2\n??\nb?\nc?\n?g\ncg\n', 8)]:
    assert run('word',data)==[answer]
for _ in range(300):
    n,m=rng.randint(1,30),rng.randint(1,6)
    words=[''.join(rng.choice('abc?') for _ in range(m)) for _ in range(n)]
    answer=sum(all(a==b or a=='?' or b=='?' for a,b in zip(words[i],words[j]))
               for i in range(n) for j in range(i))
    assert run('word',f'{n} {m}\n'+'\n'.join(words)+'\n')==[answer],words
print('word official samples: 3; random direct pair checks: 300',flush=True)

count=0
for r,c in [(1,1),(1,4),(4,1),(2,2),(2,3),(3,2)]:
    for bits in itertools.product('NZ',repeat=r*c):
        g=[''.join(bits[i*c:(i+1)*c]) for i in range(r)]
        got=run('grid',f'{r} {c}\n'+'\n'.join(g)+'\n')
        assert got==brute(g),(g,got,brute(g))
        count+=1
for _ in range(8):
    g=[''.join(rng.choice('NZ') for _ in range(3)) for _ in range(3)]
    assert run('grid','3 3\n'+'\n'.join(g)+'\n')==brute(g),g
print('grid exhaustive patterns:',count,'; random 3x3: 8',flush=True)

# Actual shortest paths under adjacent swaps on a circle, to any rotation.
count=0
for n in range(1,7):
    goal=tuple(range(n));distance={goal[k:]+goal[:k]:0 for k in range(n)}
    queue=collections.deque(distance)
    while queue:
        p=queue.popleft()
        for i in range(n):
            v=list(p);j=(i+1)%n;v[i],v[j]=v[j],v[i];v=tuple(v)
            if v not in distance:
                distance[v]=distance[p]+1;queue.append(v)
    for p,answer in distance.items():
        data=f'{n} {2*n}\n'+''.join(f'{2*i} {2*v+1}\n' for i,v in enumerate(p))
        assert run('loop',data)==[answer],(p,answer)
        count+=1
for data,answer in [('3 100\n10 50\n30 20\n60 40\n',0),
                    ('4 100\n30 70\n10 12\n60 75\n90 50\n',1)]:
    assert run('loop',data)==[answer]
print('loop BFS permutations:',count,'; official samples: 2',flush=True)

if args.stress:
    n=50000
    for word in ['??????','aaaaaa']:
        assert run('word',f'{n} 6\n'+(word+'\n')*n)==[n*(n-1)//2]
    words=[''.join(rng.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(6)) for _ in range(n)]
    freq=collections.Counter(words)
    assert run('word',f'{n} 6\n'+'\n'.join(words)+'\n')==[sum(v*(v-1)//2 for v in freq.values())]
    print('word maximum n,m: wildcard, duplicate, random-letter cases passed',flush=True)
    r=c=400
    for ch in 'NZ':
        got=run('grid',f'{r} {c}\n'+(ch*c+'\n')*r)
        want=[2*min((j+1)*(r-i),(c-j)*(i+1)) if ch=='N' else
              2*min((j+1)*(i+1),(c-j)*(r-i)) for i in range(r) for j in range(c)]
        assert got==want,ch
    for start in range(2):
        g=[''.join('NZ'[(i+j+start)%2] for j in range(c)) for i in range(r)]
        got=run('grid',f'{r} {c}\n'+'\n'.join(g)+'\n')
        assert len(got)==r*c and all(v==-1 or 2<=v<=2*r*c and v%2==0 for v in got)
        flipped=[s[::-1].translate(str.maketrans('NZ','ZN')) for s in g]
        reflected=run('grid',f'{r} {c}\n'+'\n'.join(flipped)+'\n')
        assert reflected==[got[i*c+c-1-j] for i in range(r) for j in range(c)]
    print('grid 400x400: all N/Z closed forms; checkerboards and reflection passed',flush=True)
print('All checks passed.',flush=True)
