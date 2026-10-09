#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll l[N],r[N],b[N];
struct node{
	ll pos,type;
	bool operator < (const node &x)const{
		if(pos!=x.pos) return pos<x.pos;
	}
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	//freopen("cover.in","r",stdin);
	//freopen("cover.out","w",stdout);
	ll n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		a[++cnt]={l[i],1};
		a[++cnt]={r[i]+1,-1};
	}
	a[0]={0,0};
	sort(a+1,a+cnt+1);
	ll now=a[1].type;
	for(int i=2;i<=cnt;i++){
		b[now]+=a[i].pos-a[i-1].pos;
		now+=a[i].type;
	}
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

