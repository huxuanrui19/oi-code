#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int a,b,c;
}x[N];
int n;
ll val[105];
map<pair<int,int>,ll> mp1;
map<tuple<int,int,int>,ll> mp2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		val[x[i].a]++;
	}
	for(int i=1;i<105;i++){
		ans+=val[i]*(val[i]-1)/2;
		val[i]=0;
	}
	for(int i=1;i<=n;i++){
		val[x[i].b]++;
	}
	for(int i=1;i<105;i++){
		ans+=val[i]*(val[i]-1)/2;
		val[i]=0;
	}
	for(int i=1;i<=n;i++){
		val[x[i].c]++;
	}
	for(int i=1;i<105;i++){
		ans+=val[i]*(val[i]-1)/2;
		val[i]=0;
	}
	for(int i=1;i<=n;i++){
		mp1[{x[i].a,x[i].b}]++;
	}
	for(auto d:mp1){
		ans-=d.second*(d.second-1);
	}
	mp1.clear();
	for(int i=1;i<=n;i++){
		mp1[{x[i].a,x[i].c}]++;
	}
	for(auto d:mp1){
		ans-=d.second*(d.second-1);
	}
	mp1.clear();
	for(int i=1;i<=n;i++){
		mp1[{x[i].c,x[i].b}]++;
	}
	for(auto d:mp1){
		ans-=d.second*(d.second-1);
	}
	mp1.clear();
	for(int i=1;i<=n;i++){
		mp2[make_tuple(x[i].a,x[i].b,x[i].c)]++;
	}
	for(auto d:mp2){
		ans+=d.second*(d.second-1)/2*3;
	}
	cout<<ans;
	return 0;
}

