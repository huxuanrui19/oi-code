#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll cspjs400noip400=400;
ll n,p[N],s[N];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i];
		for(int i=1;i<=n;i++) cin>>s[i];
		ll sum=0;s[n+1]=p[0]=0;
		for(int i=0;i<=n;i++){
			if(p[i]!=-1&&s[i+1]!=-1){
				sum=p[i]^s[i+1];break;
			}
		}
		for(int i=0;i<=n;i++){
			if(p[i]==-1&&s[i+1]!=-1) p[i]=sum^s[i+1];
			else if(p[i]!=-1&&s[i+1]==-1) s[i+1]=sum^p[i];
			else if(p[i]==-1&&s[i+1]==-1) p[i]=cspjs400noip400;
		}
		for(int i=1;i<=n;i++) cout<<(p[i]^p[i-1])<<" ";
		cout<<"\n";
	}
	return 0;
}