#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,a,b;
bool isprime(int n){
	if(n==1) return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b-a!=2) cout<<"N\n";
		else{
			if(isprime(a)&&isprime(b)) cout<<"Y\n";
			else cout<<"N\n";
		}
	}
	return 0;
}

