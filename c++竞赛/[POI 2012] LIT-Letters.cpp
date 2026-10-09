#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,num=0,id[26][N],c[26],d[26],arr[N];
string a,b;
inline int lowbit(int x){
	return x&(-x);
}
int tree[N];
void update(int x){
	while(x<N){
		tree[x]++;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>a>>b;
	a=' '+a;
	b=' '+b;
	for(int i=1;i<=n;i++){
		id[a[i]-'A'][++c[a[i]-'A']]=i;
	}
	for(int i=1;i<=n;i++){
		arr[i]=id[b[i]-'A'][++d[b[i]-'A']];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=query(n)-query(arr[i]-1);
		update(arr[i]);
	}
	cout<<ans;
	return 0;
}

