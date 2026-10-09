#include<bits/stdc++.h>
#define pii pair<ll,pair<int,int> >
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,m,k,a[N][N],rk[N][N],cnt[N][N],pos[N][N];
struct comp{
	bool operator()(pii x,pii y)const{
		if(x.first!=y.first) return x.first<y.first;
		else return x.second.second<y.second.second;
	}
};
priority_queue<pii,vector<pii>,comp> q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			cnt[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		sort(cnt[i]+1,cnt[i]+m+1);
		for(int j=1;j<=m;j++) rk[i][j]=lower_bound(cnt[i]+1,cnt[i]+m+1,a[i][j])-cnt[i];
		for(int j=1;j<=m;j++) pos[i][rk[i][j]]=j;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(rk[i][j]==j) continue;
			else q.push({a[i][j]-a[i][pos[i][j]],{i,pos[i][j]}});
		}
		while(!q.empty()){
			int i=q.top().second.first;q.pop();
			if(k) k--;
			else continue;
			swap(a[i][j],a[i][pos[i][j]]);
			ll t=rk[i][j];
			swap(rk[i][j],rk[i][pos[i][j]]);
			swap(pos[i][j],pos[i][t]);
		}
		if(k==0) break;
		while(!q.empty()) q.pop();
	}
	for(int j=1;j<=m;j++){
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][j];
		}
		cout<<ans<<" ";
	}
	return 0;
}
