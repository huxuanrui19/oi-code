#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,k,c[N],a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	ll num=0;
	priority_queue<ll,vector<ll>,greater<ll> > q;
	for(int i=1;i<=n;i++){
		if(i<=k){
			q.push(a[i]);
			num+=a[i];
		}
		else{
			if(a[i]<q.top()) continue;
			else num=num-q.top()+a[i],q.pop(),q.push(a[i]);
		}
		b[i]=num;
	} 
	ll ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=c[i-1];
		ans=max(ans,min(b[i],m-sum));
	}
	cout<<ans;
	return 0;
}

