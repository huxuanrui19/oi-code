#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,mark=0,cnt=0,p,q,a[N],b[N],col[N];
vector<int> g[N];
void dfs(int u,int c){
	if(col[u]){
		if(col[u]^c) mark=1;
		return;
	}
	col[u]=c;
	cnt++;
	if(c==1) p+=a[u];
	else q+=a[u];
	for(auto v:g[u]) dfs(v,3-c);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]-=b[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(!col[i]){
			mark=cnt=p=q=0;
			dfs(i,1);
			if(mark==1) ans+=abs(p-q)%2;
			else{
				ll num=abs(p-q);
				ll tmp=num/cnt,tmp2=num%cnt;
				ans+=tmp*tmp*(cnt-tmp2)+(tmp+1)*(tmp+1)*tmp2;
			}
		}
	}
	cout<<ans;
	return 0;
}

