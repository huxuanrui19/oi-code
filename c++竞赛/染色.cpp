//注释系为学习笔记 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],sum[N],ind[N],w[N],flag[int(1e6+5)],dp[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(flag[a[i]]){
				if(a[i]==a[i-1]){
					ans+=a[i];
				}
				else{
					ind[i-1]=flag[a[i]]+1;		//建边 
					w[i-1]=a[i];		//边权 
				}
			}
			flag[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];			//继承 
			if(ind[i]){
				dp[i]=max(dp[i],dp[ind[i]-1]+w[i]);		//转移dp[i]=max(dp[i],dp[ind[i]-1]+w[i])
			}
		}
		cout<<ans+dp[n]<<endl;
		for(int i=1;i<=n;i++){
			flag[a[i]]=0;
			a[i]=0;
			ind[i]=0;
			w[i]=0;
			dp[i]=0;
		}
	}
	return 0;
}
// 参考https://www.luogu.com.cn/article/v9dkcs0y；
// 记得复习 
