#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a,b,ans=0;
ll check(ll k){
	if(b&(1<<k)==0) return 0;
	ll cnt=b-(1<<k);
	if(k>=1){
		for(int i=0;i<=k-1;i++){
			if((b&(1<<i))==0) cnt+=1<<i;
		}
	}
	if(cnt<a) return 0;
	int res=0;
	while(cnt){
		res+=cnt%2;
		cnt=cnt>>1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
    ll tmp=a;
    while(tmp){
        ans+=(tmp%2);
        tmp=tmp>>1;
    }
    tmp=b;
    ll cnt=0;
    while(tmp){
        cnt+=(tmp%2);
        tmp=tmp>>1;
    }
    ans=max(ans,cnt);
	for(int i=0;(1<<i)<=b;i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
}
