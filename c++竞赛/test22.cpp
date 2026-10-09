#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll phi(ll x){
	ll ans=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans*(1-1.0/i);
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x>1) ans=ans*(1-1.0/x);
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=20;i++) cout<<phi(i)<<"\n";
	return 0;
}

