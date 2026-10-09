#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int isprime(int n){
	if(n==1) return -1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	} //i<=sqrt(n)
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;ll ans=0;
	for(int i=2;i<=n;i++){
		ans+=isprime(i);
	}
	cout<<ans;
	return 0;
}

