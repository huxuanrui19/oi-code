#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,a[N];
vector<ll> v[64];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[1]>a[n]){
			cout<<"NO\n";
			continue;
		}
		ll res=0;
		for(int i=2;i<=n;i++){
			ll d=a[i]^a[i-1];
			if(d==0) continue;
			int h=63-__builtin_clzll(d);
			v[h].push_back(d);
			res++;
		}
		ll num=a[1],flag=1;
		while(res){
			bool found=0;
			for(ll i=0;i<64;i++){
				if(!v[i].empty()&&(num&(1ll<<i))==0){
					num^=v[i].back();v[i].pop_back();
					res--;found=1;break;
				}
			}
			if(!found){
				flag=0;break;
			}
		}
		if(num!=a[n]) flag=0;
		if(flag==0) cout<<"NO\n";
		else cout<<"YES\n";
		for(int i=0;i<=63;i++) v[i].clear();
	}
	return 0;
}
