#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
priority_queue<int,vector<int>,greater<int>> g[N];
int main(){
    
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        int m,k;
        scanf("%d%d",&m,&k);
        g[m].push(k);
    }
    while(q--){
        int op,m,k;
        scanf("%d%d%d",&op,&m,&k);
        if(op==1) g[m].push(k),n++;
        else{
            int t=sqrt(k);
            for(int x=max(m-t,1);x<=m+t;x++){
                while(!g[x].empty()&&1ll*(x-m)*(x-m)+g[x].top()<=k) n--,g[x].pop();
            }
        }
        printf("%d\n",n);
    }
    return 0;
}