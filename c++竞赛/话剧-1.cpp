#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=2e6+10,M=25;
ll n,a[N],l[N],r[N],dp_max[N][25],LOG2[N];
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
void write(lll x){
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	st_max_init();
	lll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,lll(a[i])*(r[i]-l[i]-1)*st_max_query(l[i],r[i]));
	}
	write(ans); 
	return 0;
}

