#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,a[N],dp_max[N][25],LOG2[N];
template < typename T >
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar(); 
	}
	x*=f;
}
void st_max_init(){
	LOG2[0]=-1; 
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;		//初始化log2 
	for(int i=1;i<=n;i++) read(a[i]);		//输入 
	for(int i=1;i<=n;i++) dp_max[i][0]=a[i];		//初始化 
	int p=log2(n);
	for(int i=1;i<=p;i++){
		for(int s=1;s+(1<<i)<=n+1;s++){
			dp_max[s][i]=max(dp_max[s][i-1],dp_max[s+(1<<(i-1))][i-1]);
		}
	}		//dp推导 
}
int st_max_query(int l,int r){
	int k=LOG2[r-l+1];
	return max(dp_max[l][k],dp_max[r-(1<<k)+1][k]);			//查询 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	read(n);read(m); 
	st_max_init();
	for(int i=1;i<=m;i++){
		int l,r;
		read(l);read(r);
		cout<<st_max_query(l,r)<<'\n';
	}
	return 0;
}
