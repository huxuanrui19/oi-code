#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;
ll a[N],dp1[N][10],dp2[N][10],dp3[N][10];		//递增，递减，相同数位 
void init(){
	dp1[1][0]=dp2[1][0]=dp3[1][0]=1;
	for(int i=1;i<10;i++) dp1[1][i]=dp2[1][i]=dp3[1][i]=1;
	for(int i=2;i<N;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				if(j>=k) dp1[i][j]+=dp1[i-1][k];
				if(j<=k) dp2[i][j]+=dp2[i-1][k];
			}
		}
	}
}
ll solve2(ll x){
	if(!x) return 0;
	ll cnt=0;
	memset(a,0,sizeof(a));
	while(x) a[++cnt]=x%10,x/=10;
	ll res=0,last=0;
	for(int i=cnt;i>=1;i--){
		int now=a[i];
		for(int j=(i==cnt);j<now;j++){
			if(last<=j) res+=dp2[i][j];
		}
		if(last>now) break;
		last=now;
		if(i==1) res++;
	}
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=9;j++){
			res+=dp2[i][j];
		}
	}
	return res;
}
ll solve1(ll x){
	if(!x) return 0;
	ll cnt=0;
	memset(a,0,sizeof(a));
	while(x) a[++cnt]=x%10,x/=10;
	ll res=0,last=10;
	for(int i=cnt;i>=1;i--){
		int now=a[i];
		for(int j=(i==cnt);j<now;j++){
			if(last>=j) res+=dp1[i][j];
		}
		if(last<now) break;
		last=now;
		if(i==1) res++;
	}
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=9;j++){
			res+=dp1[i][j];
		}
	}
	return res;
}
ll solve3(ll x){
	if(!x) return 0;
	ll res=0;
	for(ll i=1;i<=9;i++){
		ll tmp=0;
		while(1){
			tmp=tmp*10+i;
			if(tmp<=x&&tmp>0) res++;
			else break;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		//cout<<solve1(n)<<" "<<solve2(n)<<" "<<solve3(n)<<"\n";
		cout<<(solve1(n)+solve2(n)-solve3(n))<<"\n";
	}
	return 0;
}

