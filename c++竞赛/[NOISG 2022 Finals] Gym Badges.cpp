#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
struct node{
	ll l,x;
	bool operator <(const node &tmp)const{
		return (l+x)<(tmp.l+tmp.x);
	}
}cnt[N];
int n,x[N],l[N];
ll ans,sum=0;
priority_queue<ll,vector<ll>,less<int> > q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=n;i++) cnt[i]=(node){l[i],x[i]};
	sort(cnt+1,cnt+n+1);
	for(int i=1;i<=n;i++){
		sum+=cnt[i].x;ans++;q.push(cnt[i].x);
		if(sum>cnt[i].l+cnt[i].x){
			sum-=q.top();q.pop();ans--;
		}
	}
	cout<<ans;
	return 0;
}

