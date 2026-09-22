#include<bits/stdc++.h>
#define ll long long 
#define maxn 2005
#define mod 998244353
using namespace std;
#define lowbit(x) (x&(-x))
int n,m;
ll ans;
string s[maxn];
int L[maxn][maxn],R[maxn][maxn],D[maxn][maxn];
map<int,int> vis; 
ll sum1[maxn],sum2[maxn];
void modify(int x,ll v)
{
	ll tt=(x-1)*v;
	//给sum2[i]单点加v，给sum1[i]单点加(x-1)*v 
	for (int i=x;i<=m;i+=lowbit(i)) 
	{
		sum2[i]+=v;
		sum1[i]+=tt;
	}
}
ll get(ll *sum,ll x)
{
	ll ret=0;
	for (x;x>=1;x-=lowbit(x)) ret+=sum[x];
	return ret;
}
//处理第i行的所有元素 
void work(int i)
{
	//每个位置有两个参数：高度h，答案r，r<=h是必定的 
	//我每次插入的是r以及数量v 
	memset(sum1,0,sizeof(sum1)); memset(sum2,0,sizeof(sum2));
	vis.clear();
	for (int j=m;j>=1;j--)
	{
		int h=D[i][j];
		if (h<=1) //完犊子了 
		{
			for (auto tt:vis)
			{
				int r=tt.first,v=tt.second;
				modify(r,-v);
			}
			vis.clear();
//			cout<<i<<" "<<j<<" "<<0<<endl;
			continue;
		}
		//先来处理右边不合法的
		while (!vis.empty() && (*vis.rbegin()).first>h)
		{
			int r=(*vis.rbegin()).first,v=(*vis.rbegin()).second;
			modify(r,-v);
			modify(h,v);
			vis[h]+=v;
			vis.erase(r);
		}
		//现在里面都是合法的了
		ll r=L[i][j];
		ll tmp=0;
		if (r>=2)
		{
			tmp+=get(sum1,r);
			tmp+=(get(sum2,m)-get(sum2,r))*(r-1);
			//比你小的一概都要
			ans+=get(sum1,r); //sum数组里r以内的 
			ans+=(get(sum2,m)-get(sum2,r))*(r-1); //比r大的都按r算
		}
		//插入r,1
		r=R[i][j];
		modify(r,1);
		vis[r]++; 
//		cout<<i<<" "<<j<<" "<<tmp<<endl;
	}
	return;
}

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) {cin>>s[i];}
	for (int i=n;i>=1;i--)
	for (int j=1;j<=m;j++)
	if (s[i][j-1]=='.')
		L[i][j]=min(L[i+1][j],L[i][j-1])+1,
		D[i][j]=D[i+1][j]+1;
	for (int i=n;i>=1;i--)
	for (int j=m;j>=1;j--)
	if (s[i][j-1]=='.')
		R[i][j]=min(R[i+1][j],R[i][j+1])+1;	
}

int main()
{
	freopen("sail.in","r",stdin);
	freopen("sail.out","w",stdout);
	init();
	for (int i=1;i<=n;i++) work(i); 
	cout<<ans<<endl;
} 
