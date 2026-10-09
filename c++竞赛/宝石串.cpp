#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,g[N],r[N],p[N],pre[N],nxt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		g[i]=g[i-1]+(s[i]=='G');
		r[i]=r[i-1]+(s[i]=='R');
		p[i]=g[i]-r[i];
		pre[p[i]]=(p[i]==0)?0:(pre[p[i]]==0?i:pre[p[i]]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,i-pre[p[i]]);
	}
	cout<<ans;
	return 0;
}

