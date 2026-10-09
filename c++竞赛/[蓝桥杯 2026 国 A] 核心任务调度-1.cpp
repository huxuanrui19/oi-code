#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
struct node{
	ll t,w,type;
	bool operator <(const node &x) const{
		if(type!=x.type) return type>x.type;
		else if(t!=x.t) return t<x.t;
		else return w>x.w;
	}
}a[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
ll m,ans,cnt[N],num[N],nxt[N];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].w>>a[i].type;
	sort(a+1,a+n+1);int pos=n+1;
	for(int i=1;i<=n;i++){
		if(a[i].type==0){
			pos=i;break;
		}
		else{
			q.push({a[i].w,i});
			if(q.size()>a[i].t) q.pop();
		}
	}
	while(!q.empty()){
		ans+=q.top().first;
		num[++m]=q.top().second;
		q.pop();
	}
	sort(num+1,num+m+1);
	cnt[m]=a[num[m]].t;nxt[m]=m;
	for(int i=m-1;i>=1;i--){
		cnt[i]=min(a[num[i]].t,cnt[i+1]-1);
		if(cnt[i]==cnt[i+1]-1) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	ll ti=0;
	for(int i=pos;i<=n;i++){
		q.push({a[i].w,i});ll nt=ti+1;
		if(binary_search(cnt+1,cnt+m+1,nt)){
			int pos=lower_bound(cnt+1,cnt+m+1,nt)-cnt;
			nt=cnt[nxt[pos]]+1;
		}
		if(nt>a[i].t) q.pop();
		else ti=nt;
	}
	while(!q.empty()){
		ans+=q.top().first;
		q.pop();
	}
	cout<<m<<" "<<ans;
	return 0;
}
