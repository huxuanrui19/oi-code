#include<bits/stdc++.h>
#define pii pair<int,int>
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
		if(len==0||(len*2+1==n&&s.substr(1,len)==s.substr(n-len+1,len))) cout<<"Shuiniao\n";
		else{
			cout<<"Huoyu\n";
			map<char,ll> mp;
			for(int i=1;i<=n;i++) mp[s[i]]++;
			ll ans=0;char ch;
			for(auto d:mp){
				if(ans<d.second) ch=d.first;
				ans=max(ans,d.second);
			}
			if(ans>n/2){
				int res=n-ans;
				if(res==1){
					cout<<"1\n"<<n<<" ";
					for(int i=1;i<=n;i++) cout<<i<<" ";
					cout<<"\n";
				}
				else{
					cout<<res<<"\n";
					vector<pii> v;
					queue<int>q;
					for(int i=1;i<=n;i++) if(s[i]==ch) q.push(i);
					q.push(q.front());q.pop();
					ll cnt=0;
					for(int i=1;i<=n;i++){
						if(s[i]==ch&cnt) v.push_back({cnt,i-cnt});
						else cnt++;
					}
					if(cnt) v.push_back({cnt,n+1-cnt});
				}
			}
			else{
				vector<pii> v;
				for(int i=1;i<=n;i++) v.push_back({s[i-1],i});
				sort(v.begin(),v.end());
				cout<<n/2<<"\n";
				for(int i=1,j=1;i<=n/2;i++){
					//
				}
			}
		}
	}
	return 0;
}