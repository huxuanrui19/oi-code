#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2e6+10;
int n,a[N],fa[M];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<M;i++) fa[i]=i;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int f=find(a[i]);
		fa[f]=f+1;
		cout<<f<<" ";
	}
	return 0;
}

