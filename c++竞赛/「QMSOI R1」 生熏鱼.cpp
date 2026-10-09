#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=30,K=2e7+10;
const int M=1e9,C=1e5+5;
const ll inf=1e18;
ll n,m,k,s,a[N],b[N],c[K],dp[C*N],vis[N],minn[C*N]; 
void read(){
    cin>>n>>m>>k>>s;
    mt19937 rand(s);
    for(int i=1;i<=n;i++)  a[i]=rand()%M+1,b[i]=rand()%C+1;
    for(int i=1;i<=k;i++)  c[i]=rand()%n+1;
}		//读入 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	read();

	dp[0]=0;minn[0]=inf;
	for(int i=1;i<C*N;i++){
		dp[i]=inf;
		minn[i]=inf;
	}		//初始化 
	ll sum=0,maxn=0;
	for(int i=1;i<=k;i++){
		sum+=a[c[i]];
		if(!vis[c[i]]){
			vis[c[i]]=1;
			for(ll j=C*n;j>=b[c[i]];j--){
				dp[j]=min(dp[j],dp[j-b[c[i]]]+a[c[i]]);
			}		//dp初始化(滚动数组要从后往前遍历)
			for(ll j=C*n;j>=0;j--){
				minn[j]=min(minn[j+1],dp[j]);
			}		//后缀最小值 
		}
		if(m<=0){
			if(1-m<C*n&&minn[1-m]!=inf){
				maxn=max(maxn,sum-minn[1-m]);		//救 
			}
			else break;			//救不动 
		}		//血量太少，需要救(To save or not to save,that's a question.) 
		else{
			maxn=max(maxn,sum);
		}		//不用回血 
		m-=b[c[i]];			//扣除血量 
	}
	cout<<maxn;			//输出 
	return 0;
}		//To be or not to be,that's a question.

