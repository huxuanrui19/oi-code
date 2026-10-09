#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,cnt,a[N],b[N];
bool flag[N];
struct node{
	ll num,idx,op;
	bool operator <(const node &x) const{
		return num<x.num;
	}
}tot[N*2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		tot[++cnt]={a[i],i,1};
		tot[++cnt]={b[i],i,0};
	}
	sort(tot+1,tot+cnt+1);
	
	int l=1,r=cnt,now=0;
	while(!flag[tot[l].idx]&&now+tot[l+1].op<=m){
		flag[tot[l].idx]=1;
		now+=tot[l].op;
		l++;
	}
	while(!flag[tot[r].idx]&&now+tot[r].op<=m){
		flag[tot[r].idx]=1;
		now+=tot[r].op;
		r--;
	}
	ll ans=2e9;
	while(l>=1){
		ans=min(ans,tot[r].num-tot[l].num);
		flag[tot[l+1].idx]=0;
		now-=tot[l+1].op;
		l--;
		while(!flag[tot[r].idx]&&now+tot[r].op<=m){
			flag[tot[r].idx]=1;
			now+=tot[r].op;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

