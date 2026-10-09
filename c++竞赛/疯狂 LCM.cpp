#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll cnt=0,phi[N],pri[N],vis[N];
ll ans[N];
void init(){
	phi[0]=phi[1]=1;
	vis[0]=vis[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			phi[i]=i-1;
			pri[++cnt]=i;
			vis[i]=1;
		}
		for(int j=1;j<=cnt;j++){
			if(i*pri[j]>=N){
				break;
			}
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
	}
}
int main(){
	init();
	int t;
	cin>>t;
	for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            ans[j]+=phi[(j/i)]*(j/i)>>1;
	while(t--){
		int n;
		cin>>n;
		cout<<(ans[n]+1)*n<<endl;
	}
	return 0;
} 
