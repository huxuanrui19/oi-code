#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=24+10,K=2e7+10;
const int M=1e9,C=1e5+5;
ll n,m,k,s,a[N],b[N],c[K];
void read(){
    cin>>n>>m>>k>>s;
    mt19937 rand(s);
    for(int i=1;i<=n;i++)  a[i]=rand()%M+1,b[i]=rand()%C+1;
    for(int i=1;i<=k;i++)  c[i]=rand()%n+1;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    read();
    for(int i=1;i<=n;i++){
        
    }
    return 0;
}