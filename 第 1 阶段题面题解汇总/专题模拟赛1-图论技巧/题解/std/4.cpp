#include <set>
#include <cmath>
#include<iostream>
#include<vector>
#include <algorithm>
struct BlockCutTree{
  int n;
  std::vector<std::vector<int>> adj;
  std::vector<int> dfn,low,stk;
  int cnt,cur;
  std::vector<std::pair<int,int>> edges;
  BlockCutTree() {}
  BlockCutTree(int n):n(n){
    adj.assign(n + 1,{});
    dfn.assign(n + 1,0);
    low.assign(n + 1,0);
    stk.clear();
    cnt = cur = 0;
    edges.clear();
  }
  void addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int x){
    stk.push_back(x);
    dfn[x] = low[x] = ++ cur;
    for(auto y: adj[x]){
      if(!dfn[y]){
        dfs(y);
        low[x] = std::min(low[x],low[y]);
        if(low[y] == dfn[x]){
          int v;
          cnt ++;
          do {
            v = stk.back();
            stk.pop_back();
            edges.push_back({n + cnt,v});
          }while(v != y);
          edges.push_back({x,n + cnt});
        }
      }else {
        low[x] = std::min(low[x],dfn[y]);
      }
    }
  }
  std::pair<int,std::vector<std::pair<int,int>>> work(){
    for(int i = 1;i <= n;i ++){
      if(dfn[i] == 0){
        stk.clear();
        dfs(i);
      }
    }
    return {cnt,edges};
  }
};
void solve(){
  int n,m;
  std::cin >> n >> m;
  
  BlockCutTree T(n);
  for(int i = 0;i < m;i ++){
    int u,v;
    std::cin >> u >> v;
    T.addEdge(u,v);
  }

  auto [N,edges] = T.work();
  N += n;
  // std::cerr << "OvO" << N << std::endl;
  std::vector<std::vector<int>> e(N + 1);
  for(auto [x,y]:edges){
    e[x].push_back(y);
    e[y].push_back(x);
  }
  std::vector<std::vector<int>> anc(22, std::vector<int>(N + 1));
  std::vector<int> sum(N + 1, 0), dep(N + 1, 0);
  auto Dfs = [&](auto &&dfs, int u, int fa) -> void {
    anc[0][u] = fa;
    for (int j = 0; anc[j][anc[j][u]]; ++j) anc[j + 1][u] = anc[j][anc[j][u]];
    if(u <= n)sum[u] = 1;
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) if (v != fa) {
      dfs(dfs, v, u);
      sum[u] += sum[v];
    }
  };
  auto LCA = [&](int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    while (dep[x] != dep[y]) x = anc[int(log2(dep[x] - dep[y]))][x];
    for (int i = log2(dep[x]) + 1; i >= 0; --i) if (anc[i][x] != anc[i][y]) {
      x = anc[i][x];
      y = anc[i][y];
    }
    return (x == y) ? x : anc[0][x];
  };
  Dfs(Dfs, 1, 0);
  int q;
  std::cin >> q;
  for (int x, y; q; --q) {
    std::cin >> x >> y;
    if(dep[x] > dep[y]){
      std::swap(x,y);
    }
    int lca = LCA(x,y);
    int ans = 0;
    if(x == lca){
      int yyy = y;
      for (int i = log2(dep[y]) + 1; ~i; --i) if ((dep[y] - dep[x]) > (1 << i)) y = anc[i][y];
      ans = sum[y] - sum[yyy] + 2;
    }else {
      ans = n - sum[x] - sum[y] + 2;
    }
    std::cout << ans << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  for (std::cin >> T; T; --T) {
    solve();
  }  
}