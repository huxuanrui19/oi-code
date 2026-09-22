#include<bits/stdc++.h>
#define ll long long 
#define maxn 1000005
using namespace std;
int n;
ll a[maxn],l[maxn],r[maxn];
void init(int x)
{
	int cnt=-1,zd=-1;
	r[x]=a[x]-1;
	while (a[x])
	{
		if (a[x]&1) cnt++;
		a[x]=a[x]>>1; zd++;
	}
	l[x]=cnt+zd;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {cin>>a[i]; init(i);}
	ll now=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		if (now<l[i]) ans+=l[i]-now,now=l[i];
		if (now>r[i]) now=r[i];
	}
	cout<<ans<<endl;
}
