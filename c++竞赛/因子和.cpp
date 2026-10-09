#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1,a,b;
const ll INS=9901;
ll qp(ll k,ll n)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%INS;
		}
		k=k*k%INS;
		n>>=1;
	}
	return sum;
}
struct node{
	ll p,k;
}fj[100];
int len=0;
ll sum(ll p,ll k){
	if((p-1)%INS==0){
		return (k+1)%INS;
	}
	else{
		return (qp(p,k+1)-1+INS)%INS*qp(p-1,INS-2)%INS;
	}
}
int main(){
	cin>>a>>b;
	ll tmp=a;
	for(ll i=2;i*i<=a;i++){
		if(tmp%i==0){
			ll zs=0;
			while(tmp%i==0){
				tmp/=i;
				zs++;
			}
			zs*=b;
			fj[++len]=node{i,zs};
			if(tmp<=1) break;
		}
	}
	if(tmp!=1){
		fj[++len]=node{tmp,b};
	}
	for(int i=1;i<=len;i++){
		ans=ans*sum(fj[i].p,fj[i].k)%INS;
	}
	cout<<ans;
	return 0;
}

