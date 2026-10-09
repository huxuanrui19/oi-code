#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+1][m+1],row[n+1],col[m+1];
    memset(a,0,sizeof(a));
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for(int i=1;i<=k;i++){
		char c;
		int pos;
		cin>>c>>pos;
		if(c=='R') row[pos]^=1;
		else col[pos]^=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=a[i][j]^row[i]^col[j];
		}
	}
	cout<<ans;
	return 0;
}

