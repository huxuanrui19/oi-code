#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
using ll=long long;
using ld=long double;
using pli=pair<ll,int>;
using pi=pair<int,int>;
template<typename A>
using vc=vector<A>;
inline int read()
{
	int s=0,w=1;char ch;
	while((ch=getchar())>'9'||ch<'0') if(ch=='-') w=-1;
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
inline ll lread()
{
	ll s=0,w=1;char ch;
	while((ch=getchar())>'9'||ch<'0') if(ch=='-') w=-1;
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const ll L=100000000000000ll;
vc<int>wr[1100005];
vc<ll>sr[1100005];
map<ll,int>id;
char s[100005];
int nx[100005];
int lt[100005];
ll p[13];
int n,m,c;
inline ll get(ll v)
{
	if(!id.count(v))
	{
		id[v]=c;
		wr[c].push_back(0);sr[c].push_back(0);
		c++;
	}
	return id[v];
}
int main()
{
	freopen("fingerprint.in","r",stdin);
	freopen("fingerprint.out","w",stdout);
	n=read(),m=read();scanf("%s",s+1),p[0]=1;get(0);
	for(int i=1;i<=12;i++) p[i]=p[i-1]*26;
	lt[0]=0;for(int i=1;i<=n;i++) lt[i]=s[i]=='a'?lt[i-1]:i;
	nx[n+1]=n+1;for(int i=n;i;i--) nx[i]=s[i]=='a'?nx[i+1]:i;

	for(int i=1;i<=n;i++)
	{
		ll now=0;
		for(int j=lt[i];j;j--)
		{
			now=now*26+s[j]-'a';
			if(now>L) break;
			int p=get(now);
			if(wr[p].back()!=i) wr[p].push_back(i),sr[p].push_back(0);
			sr[p].back()++;
		}
	}

	wr[0].clear(),sr[0].clear();
	wr[0].push_back(0),sr[0].push_back(0);

	for(int i=1;i<=n;i++) if(s[i]=='a')
		wr[0].push_back(i),sr[0].push_back(i-lt[i]);

	for(int i=0;i<=c;i++)
	{
		ll sum=0;
		for(unsigned j=0;j<wr[i].size();j++) sum+=sr[i][j],sr[i][j]=sum;
	}
	// int P=get(52728);
	// for(unsigned i=0;i<wr[P].size();i++) printf("(%d,%lld) ",wr[P][i],sr[P][i]);;putchar('\n');
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();ll k=lread();
		if(!id.count(k)){ printf("0\n");continue;}
		int p=get(k),w1,w2;
		w1=upper_bound(wr[p].begin(),wr[p].end(),r)-wr[p].begin()-1;
		w2=lower_bound(wr[p].begin(),wr[p].end(),l)-wr[p].begin()-1;
		ll ans=sr[p][w1]-sr[p][w2];
		// printf("ans=%lld\n",ans);

		if(!k) ans-=(ll)(l-1-lt[l-1])*(min(r+1,nx[l])-l);
		else
		{
			vc<int>w;int nod=lt[l-1];
			for(int j=l-1;j>0&&j>=l-10;j--) w.push_back(j);
			for(int j=nod;j>=nod-10&&j;j--) if(j<l-10) w.push_back(j);
			for(int p:w)
			{
				ll now=0;
				for(int q=p;q<=r;q++)
				{
					now=now+(s[q]-'a')*::p[q-p];
					if(now>k||q-p>11) break;
					if(now==k)
					{
						ans-=max(0,min(nx[q+1]-1,r)-max(q,l)+1);
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);

	}
	return 0;
}
