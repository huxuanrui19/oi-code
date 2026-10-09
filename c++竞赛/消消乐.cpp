#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5;
int kkk(ll ii,ll nn,ll kk){
	int a[10];
	for(int i=0;i<=9;i++){
		a[i]=0;
	}
	ll i=ii,k=kk,n=nn;
	while(i){
		a[i%10]++;
		i/=10;
	}
	while(n){
		a[n%10]++;
		n/=10;
	}
	while(k){
		a[k%10]--;
		k/=10;
	}
	for(int j=0;j<=9;j++){
		if(a[j]!=0) return 0;
	}
	i=ii,k=kk,n=nn;
	while(i>0&&k>0){
		if(i%10==k%10) i/=10;
		k/=10;
	}
	if(i!=0) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	int flag=0;
	for(ll i=1;i<=N;i++){
		ll k=n*i;
		if(kkk(n,i,k)){
			flag=1;
			cout<<i<<" "<<k<<endl;
		} 
	}
	if(!flag) cout<<"-1";
	return 0;
}
