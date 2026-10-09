#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,b,ans,res;
map<ll,bool> ma;		//记录，防止重复 
void solve(){
	for(ll i=2;i*i*i<=n;i++){
		ll tmp=i*i,m=2;
		while(tmp<=n/i){		//！！！！！小心10^18和10^6相乘爆long long 
			m++;
			tmp*=i;
			if(m<b) continue;		//指数不够 
			if(ma.count(tmp)) continue;			//重复访问 
			ll num=sqrtl(tmp);
			if(num*num==tmp) res++;		//统计a^2b类型的数 
			ans++;
			ma[tmp]=1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>b;
	solve();
	if(b==1) cout<<n;
	else if(b>=3) cout<<ans+1;			//考虑1 
	else cout<<ll(sqrtl(n))+ans-res;		//sqrtl(n)包括了1 
	return 0;
}
//记得用sqrtl()，主要是精度问题 
