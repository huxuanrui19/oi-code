#include<bits/stdc++.h>
#define ll long long 
#define maxn 200005
#define mod1 1000000007
#define mod2 998244353
using namespace std;
int n,q;
string s;
ll has1[maxn][26],has2[maxn][26];
ll mi1[maxn],mi2[maxn];
pair<ll,ll> a[26],b[26];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q; cin>>s; s="0"+s;
	mi1[0]=mi2[0]=1;
	for (int i=1;i<=n;i++) mi1[i]=mi1[i-1]*29%mod1,mi2[i]=mi2[i-1]*31%mod2;
	ll p1=1,p2=1;
	for (int i=1;i<=n;i++)
	{
		p1=p1*29%mod1; p2=p2*31%mod2;
		for (int j=0;j<26;j++) has1[i][j]=has1[i-1][j],has2[i][j]=has2[i-1][j];
		int id=s[i]-'a'+1; ll z1,z2;
		z1=p1%mod1; z2=p2%mod2;
		(has1[i][id-1]+=z1)%=mod1;
		(has2[i][id-1]+=z2)%=mod2;
	}
	int l1,l2,r1,r2;
	while (q--)
	{
		cin>>l1>>r1>>l2>>r2;
		if (l1>l2) {swap(l1,l2); swap(r1,r2);}
		for (int i=0;i<26;i++)
		{
			a[i].first=(has1[r1][i]-has1[l1-1][i]+mod1)%mod1;
			a[i].second=(has2[r1][i]-has2[l1-1][i]+mod2)%mod2;
			(a[i].first*=mi1[l2-l1])%=mod1;
			(a[i].second*=mi2[l2-l1])%=mod2;
			b[i].first=(has1[r2][i]-has1[l2-1][i]+mod1)%mod1;
			b[i].second=(has2[r2][i]-has2[l2-1][i]+mod2)%mod2;
		} 
		sort(a,a+26); sort(b,b+26);
		int flag=0;
		for (int i=0;i<26;i++) if(a[i]!=b[i]) flag=1;
		if (flag) cout<<"No\n"; else cout<<"Yes\n";
	}
}