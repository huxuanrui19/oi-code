#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll gcd(ll a,ll b){return ((b==0)?a:gcd(b,a%b));} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll a,b;cin>>a>>b;
	cout<<gcd(a,b)<<" "<<(a/gcd(a,b)*b);
	return 0;
}

