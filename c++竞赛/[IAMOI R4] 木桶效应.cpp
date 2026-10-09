#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,k,h,l=1e18+10,r,ans=0;
ll a[N],dif[N],res[N];
bool check(ll x){
	ll mm=m,kk=k;
	for(int i=1;i<=n;i++){
		if(x<=a[i]){
			dif[i]=res[i]=0;
			continue;
		}
		dif[i]=(x-a[i])/h;
		res[i]=(x-a[i])%h;
	}
	__int128 sum=0;
	for(int i=1;i<=n;i++) sum+=dif[i];
	if(sum>kk){
		sum-=kk;
		__int128 cnt=0;
		for(int i=1;i<=n;i++) cnt+=res[i];
		cnt+=sum*h;
		return cnt<=mm;
	}
	else{
		sum=k-sum;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(res[i]) v.push_back(res[i]);
		}
		sort(v.begin(),v.end());
		__int128 cnt=0;
		for(int i=0;i<v.size()-sum;i++){
			cnt+=v[i];
		}
		return cnt<=mm;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k>>h;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) l=min(l,a[i]);
	r=1e18;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
