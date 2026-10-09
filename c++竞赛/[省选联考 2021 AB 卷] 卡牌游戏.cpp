#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,cnt=0,l=0,r,now=0,a[N],b[N],flag[N];
struct node{
	ll num,idx,type;
	bool operator < (const node &x) const{
		return num<x.num;
	}
}tot[2*N];

void find1(){
	while(!flag[tot[l+1].idx]&&now+tot[l+1].type<=m){
		l++;
		now+=tot[l].type;
		flag[tot[l].idx]=1;
	}
}

void find2(){
	while(!flag[tot[r-1].idx]&&now+tot[r-1].type<=m){
		r--;
		now+=tot[r].type;
		flag[tot[r].idx]=1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		tot[++cnt]={a[i],i,1};
		tot[++cnt]={b[i],i,0};
	}
	sort(tot+1,tot+cnt+1);
	r=cnt+1;
	
	ll ans=2e9;
	find1();
	find2();
	
	while(l>=0){
		ans=min(ans,tot[r-1].num-tot[l+1].num);
		flag[tot[l+1].idx]=0;
		now-=tot[l+1].type;
		l--;
		find2();
	}
	cout<<ans;
	return 0;
}

