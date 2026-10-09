#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,ans,a[N],b[N],c[N];
ll st[N][20][2],LOG2[N];
void build(){
	for(int i=1;i<=n;i++) st[i][0][0]=st[i][0][1]=a[i];
	LOG2[0]=-1;for(int i=1;i<=n;i++) LOG2[i]=LOG2[i>>1]+1;
	for(int j=1;j<20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j][0]=max(st[i][j-1][0],st[i+(1<<(j-1))][j-1][0]);
			st[i][j][1]=max(st[i][j-1][1],st[i+(1<<(j-1))][j-1][1]);
		}
	}
}
inline ll query(ll l,ll r,ll type){
	ll p=LOG2[r-l+1];
	return max(st[l][p][type],st[r-(1<<p)+1][p][type]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll len=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans+=(len+1)*len/2;
			len=0;
		}
		else len++;
	}
	ans+=(len+1)*len/2;int flag=0;
	for(int i=1;i<=n;i++) if(a[i]==0) flag=1;
	if(flag==0){
		cout<<0;return 0;
	}
	memset(b,0x3f,sizeof(b));
	for(ll i=1;i<=n;i++){
		b[a[i]]=min(b[a[i]],i);
		c[a[i]]=max(c[a[i]],i);
	}
	ll l=n+1,r=0,mex=-1;
	set<int> v;
	for(int i=1;i<N;i++){
		if(b[i]>n) continue;
		ll lp=l,rp=r;
		l=min(l,b[i-1]);r=max(r,c[i-1]);
		if(i==1){
			for(int k=l;k<=r;k++){
				v.insert(a[k]);
			}
			for(int k=0;k<N;k++){
				if(v.find(k)==v.end()){
					mex=k;break;
				}
			}
		}
		else{
			for(int k=lp-1;k>=l;k--) v.insert(a[k]);
			for(int k=rp+1;k<=r;k++) v.insert(a[k]);
			for(mex;mex<N;mex++){
				if(v.find(mex)!=v.end()) continue;
				else break;
			}
			if(mex==i) ans++;
		}
	}
	cout<<ans;
	return 0; 
}
