#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=2e6+10;
const ull K=30;
ull n,a[N],lstpos[N],cnt[N],tl[N];
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
		}
		for(ull i=1;i<=n;i++){
			while(!q.empty()&&q.front()<i) q.pop();
			if(!q.empty()) ans+=(n-q.front()+1)*(1ull<<j);
		}
	}
    for(ull j=0;(1ull<<j)<=n;j++){
        ull need=(1ull<<j);
        for(ull i=0;i<need;i++) lstpos[i]=0;
        memset(cnt,0,sizeof(cnt));
        ull st=1,res=need;
        ull minpos=1,tc=0,c=0;
        for(ull i=1;i<=n;i++){
            ull x=a[i];
            if(x>>j&1ull){
                for(ull j=0;j<tc;j++) lstpos[tl[j]]=0;
                tc=0,st=i+1;res=need,minpos=st;
                continue;
            }
            if(x<need){
                ull pos=lstpos[x];
                if(pos>=st) cnt[pos]--;
                else res--;
                lstpos[x]=i;cnt[i]++;tl[tc++]=x;
                if(res==0) while(cnt[minpos]==0) minpos++;
            }
            if(res==0) c+=minpos-st+1;
        }
        ans+=c*(1ull<<j);
    }
	cout<<ans;
	return 0;
}