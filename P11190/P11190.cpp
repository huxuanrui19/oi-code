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
					int cnt=2;vector<int> ans[n];
					int l=0,r=0;
					for(int i=1;i<=n;i++){
						if(s[i]!=ch){
							l=i;break;
						}
					}
					for(int i=n;i>=1;i--){
						if(s[i]!=ch){
							r=i;break;
						}
					}
					ans[1].push_back(l);
					ans[2].push_back(r);
					for(int i=l+1;i<=n;i++){
						if(s[i]==ch) ans[1].push_back(i);
					}
					for(int i=1;i<l;i++){
						if(s[i]==ch) ans[2].push_back(i);
					}
					for(int i=l+1;i<r;i++){
						if(s[i]!=ch) ans[++cnt].push_back(i);
					}
					for(int i=1;i<=cnt;i++){
						if(ans[i].size()<2){
							if(ans[1].size()>2) ans[i].push_back(ans[1].back()),ans[1].pop_back();
							else ans[i].push_back(ans[2].back()),ans[2].pop_back();
						}
					}
					for(int i=1;i<=cnt;i++) sort(ans[i].begin(),ans[i].end());
					cout<<cnt<<"\n";
					for(int i=1;i<=cnt;i++){
						cout<<ans[i].size()<<" ";
						for(auto d:ans[i]) cout<<d<<" ";
						cout<<"\n";
					}
				}
			}
			else{
				vector<pii> v;
				for(int i=1;i<=n;i++) v.push_back({s[i],i});
				sort(v.begin(),v.end());
				cout<<(n/2)<<"\n";
				vector<int> ans[n];
				for(int i=1;i<=n/2;i++){
					ans[i].push_back(v[i-1].second);ans[i].push_back(v[i+n/2-1].second);
					if(ans[i][0]>ans[i][1]) swap(ans[i][0],ans[i][1]);
				}
				if(n%2==1){
					ans[1].push_back(v[n-1].second);
                    sort(ans[1].begin(),ans[1].end());
				}
				for(int i=1;i<=n/2;i++){
					cout<<ans[i].size()<<" ";
					for(auto d:ans[i]) cout<<d<<" ";
					cout<<"\n";
				}
			}
		}
	}
	return 0;
}