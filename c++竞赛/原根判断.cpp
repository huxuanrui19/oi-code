#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qp(ll k,ll n,ll INS)
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
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,p;
		cin>>a>>p;
		if(qp(a,p-1,p)!=1){
			cout<<"No"<<endl;
		}
		else{
			int flag=0;
			for(int i=2;i<=sqrt(p-1);i++){
				if((p-1)%i!=0) continue;
				if(qp(a,i,p)==1||qp(a,(p-1)/i,p)==1){
					cout<<"No"<<endl;
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
} 
