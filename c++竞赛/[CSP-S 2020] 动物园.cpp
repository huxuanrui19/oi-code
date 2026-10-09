#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e6+10,M=1e8+10;
int n,m,c;
ll k,a[N];
vector<int> g[N];
bool flag[N][70];
bool lis[M];
bool ju[70];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int p,q;
		cin>>p>>q;
		g[p+1].push_back(q);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k;j++){
			if(a[i]&(1ll<<(j-1))) flag[i][j]=1;
		}
	}
	for(ll i=1;i<=k;i++){
		int mark=0;
		for(ll j=1;j<=n;j++){
			if(flag[j][i]==1) mark=1;
		}
		if(mark==1){
			for(auto d:g[i]){
				lis[d]=1;
			}
		}
	}
	for(int i=0;i<=69;i++) ju[i]=1;
	for(ll i=1;i<=k;i++){
		int mark=0;
		for(auto d:g[i]){
			if(lis[d]==0) mark=1;
		}
		if(mark==1) ju[i]=0;
	}
	ll sum=0;
	for(ll i=1;i<=k;i++){
		if(ju[i]==1) sum++;
	}
	if(sum==64){
		if(n!=0) cout<<ll(-n);		//1<<64-1 先爆了ull，直接对1<<64自然溢出取模即可 
		else cout<<"18446744073709551616";		//1<<64 爆ull，直接预处理出答案 
	}
	else cout<<(1ull<<sum)-n;
	return 0;
}

