#include<bits/stdc++.h>
#define ll long long 
#define maxn 200005
#define mod1 1000000007
#define mod2 998244353
using namespace std;
map<int,int> vis,id;
int a[maxn],tot,n,q,ok[maxn],fir[maxn];
ll bas[maxn],sum[maxn],ans[maxn];
int lb(int x) {return x&(-x);}
void add(int x,int v) {for (x;x<=n;x+=lb(x)) sum[x]+=v;}
ll get(int x) {ll ret=0; for (x;x>0;x-=lb(x)) ret+=sum[x]; return ret;}
int main()
{
	freopen("fold.in","r",stdin);
	freopen("fold.out","w",stdout);	
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {cin>>a[i]; vis[a[i]]=1;}
	for (auto tt:vis) id[tt.first]=++tot;
	for (int i=1;i<=n;i++) a[i]=id[a[i]];
	for (int i=1;i<=n;i++) if (ok[a[i]]==0) {ok[a[i]]=1; fir[i]=1;}
	for (int i=1;i<=n;i++)
	{
		bas[i]=get(a[i]-1)+1;
		if (fir[i]) add(a[i],1); 
	}
	memset(sum,0,sizeof(sum));
	for (int i=n;i>=1;i--)
	if (fir[i])
	{
		ans[a[i]]=bas[i]*(n-i+1)+get(a[i]-1);
		add(a[i],n-i+1);
	}
	int x;
	while (q--)
	{
		cin>>x; x=id[x];
		cout<<ans[x]<<" ";
	}
	cout<<endl;
}
