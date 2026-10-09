#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int N=2e6+10;
ll n,a[N],pre[N],nxt[N],dp_max[N][25],LOG2[N];
void st_max_init(){
	LOG2[0]=-1; 
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;		//初始化log2 
	for(int i=1;i<=n;i++) dp_max[i][0]=a[i];		//初始化 
	int p=LOG2[n];
	for(int i=1;i<=p;i++){
		for(int s=1;s+(1<<i)<=n+1;s++){
			dp_max[s][i]=max(dp_max[s][i-1],dp_max[s+(1<<(i-1))][i-1]);
		}
	}		//dp推导 
}
int st_max_query(int l,int r){
	if(l<1) l=1;
	if(r>n) r=n;
	int k=LOG2[r-l+1];
	return max(dp_max[l][k],dp_max[r-(1<<k)+1][k]);			//查询 
}
ll read()
{
	ll x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	w=-w;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return w*x;
}

void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
void stack_min_build(){
	stack<ll> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]){
			st.pop();
		}
		pre[i]= (st.empty() ? 0:st.top());
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]){
			st.pop();
		}
		nxt[i]=(st.empty() ? n+1:st.top());
		st.push(i);
	}
}
ll cal(int i){
	return a[i]*(nxt[i]-pre[i]-1)*st_max_query(pre[i],nxt[i]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	stack_min_build();
	st_max_init();
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,cal(i));
	}
	write(ans);
	return 0;
}

