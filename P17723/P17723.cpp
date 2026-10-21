#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=2e6+10,M=(1ull<<23);
const ull K=30;
ull n,a[N],pos[M],nxt[N],sec[M],lstpos[M];
inline bool cal(ull i,ull j){
	return (bool)((1ull<<j)&a[i]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;for(ull i=1;i<=n;i++) cin>>a[i];
	ull ans=0;
	for(ull j=0;j<K;j++){
		queue<ull> q;
		for(ull i=1;i<=n;i++){
			if(cal(i,j)) q.push(i);
			nxt[i]=0;
		}
		for(ull i=1;i<=n;i++){
			while(!q.empty()&&q.front()<i) q.pop();
			if(!q.empty()) ans+=(n-q.front()+1)*(1ull<<j);
			if(!q.empty()) nxt[i]=q.front();
			else nxt[i]=n+1;
		}
	}
	for(int j=0;j<=21;j++){
		bool flag=0;
		for(ull i=1;i<=n;i++){
			if(a[i]>=(1ull<<j)) continue;
			sec[lstpos[a[i]]]=i;
			lstpos[a[i]]=i;
		}
		for(ull l=1,r=1,maxpos=0;l<=n&&r<=n;){
			if(cal(r,j)){
				flag=0;
				while(l<r){
					if(a[l]<(1ull<<j)) pos[a[l]]=0;
					l++;
				}
				l++;r++;
				continue;
			}
			ull res=(1ull<<j);
			if(flag==0){
				maxpos=0;
				while(res&&cal(r,j)==0&&r<=n){
					if(pos[a[r]]||a[r]>=(1ull<<j)){
						r++;continue;
					}
					else pos[a[r]]=r,maxpos=max(maxpos,pos[a[r]]),res--;
					r++;
				}
				if(res==0){
					ans+=(1ull<<j)*(nxt[l]-maxpos);
					flag=1;
					l++;
				}
				else l=r=nxt[l]+1,flag=0;
			}
			else{
				if(a[l-1]<(1ull<<j)){
					if(sec[a[l-1]]&&sec[a[l-1]]<=r){
						pos[a[l-1]]=sec[a[l-1]];
						maxpos=max(maxpos,pos[a[l-1]]);
						ans+=(1ull<<j)*(nxt[l]-maxpos);
					}
					else{
						while(cal(r,j)&&a[r]!=a[l-1]&&r<=n) r++;
						if(cal(r,j)==1||r>n) r=l=r+1,flag=0;
						else{
							maxpos=max(maxpos,r);
							ans+=(1ull<<j)*(nxt[l]-maxpos);
						}
					}
					l++;
				}
			}
		}
		for(ull i=0;i<M;i++) sec[i]=lstpos[i]=0;
	}
	cout<<ans;
	return 0;
}