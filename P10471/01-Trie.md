---
aliases:
  - 01 Trie
  - Binary Trie
  - Bitwise Trie
tags:
  - data-structure
  - trie
  - bitwise
  - xor
  - luogu
source: P10471
---

# 01 Trie (Binary Trie)

> [!abstract] Core idea
> A **01 Trie** stores the binary representation of integers. Every node has at most two children: `0` and `1`. It is especially useful for XOR optimization problems.

## XOR observation

For one bit, different values produce `1` and equal values produce `0`:

| $a$ | $b$ | $a \oplus b$ |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Higher bits contribute more to the result than all lower bits combined. Therefore, when maximizing XOR, process bits from high to low and greedily choose the opposite bit whenever possible.

## Structure

In `P10471.cpp`:

- `tree[p][0]` is the child for bit `0`;
- `tree[p][1]` is the child for bit `1`;
- node `0` is the root;
- bits `30` down to `0` are stored, giving every number a path of 31 bits.

## Operations

### Insert a number

For each bit from bit `30` down to bit `0`:

1. Extract the current bit with `(num >> i) & 1`.
2. Create the matching child if necessary.
3. Move to that child.

Leading zeroes are also inserted, so all paths have the same length.

### Find the largest XOR with a number

At each bit, let the current bit be `cnt`:

- first try `cnt ^ 1`, the opposite bit, because it contributes $2^i$ to the XOR result;
- if that child does not exist, follow `cnt` instead.

The greedy choice is correct because obtaining `1` at bit $i$ is worth more than any possible combination of lower bits.

> [!example] Example
> Suppose the Trie contains `5 = 101₂` and the query is `2 = 010₂`.
> At every bit the opposite branch exists, producing `111₂ = 7`, so $5 \oplus 2 = 7$.

## How P10471 is solved

1. Insert every array element into the 01 Trie.
2. Query every element to find its maximum XOR with any inserted element.
3. Keep the largest query result in `ans`.

## Complexity

Let $B=31$ be the number of processed bits:

- insertion: $O(B)$ per number;
- query: $O(B)$ per number;
- total time: $O(nB)$, effectively $O(n)$ for fixed-width integers;
- memory: $O(nB)$ nodes.

> [!warning] Implementation details
> - Bits must be processed from high to low for the greedy query to work.
> - `N * M` nodes are allocated because each of the `N` numbers can create up to roughly `M` nodes.
> - This implementation handles non-negative values whose relevant bits are within positions `0` through `30`.
> - For wider values, use `long long` consistently and extend the loop to the required highest bit; write `1LL << i` when adding a bit contribution.

## P10471.cpp

> [!code]- Full solution — `P10471.cpp`
> ```cpp
> #include<bits/stdc++.h>
> using namespace std;
> typedef long long ll;
> const int N=1e5+10,M=35;
> int n,tot,tree[N*M][2];ll ans,a[N];
> void insert(int num){
> 	ll p=0;
> 	for(int i=30;i>=0;i--){
> 		int cnt=(num>>i)&1;
> 		if(tree[p][cnt]==0) tree[p][cnt]=++tot;
> 		p=tree[p][cnt];
> 	}
> }
> ll query(ll num){
> 	int p=0;ll sum=0;
> 	for(int i=30;i>=0;i--){
> 		int cnt=(num>>i)&1;
> 		if(tree[p][cnt^1]) p=tree[p][cnt^1],sum+=(1<<i);
> 		else p=tree[p][cnt];
> 	}
> 	return sum;
> }
> int main() {
> 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
> 	//freopen(".in","r",stdin);
> 	//freopen(".out","w",stdout);
> 	cin>>n;
> 	for(int i=1;i<=n;i++) cin>>a[i];
> 	for(int i=1;i<=n;i++) insert(a[i]);
> 	for(int i=1;i<=n;i++) ans=max(ans,query(a[i]));
> 	cout<<ans;
> 	return 0;
> }
> ```

## Related

- [[Trie]] — the general prefix-tree structure used for strings.
