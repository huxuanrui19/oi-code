---
aliases:
  - Trie
  - Prefix Tree
tags:
  - data-structure
  - trie
  - string
  - luogu
source: P8306
---

# Trie (Prefix Tree)

> [!abstract] Core idea
> A **Trie**, also called a **prefix tree**, stores strings one character at a time. Strings with the same prefix share the same path, so prefix insertion and lookup are both efficient.

## Structure

Each node represents a prefix. In `P8306.cpp`, every node contains:

- `tree[p][idx]`: the next node reached from node `p` using character `idx`;
- `tot[p]`: the number of inserted strings that pass through node `p`;
- `cnt`: the number of Trie nodes that have been created.

Node `0` is the root and represents the empty prefix.

The input alphabet contains lowercase letters, uppercase letters, and digits. `judge()` maps them into numeric indexes:

| Character | Index range |
| --- | --- |
| `a`–`z` | `0`–`25` |
| `A`–`Z` | `26`–`51` |
| `0`–`9` | `52`–`61` |

## Operations

### Insert a string

Starting at the root, process every character in order:

1. Convert the character to an index.
2. Create the corresponding child node if it does not exist.
3. Move to that child.
4. Increment `tot[p]` because one more string contains this prefix.

### Count strings with a prefix

Follow the query string from the root:

- if an edge is missing, no inserted string has this prefix, so return `0`;
- otherwise, after reaching the final node, return `tot[p]`.

> [!example] Example
> After inserting `apple`, `app`, and `apply`:
>
> - query `app` → `3`
> - query `apple` → `1`
> - query `apx` → `0`

## Complexity

For a string of length $L$:

- insertion: $O(L)$;
- prefix query: $O(L)$;
- memory: $O(S \times |\Sigma|)$ for this array implementation, where $S$ is the number of nodes and $|\Sigma|$ is the alphabet size.

> [!warning] Implementation details
> - `tot[p]` counts strings passing through a node; it does **not** only count strings ending there.
> - The Trie must be cleared between test cases. The program clears only the nodes used by the previous case, then resets `cnt`.
> - Calling `strlen()` in every loop condition repeatedly scans the string. Saving the length first would avoid that extra work.
> - The child array uses 63 columns although only indexes `0` through `61` are used.

## P8306.cpp

> [!code]- Full solution — `P8306.cpp`
> ```cpp
> #include <bits/stdc++.h>
> using namespace std;
> typedef long long ll;
> const int N=3e6+10;
> int cnt=0,tree[N][63],tot[N];
> int judge(char c){
> 	if(c>='a'&&c<='z') return int(c-'a');
> 	if(c>='A'&&c<='Z') return int(c-'A'+26);
> 	return int(c-'0'+52);
> }
> void insert(char *s){
> 	int p=0;
> 	for(int i=0;i<strlen(s);i++){
> 		int idx=judge(s[i]);
> 		if(tree[p][idx]) p=tree[p][idx];
> 		else tree[p][idx]=++cnt,p=cnt;
> 		tot[p]++;
> 	}
> }
> int ask(char *t){
> 	int p=0;
> 	for(int i=0;i<strlen(t);i++){
> 		int idx=judge(t[i]);
> 		if(tree[p][idx]==0) return 0;
> 		p=tree[p][idx];
> 	}
> 	return tot[p];
> }
> char s1[N];
> int main() {
> 	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
> 	int t;cin>>t;
> 	while(t--){
> 		int n,q;
> 		cin>>n>>q;
> 		for(int i=0;i<=cnt;i++){
> 			tot[i]=0;
> 			for(int j=0;j<63;j++) tree[i][j]=0;
> 		}
>         cnt=0;
> 		for(int i=1;i<=n;i++){
> 			cin>>s1;
> 			insert(s1);
> 		}
> 		for(int i=1;i<=q;i++){
> 			cin>>s1;
> 			cout<<ask(s1)<<"\n";
> 		}
> 	}
> 	return 0;
> }
> ```

## Related

- [[01-Trie|01 Trie]] — applies the same tree idea to binary digits and XOR optimization.

