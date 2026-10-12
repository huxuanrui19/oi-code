# -*- coding: utf-8 -*-
# 追踪 D：逐行比较线段树维护的值与 O(nm) dp
from bisect import bisect_right

A=[0,2,5,3,1]; S=[0,15,7,23,26]; P=[0,3,9,3,5]
B=[0,2,6,6]; T=[0,24,5,7]; Q=[0,10,7,1]
n, m = 4, 3
NEG=-10**30
size=4*(m+2)+5
tr=[0]*size; lzadd=[0]*size; lztag=[NEG]*size; mark=[False]*size

def apply(o,v,M):
    tr[o]=max(tr[o]+v,M); lzadd[o]+=v; lztag[o]+=v; lztag[o]=max(lztag[o],M)
def pushdown(o):
    apply(o*2,lzadd[o],lztag[o]); apply(o*2+1,lzadd[o],lztag[o])
    lzadd[o]=0; lztag[o]=NEG
    if mark[o]:
        mark[o*2]=mark[o*2+1]=True; mark[o]=False
        apply(o*2+1,0,tr[o*2])
def pull(o): tr[o]=max(tr[o*2],tr[o*2+1])
def build(o,l,r):
    mark[o]=False; lztag[o]=NEG
    if l==r:
        tr[o]=0 if l==0 else NEG
        return
    mid=(l+r)//2
    build(o*2,l,mid); build(o*2+1,mid+1,r); pull(o)
def rngadd(o,l,r,x,y,v):
    if x<=l and r<=y: return apply(o,v,NEG)
    if r<x or l>y: return
    pushdown(o)
    mid=(l+r)//2
    rngadd(o*2,l,mid,x,y,v); rngadd(o*2+1,mid+1,r,x,y,v); pull(o)
def query(o,l,r,p):
    if l==r: return tr[o]
    mid=(l+r)//2
    pushdown(o)
    return query(o*2,l,mid,p) if p<=mid else query(o*2+1,mid+1,r,p)
def dump():
    return [query(1,0,m,j) for j in range(m+1)]

build(1,0,m)
qwq=[[] for _ in range(n+2)]
for j in range(1,m+1):
    rngadd(1,0,m,j,m,-Q[j])
    t=bisect_right([A[i] for i in range(n+1)],T[j]-B[j])
    qwq[t].append(j)
print("init:", dump(), "qwq:", qwq)

# O(nm) 参考 dp
dp=[[NEG]*(m+1) for _ in range(n+1)]
dp[0][0]=0
for i in range(n+1):
    for j in range(m+1):
        if i==0 and j==0: continue
        if i>0: dp[i][j]=max(dp[i][j],dp[i-1][j]+(P[i] if A[i]+B[j]<=S[i] else 0))
        if j>0: dp[i][j]=max(dp[i][j],dp[i][j-1]+(Q[j] if A[i]+B[j]<=T[j] else 0))
print("dp rows:")
for i in range(n+1): print(" ",i,dp[i])

for i in range(0,n+1):
    for j in qwq[i]: rngadd(1,0,m,j,m,Q[j])
    mark[1]=True
    if i!=n:
        t=bisect_right([B[j] for j in range(m+1)],S[i+1]-A[i+1])-1
        if t>=0: rngadd(1,0,m,0,t,P[i+1])
    print(f"after row i={i}:", dump())
for j in qwq[n+1]: rngadd(1,0,m,j,m,Q[j])
print("final:", dump(), "ans=",query(1,0,m,m))
