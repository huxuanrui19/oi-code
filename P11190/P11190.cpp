#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int c,q,n;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>q;
	while(q--){
		cin>>n>>s;s=" "+s;
		int len=0;
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]){
				len=i-1;break;
			}
		}
		if(len==0||(len*2+1==n&&s.substr(1,len)==s.substr(n-len+1,len))) cout<<"Huoyu\n";
		else{
			cout<<"Shuiniao\n";
			map<char,ll> mp;
			for(int i=1;i<=n;i++) mp[s[i]]++;
			ll ans=0;
			for(auto d:mp){
				ans=max(ans,d.second);
			}
			if(ans>n/2);
		}
	}
	return 0;
}