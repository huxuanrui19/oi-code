#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll cnt=0,f[N],pri[N],vis[N];
void init(){
	f[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			f[i]=f[i-1];
			vis[i]=1;
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<N;j++){
			vis[i*pri[j]]=1;
			f[i*pri[j]]=f[i]+f[pri[j]];
			if(i%pri[j]==0){
				break;
			}
		}
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>m;
		ll ans=0,flag=0;
		for(int i=1;i<=m;i++){
			ll p,q;
			cin>>p>>q;
			if(p==2){
				flag=1;
			}
			ans+=f[p]*q;
		}
		if(!flag){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
