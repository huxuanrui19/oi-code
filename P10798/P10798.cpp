#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=25;
int n,a[N],LOG2[N],st[N][M];
void build(){
	LOG2[0]=-1;for(int i=1;i<=n;i++) LOG2[i]=LOG2[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0]=abs(a[i]);
	for(int j=1;j<M;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	return;
}
inline int query(int l,int r){
	int p=LOG2[r-l+1];
	return max(st[l][p],st[r-(1<<p)+1][p]);
}
inline ll cal(ll x){
	return x*(x-1)/2;
}
unordered_map<int,pair<int,int> > mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build();ll ans=0;
	for(int i=1;i<=n;i++){
		if(!mp.count(abs(a[i]))){
			mp[abs(a[i])].first=1;
			mp[abs(a[i])].second=i;
		}
		else{
			ll mi=query(mp[abs(a[i])].second,i);
			if(mi>abs(a[i])){
				if(a[i]==0) ans+=cal(mp[abs(a[i])].first);
				else ans+=cal(mp[abs(a[i])].first/2)+cal(mp[abs(a[i])].first-mp[abs(a[i])].first/2);
				mp[abs(a[i])].first=1;mp[abs(a[i])].second=i;
			}
			else mp[abs(a[i])].first++;
		}
	}
	for(auto d:mp){
		auto dd=d.second;
		if(dd.first<=1) continue;
		if(a[dd.second]==0) ans+=cal(dd.first);
		else ans+=cal(dd.first/2)+cal(dd.first-dd.first/2);
	}
	cout<<ans;
	return 0;
}