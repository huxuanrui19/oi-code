#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],pos[N],l[N],r[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[i]=i;
		l[i]=i-1;
		r[i]=i+1;
	}
	sort(pos+1,pos+1+n,cmp);
	for(int i=1;i<=n;i++){
		int id=pos[i];
		int lp=id,llen=1;
		while(llen!=k&&l[lp]){
			lp=l[lp];
			llen++;
		}
		int rp=id,rlen=0;
		rp++;rp--;
		while(llen+rlen<k&&r[rp]!=n+1){
			rp=r[rp];
			rlen++;
		}
		if(llen+rlen==k){
			while(rp!=n+1){
				ll le=lp-l[lp];
				ll re=r[rp]-rp;
				ans+=le*re*a[id];
				if(lp==id) break;
				lp=r[lp];
				rp=r[rp];
			}
		}
		l[r[id]]=l[id];
		r[l[id]]=r[id];
	}
	cout<<ans;
	return 0;
}

